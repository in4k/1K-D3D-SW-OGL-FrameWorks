; Some equates for d3d (incomplete)

D3DFMT_A8R8G8B8			equ	21		; 32 bits
D3DFMT_X8R8G8B8			equ	22		; 24 bits
D3DFMT_R5G6B5			equ	23		; 16 bits
D3DFMT_X1R5G5B5			equ	24		; 15 bits
D3DFMT_P8			equ	41		; 8 bits

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
GMEM_FIXED			equ	0h
GMEM_ZEROINIT			equ	40h

; --- DX equates and structures
D3D_SDK_VERSION			equ	220
D3DSWAPEFFECT_DISCARD		equ	1
D3DSWAPEFFECT_FLIP		equ	2
D3DPRESENT_RATE_DEFAULT		equ	0
D3DFMT_D16			equ	80
D3DPRESENT_INTERVAL_IMMEDIATE   equ	0x80000000
D3DADAPTER_DEFAULT		equ	0
D3DDEVTYPE_HAL			equ	1
D3DCREATE_SOFTWARE_VERTEXPROCESSING	equ	0x00000020
D3DCLEAR_TARGET			equ	0x00000001
D3DCLEAR_ZBUFFER		equ	0x00000002
D3DCLEAR_STENCIL		equ	0x00000004
D3DFVF_XYZ			equ	0x002
D3DFVF_NORMAL           	equ	0x010
D3DFVF_PSIZE            	equ	0x020
D3DFVF_DIFFUSE          	equ	0x040
D3DFVF_SPECULAR         	equ	0x080
D3DFVF_TEXCOUNT_MASK    	equ	0xf00
D3DFVF_TEXCOUNT_SHIFT   	equ	8
D3DFVF_TEX0             	equ	0x000
D3DFVF_TEX1             	equ	0x100
D3DFVF_TEX2             	equ	0x200
D3DFVF_TEX3             	equ	0x300
D3DFVF_TEX4             	equ	0x400
D3DFVF_TEX5             	equ	0x500
D3DFVF_TEX6             	equ	0x600
D3DFVF_TEX7             	equ	0x700
D3DFVF_TEX8             	equ	0x800
D3DFVF_TEXTUREFORMAT2		equ	0
D3DFVF_TEXTUREFORMAT1		equ	3
D3DFVF_TEXTUREFORMAT3		equ	1
D3DFVF_TEXTUREFORMAT4 		equ	2
D3DUSAGE_WRITEONLY		equ	0x00000008
D3DFMT_INDEX16			equ	101
D3DFMT_INDEX32			equ	102
D3DPOOL_MANAGED			equ	1
D3DTS_VIEW			equ	2
D3DTS_PROJECTION		equ	3
D3DTS_TEXTURE0			equ	16
D3DTS_WORLD			equ	0 + 256
D3DPT_POINTLIST			equ	1
D3DPT_LINELIST			equ	2
D3DPT_LINESTRIP			equ	3
D3DPT_TRIANGLELIST		equ	4
D3DPT_TRIANGLESTRIP		equ	5
D3DPT_TRIANGLEFAN		equ	6
D3DLIGHT_POINT			equ	1
D3DLIGHT_SPOT			equ	2
D3DLIGHT_DIRECTIONAL		equ	3
D3DFILL_POINT			equ	1
D3DFILL_WIREFRAME		equ	2
D3DFILL_SOLID			equ	3
D3DCULL_NONE			equ	1
D3DCULL_CW			equ	2
D3DCULL_CCW			equ	3
D3DRS_ZENABLE			equ	7
D3DRS_FILLMODE			equ	8
D3DRS_SHADEMODE			equ	9
D3DRS_LINEPATTERN		equ	10
D3DRS_ZWRITEENABLE		equ	14
D3DRS_ALPHATESTENABLE		equ	15
D3DRS_LASTPIXEL			equ	16
D3DRS_SRCBLEND			equ	19
D3DRS_DESTBLEND			equ	20
D3DRS_CULLMODE			equ	22
D3DRS_ZFUNC			equ	23
D3DRS_ALPHAREF			equ	24
D3DRS_ALPHAFUNC			equ	25
D3DRS_DITHERENABLE		equ	26
D3DRS_ALPHABLENDENABLE		equ	27
D3DRS_FOGENABLE			equ	28
D3DRS_SPECULARENABLE		equ	29
D3DRS_ZVISIBLE			equ	30
D3DRS_FOGCOLOR			equ	34
D3DRS_FOGTABLEMODE		equ	35
D3DRS_FOGSTART			equ	36
D3DRS_FOGEND			equ	37
D3DRS_FOGDENSITY		equ	38
D3DRS_EDGEANTIALIAS		equ	40
D3DRS_ZBIAS			equ	47
D3DRS_RANGEFOGENABLE		equ	48
D3DRS_STENCILENABLE		equ	52
D3DRS_STENCILFAIL		equ	53
D3DRS_STENCILZFAIL		equ	54
D3DRS_STENCILPASS		equ	55
D3DRS_STENCILFUNC		equ	56
D3DRS_STENCILREF		equ	57
D3DRS_STENCILMASK		equ	58
D3DRS_STENCILWRITEMASK		equ	59
D3DRS_TEXTUREFACTOR		equ	60
D3DRS_WRAP0			equ	128
D3DRS_WRAP1			equ	129
D3DRS_WRAP2			equ	130
D3DRS_WRAP3			equ	131
D3DRS_WRAP4			equ	132
D3DRS_WRAP5			equ	133
D3DRS_WRAP6			equ	134
D3DRS_WRAP7			equ	135
D3DRS_CLIPPING			equ	136
D3DRS_LIGHTING			equ	137
D3DRS_AMBIENT			equ	139
D3DRS_FOGVERTEXMODE		equ	140
D3DRS_COLORVERTEX		equ	141
D3DRS_LOCALVIEWER		equ	142
D3DRS_NORMALIZENORMALS		equ	143
D3DRS_DIFFUSEMATERIALSOURCE	equ	145
D3DRS_SPECULARMATERIALSOURCE	equ	146
D3DRS_AMBIENTMATERIALSOURCE	equ	147
D3DRS_EMISSIVEMATERIALSOURCE	equ	148
D3DRS_VERTEXBLEND		equ	151
D3DRS_CLIPPLANEENABLE		equ	152
D3DRS_SOFTWAREVERTEXPROCESSING	equ	153
D3DRS_POINTSIZE			equ	154
D3DRS_POINTSIZE_MIN		equ	155
D3DRS_POINTSPRITEENABLE		equ	156
D3DRS_POINTSCALEENABLE		equ	157
D3DRS_POINTSCALE_A		equ	158
D3DRS_POINTSCALE_B		equ	159
D3DRS_POINTSCALE_C		equ	160
D3DRS_MULTISAMPLEANTIALIAS	equ	161
D3DRS_MULTISAMPLEMASK		equ	162
D3DRS_PATCHEDGESTYLE		equ	163
D3DRS_PATCHSEGMENTS		equ	164
D3DRS_DEBUGMONITORTOKEN		equ	165
D3DRS_POINTSIZE_MAX		equ	166
D3DRS_INDEXEDVERTEXBLENDENABLE	equ	167
D3DRS_COLORWRITEENABLE		equ	168
D3DRS_TWEENFACTOR		equ	170
D3DRS_BLENDOP			equ	171
D3DRS_POSITIONORDER		equ	172
D3DRS_NORMALORDER		equ	173
D3DFOG_NONE			equ	0
D3DFOG_EXP			equ	1
D3DFOG_EXP2			equ	2
D3DFOG_LINEAR			equ	3
D3DTOP_DISABLE			equ	1
D3DTOP_SELECTARG1		equ	2
D3DTOP_SELECTARG2		equ	3
D3DTOP_MODULATE			equ	4
D3DTOP_MODULATE2X		equ	5
D3DTOP_MODULATE4X		equ	6
D3DTOP_ADD			equ	7
D3DTOP_ADDSIGNED		equ	8
D3DTOP_ADDSIGNED2X		equ	9
D3DTOP_SUBTRACT			equ	10
D3DTOP_ADDSMOOTH		equ	11
D3DTOP_BLENDDIFFUSEALPHA	equ	12
D3DTOP_BLENDTEXTUREALPHA	equ	13
D3DTOP_BLENDFACTORALPHA		equ	14
D3DTOP_BLENDTEXTUREALPHAPM	equ	15
D3DTOP_BLENDCURRENTALPHA	equ	16
D3DTOP_PREMODULATE		equ	17
D3DTOP_MODULATEALPHA_ADDCOLOR	equ	18
D3DTOP_MODULATECOLOR_ADDALPHA	equ	19
D3DTOP_MODULATEINVALPHA_ADDCOLOR equ	20
D3DTOP_MODULATEINVCOLOR_ADDALPHA equ	21
D3DTOP_BUMPENVMAP		equ	22
D3DTOP_BUMPENVMAPLUMINANCE	equ	23
D3DTOP_DOTPRODUCT3		equ	24
D3DTOP_MULTIPLYADD		equ	25
D3DTOP_LERP			equ	26
D3DTSS_COLOROP			equ	1
D3DTSS_COLORARG1		equ	2
D3DTSS_COLORARG2		equ	3
D3DTSS_ALPHAOP			equ	4
D3DTSS_ALPHAARG1		equ	5
D3DTSS_ALPHAARG2		equ	6
D3DTSS_BUMPENVMAT00		equ	7
D3DTSS_BUMPENVMAT01		equ	8
D3DTSS_BUMPENVMAT10		equ	9
D3DTSS_BUMPENVMAT11		equ	10
D3DTSS_TEXCOORDINDEX		equ	11
D3DTSS_ADDRESSU			equ	13
D3DTSS_ADDRESSV			equ	14
D3DTSS_BORDERCOLOR		equ	15
D3DTSS_MAGFILTER		equ	16
D3DTSS_MINFILTER		equ	17
D3DTSS_MIPFILTER		equ	18
D3DTSS_MIPMAPLODBIAS		equ	19
D3DTSS_MAXMIPLEVEL		equ	20
D3DTSS_MAXANISOTROPY		equ	21
D3DTSS_BUMPENVLSCALE		equ	22
D3DTSS_BUMPENVLOFFSET		equ	23
D3DTSS_TEXTURETRANSFORMFLAGS	equ	24
D3DTSS_ADDRESSW			equ	25
D3DTSS_COLORARG0		equ	26
D3DTSS_ALPHAARG0		equ	27
D3DTSS_RESULTARG		equ	28
D3DTA_SELECTMASK		equ	0x0000000f
D3DTA_DIFFUSE			equ	0x00000000
D3DTA_CURRENT			equ	0x00000001
D3DTA_TEXTURE			equ	0x00000002
D3DTA_TFACTOR			equ	0x00000003
D3DTA_SPECULAR			equ	0x00000004
D3DTA_TEMP			equ	0x00000005
D3DTA_COMPLEMENT		equ	0x00000010
D3DTA_ALPHAREPLICATE		equ	0x00000020
D3DBLEND_ZERO			equ	1
D3DBLEND_ONE			equ	2
D3DBLEND_SRCCOLOR		equ	3
D3DBLEND_INVSRCCOLOR		equ	4
D3DBLEND_SRCALPHA		equ	5
D3DBLEND_INVSRCALPHA		equ	6
D3DBLEND_DESTALPHA		equ	7
D3DBLEND_INVDESTALPHA		equ	8
D3DBLEND_DESTCOLOR		equ	9
D3DBLEND_INVDESTCOLOR		equ	10
D3DBLEND_SRCALPHASAT		equ	11
D3DBLEND_BOTHSRCALPHA		equ	12
D3DBLEND_BOTHINVSRCALPHA	equ	13
D3DCMP_NEVER			equ	1
D3DCMP_LESS			equ	2
D3DCMP_EQUAL			equ	3
D3DCMP_LESSEQUAL		equ	4
D3DCMP_GREATER			equ	5
D3DCMP_NOTEQUAL			equ	6
D3DCMP_GREATEREQUAL		equ	7
D3DCMP_ALWAYS			equ	8
D3DBACKBUFFER_TYPE_MONO		equ	0
D3DLOCK_READONLY		equ	0x00000010
D3DLOCK_DISCARD			equ	0x00002000
D3DLOCK_NOOVERWRITE		equ	0x00001000
D3DLOCK_NOSYSLOCK		equ	0x00000800
D3DLOCK_NO_DIRTY_UPDATE		equ	0x00008000
D3DPRESENTFLAG_LOCKABLE_BACKBUFFER equ	0x00000001

