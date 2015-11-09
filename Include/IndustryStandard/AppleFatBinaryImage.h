#ifndef _APPLE_FAT_BINARY_IMAGE_H_
#define _APPLE_FAT_BINARY_IMAGE_H_

// FAT_BINARY_SIGNATURE
/// The common "Fat Binary Magic" number used to identify a Fat binary.
#define EFI_FAT_BINARY_SIGNATURE  0x0EF1FAB9

// MACHO_FAT_BINARY_MAGIC
/// The common "Fat Binary Magic" number used to identify a Fat binary.
#define MACHO_FAT_BINARY_SIGNATURE  0xCAFEBABE

// MACHO_FAT_BINARY_SIGNATURE
/// The common "Fat Binary Magic" number used to identify a Fat binary.
#define MACHO_FAT_BINARY_INVERT_SIGNATURE  SIGNATURE_32 (0xCA, 0xFE, 0xBA, 0xBE)

// FAT_ARCH
/// Defintion of the the Fat architecture-specific file header.
typedef struct _FAT_ARCH {
	CPU_TYPE    CpuType;     ///< The found CPU architecture specifier.
	CPU_SUBTYPE CpuSubtype;  ///< The found CPU sub-architecture specifier.
	UINT32      Offset;      ///< The offset of the architecture-specific boot file.
	UINT32      Size;        ///< The size of the architecture-specific boot file.
	UINT32      Alignment;   ///< The alignment as a power of 2 (necessary for the x86_64 architecture).
} FAT_ARCH;

// FAT_HEADER
/// Defintion of the Fat file header
typedef struct _FAT_HEADER {
	UINT32   Signature;  ///< The assumed "Fat Binary Magic" number found in the file.
	UINT32   NoFatArch;  ///< The hard-coded number of architectures within the file.
	FAT_ARCH FatArch;    ///< The first FAT_ARCH child of the FAT binary.
} FAT_HEADER;

#endif // ifndef _APPLE_FAT_BINARY_IMAGE_H_
