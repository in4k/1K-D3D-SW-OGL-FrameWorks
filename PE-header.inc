; ---------------------------------------------------------
; .COM dropper
; ---------------------------------------------------------
%ifdef DOS_STUB
				bits	16
				org	0x100
Dropper:
				call	Get_IP
Get_IP:				pop	bp
				mov	ah,03ch
				pop	cx
				lea	dx,[bp + (DropperFile - Get_IP)]
				int	21h				; Open
				xchg	ax,bx
				mov	ah,040h
				dec	cx				; 0-1=0xffff bytes to write
				int	21h				; Write
				mov	ah,03eh
				int	21h				; Close
				mov	ah,04ah
				mov	bl,080h
				int	21h				; Realloc
				mov	ax,04b00h			; Execute
				int	21h
				int	20h
				; Serve as filename and fileheader
DropperFile:			db	"MZ."
%else
DropperFile:			db	"MZ"
%endif

; ---------------------------------------------------------
; PE header
; ---------------------------------------------------------
				bits	32
_SubSystem 			equ	2
_Code_Base 			equ 	0x1000
_Size_Of_Image 			equ	(((_FCode - _IAT) + 0x1000) + 0x1000) & 0xfffff000
_Image_Base 			equ	0x400000
Tes:
%ifdef DOS_STUB
				times	58 - 1 db 0
%else
				times	58 db 0
%endif
				dd	(_PE_Header - DropperFile)
				times	160 db 0
_PE_Header:			db	"PE"
				db	0,0
				dw	0x14c					; 386
				dw	0x1					; Number of sections
				dd	0,0,0					; DateTime / Symbol table / number of symbols
				dw	(_FOptional_Header - _Optional_Header)	; Remaining bytes in NT header
				dw	0x0102					; Characteristics
_Optional_Header:		dw	0x010b					; 0x10b = PE32 0x20b = PE32+ (0x107 = ROM)
				db	0x0					; Linker version
				db	0x0					; Linker revision
				dd	0					; Size of code
				dd	0,0					; SizeOfInitializedData/SizeOfUninitializedData
				dd	(_EntryPoint - _IAT) + _Code_Base
				dd	0					; BaseOfCode
				dd	0					; BaseOfData (can also be used as PE offset at 0x3c (data:0x0c))
				dd	_Image_Base
				dd	0x1000					; SectionAlignment (in memory)
				dd	0x200					; FileAlignment
				dw	4,0					; MajorOperatingSystemVersion/MinorOperatingSystemVersion
				dw	0,0					; MajorImageVersion/MinorImageVersion
				dw	4,0					; MajorSubsystemVersion/MajorSubsystemVersion
				dd	0					; Reserved
				dd	_Size_Of_Image 
				dd	0x1000 ;(_IAT - DropperFile)			; Size of header
				dd	0					; CheckSum
				dw	_SubSystem
				dw	0					; DLL Characteristics
				dd	_Size_Of_Stack
				dd	_Size_Of_Stack				; SizeOfStackCommit
				dd	_Size_Of_Stack
				dd	_Size_Of_Stack				; SizeOfHeapCommit
				dd	0					; LoaderFlags (Obsolete)
				dd	16					; NumberOfRvaAndSizes (always 16)
				dd	0,0					; Export table
				dd	(_IID - _IAT) + _Code_Base		; Import table
				dd	(_FIID - _IID)				; NbrImports
				times	28 dd 0
_FOptional_Header:		times	8 db 0					; Section name
				dd	_Size_Of_Code
				dd	_Code_Base
				dd	_Size_Of_Code
				dd	0x200
				dd	0,0
				dw	0,0
				dd	0xe00000e0				; Characteristics
_IAT:
