; ---------------------------------------------------------
; 1k-OGL-Framework
; Written by Franck "hitchhikr" Charlet
; ---------------------------------------------------------
; Tiny OpenGL framework i created/used for my "1K-OPENGL-BOULDER"
; ---------------------------------------------------------

; buildblock RELEASE
; CAPT "c:\nasm\nasmw.exe" -f bin "%2" -o "%1.exe" -s -O9
; buildblockend

; ---------------------------------------------------------
; Headers
; ---------------------------------------------------------

; uncomment the following line to use the .com dropper
; (the com dropper is relocatable, allowing further optimisations in the depacking routine)
;%define DOS_STUB

_Size_Of_Stack 			equ	0x200000		; 2 megs of stack

				%include "PE-header.inc"
				%include "OpenGL.inc"

; ---------------------------------------------------------
; Constants
; ---------------------------------------------------------
SCREENX				equ	640
SCREENY				equ	480
SCREENDEPTH			equ	32

; kernel32.dll
GetTickCount			equ	0

; user32.dll
ChangeDisplaySettings		equ	0
CreateWindowEx			equ	1
GetDC				equ	2
GetAsyncKeyState		equ	3
ShowCursor			equ	4

; gui32.dll
ChoosePixelFormat		equ	0
SetPixelFormat			equ	1
SwapBuffers			equ	2

; opengl32.dll
glClear				equ	0
glEnable			equ	1
glMatrixMode			equ	2
glPopMatrix			equ	3
glPushMatrix			equ	4
wglCreateContext		equ	5
wglMakeCurrent			equ	6
glFrustum			equ	7

; ---------------------------------------------------------
; Datas
; ---------------------------------------------------------

MainHDC				equ	0
OldTime				equ	MainHDC + 4	
ElapsedTime			equ	OldTime + 4
PixFrm				equ	ElapsedTime + 4
VideoMode			equ	PixFrm + PIXELFORMATDESCRIPTOR_SIZE
Datas_Size			equ	VideoMode + DEVMODE_SIZE

; ---------------------------------------------------------
; main()
; ---------------------------------------------------------
_EntryPoint:			lea	ebp,[esp - (0x10000 + Datas_Size)]		; 64k of stack + room for user datas
				
				lea	esi,[ebp + VideoMode]
				mov	word [esi + DEVMODE.dmSize],DEVMODE_SIZE
				mov	dword [esi + DEVMODE.dmFields],DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT
				mov	dword [esi + DEVMODE.dmBitsPerPel],SCREENDEPTH
	
				; ---
				xor	eax,eax
				push	eax
				push	eax
				push	eax
				push	eax
				push	SCREENY
				push	SCREENX
				mov	dword [esi + DEVMODE.dmPelsWidth],SCREENX
				mov	dword [esi + DEVMODE.dmPelsHeight],SCREENY
				push	eax
				push	eax
	 			push	WS_VISIBLE | WS_POPUPWINDOW
				push	eax
				push	ClassName-_IAT+Var_Base
				push	WS_EX_TOPMOST
	
				; ---
				push	CDS_FULLSCREEN
				push	esi
				call	[(_IAT_User32-_IAT+Var_Base) + (4*ChangeDisplaySettings)]
				call	[(_IAT_User32-_IAT+Var_Base) + (4*CreateWindowEx)]
				push	eax
				call	[(_IAT_User32-_IAT+Var_Base) + (4*GetDC)]
				mov	[ebp + MainHDC],eax
				mov	edi,eax
	
				push	0
				call	[(_IAT_User32-_IAT+Var_Base) + (4*ShowCursor)]
				lea	esi,[ebp + PixFrm]
				mov	word [esi + PIXELFORMATDESCRIPTOR.nSize],PIXELFORMATDESCRIPTOR_SIZE
				mov	word [esi + PIXELFORMATDESCRIPTOR.nVersion],1
				mov	dword [esi + PIXELFORMATDESCRIPTOR.dwFlags],PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER
				mov	byte [esi + PIXELFORMATDESCRIPTOR.cColorBits],SCREENDEPTH
				mov	byte [esi + PIXELFORMATDESCRIPTOR.cDepthBits],SCREENDEPTH
				push	esi							; (this one for SetPixelFormat)
				push	esi
				push	edi
				call	[(_IAT_Gdi32-_IAT+Var_Base) + (4*ChoosePixelFormat)]
				push	eax
				push	edi
				call	[(_IAT_Gdi32-_IAT+Var_Base) + (4*SetPixelFormat)]
	
				push	edi
				call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*wglCreateContext)]
				push	eax
				push	edi
				call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*wglMakeCurrent)]
	
				; *****************************************************
				; *** Perform initializations here

				; *****************************************************
				; Set some static properties

				push	GL_PROJECTION
				call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*glMatrixMode)]
				; (Avoid gluPerspective)
				; fovY = 45.0
				; aspect = SCREENX / SCREENY
				; zNear = 0.1
				; zFar = 500.0
				push	0407f4000h		; zFar
				push	0
				push	03f847ae1h		; zNear
				push	040000000h
				; fH=tan(fovY / 180 * pi) * zNear / 2;
				mov	ebx,040000000h
				mov	eax,03f747ae1h
				push	eax			; fH
				push	ebx
				or	eax,080000000h
				push	eax			; -fH
				push	ebx
				; fW = fH * aspect
				mov	ebx,0b851eb80h
				mov	eax,03f7b4e81h
				push	eax			; fW
				push	ebx
				or	eax,080000000h
				push	eax			; -fW
				push	ebx
				call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*glFrustum)]

				; Switch matrix again
				push	GL_MODELVIEW
				call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*glMatrixMode)]
	
				; Turn some ogl features on eventually
				push	GL_DEPTH_TEST
				call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*glEnable)]
				;push	GL_LIGHTING
				;call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*glEnable)]
				;push	GL_LIGHT0
				;call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*glEnable)]

				; *****************************************************
				; Load the frame counter
				call	[(_IAT_Kernel32-_IAT+Var_Base) + (4*GetTickCount)]
				mov	[ebp + OldTime],eax

MainLoop:			push	dword [ebp + MainHDC]
				call	[(_IAT_Gdi32-_IAT+Var_Base) + (4*SwapBuffers)]
				; Clear the screen
				push	GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT
				call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*glClear)]

				; *****************************************************
				; Obtain frame counter
				call	[(_IAT_Kernel32-_IAT+Var_Base) + (4*GetTickCount)]
				mov	ebx,eax
				sub	ebx,[ebp + OldTime]
				push	ebx
				fild	dword [esp]
				pop	ebx
				mov	[ebp + OldTime],eax
				fdiv	dword [Flt1000-_IAT+Var_Base]
				fstp	dword [ebp + ElapsedTime]

				; *****************************************************
				; *** Draw your stuff here
	
			;	call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*glPushMatrix)]
			;	call	[(_IAT_OpenGL32-_IAT+Var_Base) + (4*glPopMatrix)]
	
				push	VK_ESCAPE
				call	[(_IAT_User32-_IAT+Var_Base) + (4*GetAsyncKeyState)]
				test	eax,eax
				jz	MainLoop
				ret

; ---------------------------------------------------------
; Datas
; ---------------------------------------------------------
Flt1000:			dd	1000.0

Var_Base 			equ	_Image_Base+_Code_Base

_IAT_Kernel32:			dd	(_GetTickCount-_IAT)+_Code_Base
				dd	0
_IAT_User32:			dd	(_ChangeDisplaySettingsA-_IAT)+_Code_Base
				dd	(_CreateWindowExA-_IAT)+_Code_Base
				dd	(_GetDC-_IAT)+_Code_Base
				dd	(_GetAsyncKeyState-_IAT)+_Code_Base
				dd	(_ShowCursor-_IAT)+_Code_Base
				dd	0
_IAT_Gdi32:			dd	(_ChoosePixelFormat-_IAT)+_Code_Base
				dd	(_SetPixelFormat-_IAT)+_Code_Base
				dd	(_SwapBuffers-_IAT)+_Code_Base
				dd	0
_IAT_OpenGL32:			dd	(_glClear-_IAT)+_Code_Base
				dd	(_glEnable-_IAT)+_Code_Base
				dd	(_glMatrixMode-_IAT)+_Code_Base
				dd	(_glPopMatrix-_IAT)+_Code_Base
				dd	(_glPushMatrix-_IAT)+_Code_Base
				dd	(_wglCreateContext-_IAT)+_Code_Base
				dd	(_wglMakeCurrent-_IAT)+_Code_Base
				dd	(_glFrustum-_IAT)+_Code_Base
_FIAT:

_IID:				dd	0,0,0
				dd	(_Kernel32Dll - _IAT) + _Code_Base
				dd	(_IAT_Kernel32 - _IAT) + _Code_Base
				dd	0,0,0
				dd	(_User32Dll - _IAT) + _Code_Base
				dd	(_IAT_User32 - _IAT) + _Code_Base
				dd	0,0,0
				dd	(_Gdi32Dll - _IAT) + _Code_Base
				dd	(_IAT_Gdi32 - _IAT) + _Code_Base
				dd	0,0,0
				dd	(_OpenGL32Dll - _IAT) + _Code_Base
				dd	(_IAT_OpenGL32 - _IAT) + _Code_Base
				times	5 dd 0
_FIID:

ClassName:			db	"EDIT"

				; kernel32.dll
_GetTickCount:			dw	0
				db	"GetTickCount"
				; user32.dll
_ChangeDisplaySettingsA:	dw	0
				db	"ChangeDisplaySettingsA"
_CreateWindowExA:		dw	0
				db	"CreateWindowExA"
_GetDC:				dw	0
				db	"GetDC"
_GetAsyncKeyState:		dw	0
				db	"GetAsyncKeyState"
_ShowCursor:			dw	0
				db	"ShowCursor"
				; gdi32.dll
_SwapBuffers:			dw	0
				db	"SwapBuffers"
_ChoosePixelFormat:		dw	0
				db	"ChoosePixelFormat"
_SetPixelFormat:		dw	0
				db	"SetPixelFormat"
				; opengl32.dll
_glClear:			dw	0
				db	"glClear"
_glEnable:			dw	0
				db	"glEnable"
_glMatrixMode:			dw	0
				db	"glMatrixMode"
_glPopMatrix:			dw	0
				db	"glPopMatrix"
_glPushMatrix:			dw	0
				db	"glPushMatrix"
_wglCreateContext:		dw	0
				db	"wglCreateContext"
_wglMakeCurrent:		dw	0
				db	"wglMakeCurrent"
_glFrustum:			dw	0
				db	"glFrustum",0

_Kernel32Dll: 			db	"kernel32.dll",0
_User32Dll:			db	"user32.dll",0
_Gdi32Dll:			db	"gdi32.dll",0
_OpenGL32Dll:			db	"opengl32.dll",0

_FCode:
_Size_Of_Code 			equ	(_FCode - _IAT)