D3DPRESENT_PARAMETERS_SIZE	equ	52
STRUC D3DPRESENT_PARAMETERS
.BackBufferWidth		RESD	1
.BackBufferHeight		RESD 	1
.BackBufferFormat		RESD	1
.BackBufferCount		RESD	1
.MultiSampleType		RESD	1
.SwapEffect			RESD	1
.hDeviceWindow			RESD	1
.Windowed			RESD	1
.EnableAutoDepthStencil		RESD	1
.AutoDepthStencilFormat		RESD	1
.Flags	    			RESD	1
; Following elements must be zero for Windowed mode
.FullScreen_RefreshRateInHz	RESD	1
.FullScreen_PresentationInterval RESD	1
ENDSTRUC

STRUC IDirect3D8
; IUnknown methods
.QueryInterface			RESD	1
.AddRef				RESD	1
.Release			RESD	1
; IDirect3D8 methods
.RegisterSoftwareDevice		RESD	1
.GetAdapterCount		RESD	1
.GetAdapterIdentifier		RESD	1
.GetAdapterModeCount		RESD	1
.EnumAdapterModes		RESD	1
.GetAdapterDisplayMode		RESD	1
.CheckDeviceType		RESD	1
.CheckDeviceFormat		RESD	1
.CheckDeviceMultiSampleType	RESD	1
.CheckDepthStencilMatch		RESD	1
.GetDeviceCaps			RESD	1
.GetAdapterMonitor		RESD	1
.CreateDevice			RESD	1
ENDSTRUC

STRUC IDirect3DDevice8
; IUnknown methods
.QueryInterface			RESD	1
.AddRef				RESD	1
.Release			RESD	1
; IDirect3DDevice8 methods
.TestCooperativeLevel		RESD	1
.GetAvailableTextureMem		RESD	1
.ResourceManagerDiscardBytes	RESD	1
.GetDirect3D			RESD	1
.GetDeviceCaps			RESD	1
.GetDisplayMode			RESD	1
.GetCreationParameters		RESD	1
.SetCursorProperties		RESD	1
.SetCursorPosition		RESD	1
.ShowCursor			RESD	1
.CreateAdditionalSwapChain	RESD	1
.Reset				RESD	1
.Present			RESD	1
.GetBackBuffer			RESD	1
.GetRasterStatus		RESD	1
.SetGammaRamp			RESD	1
.GetGammaRamp			RESD	1
.CreateTexture			RESD	1
.CreateVolumeTexture		RESD	1
.CreateCubeTexture		RESD	1
.CreateVertexBuffer		RESD	1
.CreateIndexBuffer		RESD	1
.CreateRenderTarget		RESD	1
.CreateDepthStencilSurface	RESD	1
.CreateImageSurface		RESD	1
.CopyRects			RESD	1
.UpdateTexture			RESD	1
.GetFrontBuffer			RESD	1
.SetRenderTarget		RESD	1
.GetRenderTarget		RESD	1
.GetDepthStencilSurface		RESD	1
.BeginScene			RESD	1
.EndScene			RESD	1
.Clear				RESD	1
.SetTransform			RESD	1
.GetTransform			RESD	1
.MultiplyTransform		RESD	1
.SetViewport			RESD	1
.GetViewport			RESD	1
.SetMaterial			RESD	1
.GetMaterial			RESD	1
.SetLight			RESD	1
.GetLight			RESD	1
.LightEnable			RESD	1
.GetLightEnable			RESD	1
.SetClipPlane			RESD	1
.GetClipPlane			RESD	1
.SetRenderState			RESD	1
.GetRenderState			RESD	1
.BeginStateBlock		RESD	1
.EndStateBlock			RESD	1
.ApplyStateBlock		RESD	1
.CaptureStateBlock		RESD	1
.DeleteStateBlock		RESD	1
.CreateStateBlock		RESD	1
.SetClipStatus			RESD	1
.GetClipStatus			RESD	1
.GetTexture			RESD	1
.SetTexture			RESD	1
.GetTextureStageState		RESD	1
.SetTextureStageState		RESD	1
.ValidateDevice			RESD	1
.GetInfo			RESD	1
.SetPaletteEntries		RESD	1
.GetPaletteEntries		RESD	1
.SetCurrentTexturePalette	RESD	1
.GetCurrentTexturePalette	RESD	1
.DrawPrimitive			RESD	1
.DrawIndexedPrimitive		RESD	1
.DrawPrimitiveUP		RESD	1
.DrawIndexedPrimitiveUP		RESD	1
.ProcessVertices		RESD	1
.CreateVertexShader		RESD	1
.SetVertexShader		RESD	1
.GetVertexShader		RESD	1
.DeleteVertexShader		RESD	1
.SetVertexShaderConstant	RESD	1
.GetVertexShaderConstant	RESD	1
.GetVertexShaderDeclaration	RESD	1
.GetVertexShaderFunction	RESD	1
.SetStreamSource		RESD	1
.GetStreamSource		RESD	1
.SetIndices			RESD	1
.GetIndices			RESD	1
.CreatePixelShader		RESD	1
.SetPixelShader			RESD	1
.GetPixelShader			RESD	1
.DeletePixelShader		RESD	1
.SetPixelShaderConstant		RESD	1
.GetPixelShaderConstant		RESD	1
.GetPixelShaderFunction		RESD	1
.DrawRectPatch			RESD	1
.DrawTriPatch			RESD	1
.DeletePatch			RESD	1
ENDSTRUC

MATRIX_SIZE			equ	(16*4)
STRUC MATRIX
._11				RESD	1
._12				RESD	1
._13				RESD	1
._14				RESD	1
._21				RESD	1
._22				RESD	1
._23				RESD	1
._24				RESD	1
._31				RESD	1
._32				RESD	1
._33				RESD	1
._34				RESD	1
._41				RESD	1
._42				RESD	1
._43				RESD	1
._44				RESD	1
ENDSTRUC

STRUC IDirect3DVertexBuffer8
; IUnknown methods
.QueryInterface			RESD	1
.AddRef				RESD	1
.Release			RESD	1
; IDirect3DResource8 methods
.GetDevice			RESD	1
.SetPrivateData			RESD	1
.GetPrivateData			RESD	1
.FreePrivateData		RESD	1
.SetPriority			RESD	1
.GetPriority			RESD	1
.PreLoad			RESD	1
.GetType			RESD	1
.Lock				RESD	1
.Unlock				RESD	1
.GetDesc			RESD	1
ENDSTRUC

STRUC IDirect3DIndexBuffer8
; IUnknown methods
.QueryInterface			RESD	1
.AddRef				RESD	1
.Release			RESD	1
; IDirect3DResource8 methods
.GetDevice			RESD	1
.SetPrivateData			RESD	1
.GetPrivateData			RESD	1
.FreePrivateData		RESD	1
.SetPriority			RESD	1
.GetPriority			RESD	1
.PreLoad			RESD	1
.GetType			RESD	1
.Lock				RESD	1
.Unlock				RESD	1
.GetDesc			RESD	1
ENDSTRUC

STRUC IDirect3DTexture8
; IUnknown methods
.QueryInterface			RESD	1
.AddRef				RESD	1
.Release			RESD	1
; IDirect3DBaseTexture8 methods
.GetDevice			RESD	1
.SetPrivateData			RESD	1
.GetPrivateData			RESD	1
.FreePrivateData		RESD	1
.SetPriority			RESD	1
.GetPriority			RESD	1
.PreLoad			RESD	1
.GetType			RESD	1
.SetLOD				RESD	1
.GetLOD				RESD	1
.GetLevelCount			RESD	1
.GetLevelDesc			RESD	1
.GetSurfaceLevel		RESD	1
.LockRect			RESD	1
.UnlockRect			RESD	1
.AddDirtyRect			RESD	1
ENDSTRUC

STRUC IDirect3DSurface8
; IUnknown methods
.QueryInterface			RESD	1
.AddRef				RESD	1
.Release			RESD	1
; IDirect3DSurface8 methods
.GetDevice			RESD	1
.SetPrivateData			RESD	1
.GetPrivateData			RESD	1
.FreePrivateData		RESD	1
.GetContainer			RESD	1
.GetDesc			RESD	1
.LockRect			RESD	1
.UnlockRect			RESD	1
ENDSTRUC

D3DCOLORVALUE_SIZE		equ	(4*4)
STRUC D3DCOLORVALUE
.r				RESD	1
.g				RESD	1
.b				RESD	1
.a				RESD	1
ENDSTRUC

D3DVECTOR_SIZE			equ	(3*4)
STRUC D3DVECTOR
.x				RESD	1
.y				RESD	1
.z				RESD	1
ENDSTRUC

D3DMATERIAL8_SIZE		equ	(17*4)
STRUC D3DMATERIAL8
.Diffuse.r			RESD	1
.Diffuse.g			RESD	1
.Diffuse.b			RESD	1
.Diffuse.a			RESD	1
.Ambient.r			RESD	1
.Ambient.g			RESD	1
.Ambient.b			RESD	1
.Ambient.a			RESD	1
.Specular.r			RESD	1
.Specular.g			RESD	1
.Specular.b			RESD	1
.Specular.a			RESD	1
.Emissive.r			RESD	1
.Emissive.g			RESD	1
.Emissive.b			RESD	1
.Emissive.a			RESD	1
Power				RESD	1
ENDSTRUC

D3DLIGHT8_SIZE			equ	(26*4)
STRUC D3DLIGHT8
.Type				RESD	1
.Diffuse.r			RESD	1
.Diffuse.g			RESD	1
.Diffuse.b			RESD	1
.Diffuse.a			RESD	1
.Specular.r			RESD	1
.Specular.g			RESD	1
.Specular.b			RESD	1
.Specular.a			RESD	1
.Ambient.r			RESD	1
.Ambient.g			RESD	1
.Ambient.b			RESD	1
.Ambient.a			RESD	1
.Position.x			RESD	1
.Position.y			RESD	1
.Position.z			RESD	1
.Direction.x			RESD	1
.Direction.y			RESD	1
.Direction.z			RESD	1
.Range				RESD	1
.Falloff			RESD	1
.Attenuation0			RESD	1
.Attenuation1			RESD	1
.Attenuation2			RESD	1
.Theta				RESD	1
.Phi				RESD	1
ENDSTRUC

D3DLOCKED_RECT_SIZE		equ	(2*4)
STRUC D3DLOCKED_RECT
.Pitch				RESD	1
.pBits				RESD	1
ENDSTRUC

TYPE_PLANEVERTEX		equ	D3DFVF_XYZ | D3DFVF_DIFFUSE
PLANEVERTEX_SIZE		equ	(6*4)
STRUC PLANEVERTEX
.px				RESD	1
.py				RESD	1
.pz				RESD	1
.diff				RESD	1
ENDSTRUC

; DSound
DSSCL_EXCLUSIVE			equ	3
DSBCAPS_PRIMARYBUFFER		equ	1
WAVE_FORMAT_PCM			equ	1
DSBCAPS_GLOBALFOCUS		equ	0x00008000
DSBCAPS_STICKYFOCUS		equ	0x00004000
DSBCAPS_CTRLPOSITIONNOTIFY	equ	0x00000100
DSBCAPS_GETCURRENTPOSITION2	equ	0x00010000
DSBPLAY_LOOPING			equ	0x00000001

STRUC IDirectSound8
; IUnknown methods
.QueryInterface			RESD	1
.AddRef				RESD	1
.Release			RESD	1
; IDirectSound methods
.CreateSoundBuffer		RESD	1
.GetCaps			RESD	1
.DuplicateSoundBuffer		RESD	1
.SetCooperativeLevel		RESD	1
.Compact			RESD	1
.GetSpeakerConfig		RESD	1
.SetSpeakerConfig		RESD	1
.Initialize			RESD	1
; IDirectSound8 methods
.VerifyCertification		RESD	1
ENDSTRUC

DSBUFFERDESC_SIZE		equ	(5 * 4)
STRUC DSBUFFERDESC
.dwSize				RESD	1
.dwFlags			RESD	1
.dwBufferBytes			RESD	1
.dwReserved			RESD	1
.lpwfxFormat			RESD	1
;GUID            guid3DAlgorithm;
ENDSTRUC

WAVEFORMATEX_SIZE		equ	18
STRUC WAVEFORMATEX
.wFormatTag			RESW	1 ; format type
.nChannels			RESW	1 ; number of channels (i.e. mono, stereo...)
.nSamplesPerSec			RESD	1 ; sample rate
.nAvgBytesPerSec		RESD	1 ; for buffer estimation
.nBlockAlign			RESW	1 ; block size of data
.wBitsPerSample			RESW	1 ; Number of bits per sample of mono data
.cbSize				RESW	1 ; The count in bytes of the size of extra information (after cbSize)
ENDSTRUC

DSBPOSITIONNOTIFY_SIZE		equ	(2 * 4)
STRUC DSBPOSITIONNOTIFY
.dwOffset			RESD	1
.hEventNotify			RESD	1
ENDSTRUC

STRUC IDirectSoundBuffer
;IUnknown methods
.QueryInterface			RESD	1
.AddRef				RESD	1
.Release			RESD	1
;IDirectSoundBuffer methods
.GetCaps			RESD	1		;12
.GetCurrentPosition		RESD	1		;16
.GetFormat			RESD	1		;20
.GetVolume			RESD	1		;24
.GetPan				RESD	1		;28
.GetFrequency			RESD	1		;32
.GetStatus			RESD	1		;36
.Initialize			RESD	1		;40
.Lock				RESD	1		;44
.Play				RESD	1		;48
.SetCurrentPosition		RESD	1
.SetFormat			RESD	1
.SetVolume			RESD	1
.SetPan				RESD	1
.SetFrequency			RESD	1
.Stop				RESD	1
.Unlock				RESD	1
.Restore			RESD	1
ENDSTRUC

STRUC IDirectSoundNotify
; IUnknown methods
.QueryInterface			RESD	1
.AddRef				RESD	1
.Release			RESD	1
; IDirectSoundNotify methods
.SetNotificationPositions	RESD	1
ENDSTRUC
