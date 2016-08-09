; ---------------------------------------------------------
; 1k-SW-Framework
; Written by Franck "hitchhikr" Charlet
; ---------------------------------------------------------
; Tiny Software rendering framework i created/used for my "1K-SW-RAYTRACE'EM ALL"
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
				%include "DX8.inc"

; ---------------------------------------------------------
; Constants
; ---------------------------------------------------------
SCREENX				equ	640
SCREENY				equ	480
SCREENDEPTH			equ	D3DFMT_A8R8G8B8		; 32 bits

; kernel32.dll
GetTickCount			equ	0

; d3d8.dll
Direct3DCreate8			equ	0

; user32.dll
CreateWindowEx			equ	0
GetAsyncKeyState		equ	1
ShowCursor			equ	2

; ---------------------------------------------------------
; Datas
; ---------------------------------------------------------

Screen				equ	0
ScreenSurface			equ	Screen + 4
OldTime				equ	ScreenSurface + 4
ElapsedTime			equ	OldTime + 4
PresentBuffer			equ	ElapsedTime + 4
SurfaceRect			equ	PresentBuffer + D3DPRESENT_PARAMETERS_SIZE
_Backuffer			equ	SurfaceRect + D3DLOCKED_RECT_SIZE
Datas_Size			equ	_Backuffer + (SCREENX * SCREENY * 4)

; ---------------------------------------------------------
; main()
; ---------------------------------------------------------
_EntryPoint:			lea	ebp,[esp - (0x10000 + Datas_Size)]		; 64k of stack + room for user datas

				lea	esi,[ebp + PresentBuffer]
				lea	eax,[ebp + ScreenSurface]
				push	eax
				xor	eax,eax
				push	eax
				push	eax
				push	D3D_SDK_VERSION
				push	eax
				push	eax
				push	eax
				push	eax
				push	eax
				push	eax
				push	eax
				push	eax
				push	eax
	 			push	WS_POPUPWINDOW
				push	eax
				push	ClassName-_IAT+Var_Base
				push	eax
				mov	dword [esi+D3DPRESENT_PARAMETERS.BackBufferWidth],SCREENX
				mov	dword [esi+D3DPRESENT_PARAMETERS.BackBufferHeight],SCREENY
				mov	dword [esi+D3DPRESENT_PARAMETERS.SwapEffect],D3DSWAPEFFECT_FLIP
				mov	dword [esi+D3DPRESENT_PARAMETERS.BackBufferFormat],SCREENDEPTH
				mov	dword [esi+D3DPRESENT_PARAMETERS.Flags],D3DPRESENTFLAG_LOCKABLE_BACKBUFFER
				call	[(_IAT_User32-_IAT+Var_Base) + (4*CreateWindowEx)]
				mov	edi,eax
				call	[(_IAT_User32-_IAT+Var_Base) + (4*ShowCursor)]
				call	[(_IAT_D3d8-_IAT+Var_Base) + (4*Direct3DCreate8)]

				push	ebp
				push	esi
				push	D3DCREATE_SOFTWARE_VERTEXPROCESSING
				push	edi
				push	D3DDEVTYPE_HAL
				push	0						; D3DADAPTER_DEFAULT
				push	eax
				mov	ebx,[eax]
				call	[ebx + IDirect3D8.CreateDevice]

				; *****************************************************
				; Load the frame counter
				call	[(_IAT_Kernel32-_IAT+Var_Base) + (4*GetTickCount)]
				mov	[ebp + OldTime],eax

				mov	eax,[ebp]
				push	eax
				mov	eax,[eax]
				call	[eax + IDirect3DDevice8.GetBackBuffer]

; ---------------------------------------------------------
; Loop
; ---------------------------------------------------------
MainLoop:			push	eax
				push	eax
				push	eax
				push	eax
				push	eax
				push	eax
				lea	eax,[ebp + SurfaceRect]
				push	eax
				mov	eax,[ebp + ScreenSurface]
				push	eax
				mov	eax,[eax]
				call	[eax + IDirect3DSurface8.LockRect]
			
				; *****************************************************
				; Obtain frame counter
				call	[(_IAT_Kernel32-_IAT+Var_Base) + (4*GetTickCount)]
				mov	ebx,eax
				sub	ebx,[ebp + OldTime]
				push	ebx
				fild	dword [esp]
				pop	ebx
				mov	[ebp + OldTime],eax
				; (1000.0 value is re-used here)
				fdiv	dword [Flt1000-_IAT+Var_Base]
				fstp	dword [ebp + ElapsedTime]

				; *************************
				; * Draw here *
				; using [ebp + SurfaceRect+D3DLOCKED_RECT.pBits]
				; [ebp + SurfaceRect+D3DLOCKED_RECT.Pitch]
				; note: it's faster to draw your stuff in _Backuffer and to copy it on the pBits right before UnlockRect

				; Just clear the screen
				mov	edx,[ebp + SurfaceRect+D3DLOCKED_RECT.pBits]
				xor	eax,eax
				mov	ebx,SCREENY
ClearScreenY:			mov	edi,edx
				mov	ecx,SCREENX
				rep	stosd
				add	edx,[ebp + SurfaceRect+D3DLOCKED_RECT.Pitch]
				dec	ebx
				jnz	ClearScreenY
				
				; *************************
				mov	eax,[ebp + ScreenSurface]
				push	eax
				mov	eax,[eax]
				call	[eax + IDirect3DSurface8.UnlockRect]
				mov	eax,[ebp]
				push	eax
				mov	eax,[eax]
				call	[eax + IDirect3DDevice8.Present]
			
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
_IAT_D3d8:			dd	(_Direct3DCreate8-_IAT)+_Code_Base
				dd	0
_IAT_User32:			dd	(_CreateWindowExA-_IAT)+_Code_Base
				dd	(_GetAsyncKeyState-_IAT)+_Code_Base
				dd	(_ShowCursor-_IAT)+_Code_Base
_FIAT:

_IID:				dd	0,0,0
				dd	(_Kernel32Dll - _IAT) + _Code_Base
				dd	(_IAT_Kernel32 - _IAT) + _Code_Base
				dd	0,0,0
				dd	(_D3d8Dll - _IAT) + _Code_Base
				dd	(_IAT_D3d8 - _IAT) + _Code_Base
				dd	0,0,0
				dd	(_User32Dll - _IAT) + _Code_Base
				dd	(_IAT_User32 - _IAT) + _Code_Base
				times	5 dd 0
_FIID:
ClassName:			db	"EDIT"

				; kernel32.dll
_GetTickCount:			dw	0
				db	"GetTickCount"
				; d3d8.dll
_Direct3DCreate8:		dw	0
				db	"Direct3DCreate8"
				; user32.dll
_GetAsyncKeyState:		dw	0
				db	"GetAsyncKeyState"
_ShowCursor:			dw	0
				db	"ShowCursor"
_CreateWindowExA:		dw	0
				db	"CreateWindowExA",0

_Kernel32Dll: 			db	"kernel32.dll",0
_User32Dll:			db	"user32.dll",0
_D3d8Dll:			db	"d3d8.dll",0

_FCode:

_Size_Of_Code 			equ	(_FCode - _IAT)
