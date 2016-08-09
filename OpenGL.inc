; Some equates for opengl (incomplete)

PFD_DOUBLEBUFFER		equ	1
PFD_DRAW_TO_WINDOW		equ	4
PFD_SUPPORT_OPENGL		equ	020h
GL_COMPILE			equ	01300h
GL_DIFFUSE			equ	01201h
GL_FRONT			equ	00404h
GL_LIGHT_MODEL_COLOR_CONTROL_EXT equ	081f8h
GL_SEPARATE_SPECULAR_COLOR_EXT	equ	081fah
GL_DEPTH_TEST			equ	00b71h
GL_LIGHTING			equ	00b50h
GL_CULL_FACE			equ	00b44h
GL_FOG				equ	00b60h
GL_EXP				equ	00800h
GL_FOG_MODE			equ	00b65h
GL_FOG_DENSITY			equ	00b62h
GL_LIGHT0			equ	04000h
GL_POSITION			equ	01203h
GL_FRONT_AND_BACK		equ	00408h
GL_AMBIENT			equ	01200h
GL_SPECULAR			equ	01202h
GL_SHININESS			equ	01601h
GL_PROJECTION			equ	01701h
GL_COLOR_BUFFER_BIT		equ	000004000h
GL_DEPTH_BUFFER_BIT		equ	000000100h
GL_MODELVIEW			equ	01700h
DM_BITSPERPEL			equ	040000h
DM_PELSWIDTH			equ	080000h
DM_PELSHEIGHT			equ	0100000h
WM_KEYDOWN			equ	100h
VK_ESCAPE			equ	01bh
WS_VISIBLE			equ	010000000h
WS_POPUP			equ	080000000h
WS_BORDER			equ	0800000h
WS_SYSMENU			equ	080000h
WS_POPUPWINDOW			equ	WS_POPUP
WS_EX_TOPMOST			equ	08h
WS_CHILD                	equ	040000000h
WS_CAPTION			equ	0C00000h
WS_MAXIMIZEBOX			equ	010000h
WS_MINIMIZEBOX			equ	020000h
WS_THICKFRAME			equ	040000h
ES_READONLY			equ	0800h
CS_HREDRAW			equ	02h
CS_VREDRAW			equ	01h
CDS_FULLSCREEN			equ	4
PM_REMOVE			equ	01h
CCHDEVICENAME			equ	32
CCHFORMNAME			equ	32

PIXELFORMATDESCRIPTOR_SIZE	equ	40
STRUC PIXELFORMATDESCRIPTOR
.nSize				RESW	1
.nVersion			RESW	1
.dwFlags			RESD	1
.iPixelType			RESB	1
.cColorBits			RESB	1
.cRedBits			RESB	1
.cRedShift			RESB	1
.cGreenBits			RESB	1
.cGreenShift			RESB	1
.cBlueBits			RESB	1
.cBlueShift			RESB	1
.cAlphaBits			RESB	1
.cAlphaShift			RESB	1
.cAccumBits			RESB	1
.cAccumRedBits			RESB	1
.cAccumGreenBits		RESB	1
.cAccumBlueBits			RESB	1
.cAccumAlphaBits		RESB	1
.cDepthBits			RESB	1
.cStencilBits			RESB	1
.cAuxBuffers			RESB	1
.iLayerType			RESB	1
.bReserved			RESB	1
.dwLayerMask			RESD	1
.dwVisibleMask			RESD	1
.dwDamageMask			RESD	1
ENDSTRUC

DEVMODE_SIZE			equ	124
STRUC DEVMODE
.dmDeviceName			RESB	CCHDEVICENAME
.dmSpecVersion			RESW	1
.dmDriverVersion		RESW	1
.dmSize				RESW	1
.dmDriverExtra			RESW	1
.dmFields			RESD	1
.dmPosition.x			RESD	1
.dmPosition.y			RESD	1
.dmScale			RESW	1
.dmCopies			RESW	1
.dmDefaultSource		RESW	1
.dmPrintQuality			RESW	1
.dmColor			RESW	1
.dmDuplex			RESW	1
.dmYResolution			RESW	1
.dmTTOption			RESW	1
.dmCollate			RESW	1
.dmFormName			RESB	CCHFORMNAME
.dmLogPixels			RESW	1
.dmBitsPerPel			RESD	1
.dmPelsWidth			RESD	1
.dmPelsHeight			RESD	1
.dmDisplayFlags			RESD	1
.dmDisplayFrequency		RESD	1
;#if(WINVER >= 0x0400) 
;  .dmICMMethod			RESD	1
;  .dmICMIntent			RESD	1
;  .dmMediaType			RESD	1
;  .dmDitherType		RESD	1
;  .dmReserved1			RESD	1
;  .dmReserved2			RESD	1
;#if (WINVER >= 0x0500) || (_WIN32_WINNT >= 0x0400)
;  .dmPanningWidth		RESD	1
;  .dmPanningHeight		RESD	1
;#endif
;#endif /* WINVER >= 0x0400 */
ENDSTRUC
