#ifndef _NDISSTRUCT_H_
#define _NDISSTRUCT_H_

#include "intro_types.h"
#include "introtypes.h"


////----------NOT ACTUAL STRUCTURES----------------------
//// Used as placeholders
//
//typedef uint8_t SLIST_HEADER [16]; //16 bytes for 64 bit systems
//
//
////--------------------------------------------------------------
//
//// TODO: PHYSICAL_ADDRESS, NET_BUFFER_DATA_LENGTH, SCATTER_GATHER_LIST
//
//
//#define MEMORY_ALLOCATION_ALIGNMENT 16
//
//typedef struct _MDL {
//  struct _MDL      *Next;
//  CSHORT           Size;
//  CSHORT           MdlFlags;
//  struct _EPROCESS *Process;
//  PVOID            MappedSystemVa;
//  PVOID            StartVa;
//  ULONG            ByteCount;
//  ULONG            ByteOffset;
//} MDL, *PMDL;
//
////--------Questionable -----------------
//// Physical Address, net buffer data length, scatter gather list & element
//
//typedef union {
//   struct {
//       ULONG LowPart;
//       LONG HighPart;
//   } u;
//   LONGLONG QuadPart;
//} PHYSICAL_ADDRESS;
//
//typedef struct _SCATTER_GATHER_ELEMENT {
//  PHYSICAL_ADDRESS  Address;
//  ULONG  Length;
//  PULONG  Reserved; //changed to PULONG from ULONG_PTR
//} SCATTER_GATHER_ELEMENT, *PSCATTER_GATHER_ELEMENT;
//
//typedef void NET_BUFFER_DATA_LENGTH(
//   PVOID _NB  //?? whats this
//);
//
//typedef struct _SCATTER_GATHER_LIST {
//  ULONG                  NumberOfElements;
//  PULONG              Reserved;  //changed to PULONG from ULONG_PTR
//  SCATTER_GATHER_ELEMENT Elements[];
//} SCATTER_GATHER_LIST, *PSCATTER_GATHER_LIST;
//
//
//
////-------------------------------------
//
//typedef 
//PVOID NDIS_HANDLE,
//*PNDIS_HANDLE;
//
//typedef int NDIS_STATUS, *PNDIS_STATUS;
//
//typedef struct _NET_BUFFER_LIST_CONTEXT
//{
//    PNET_BUFFER_LIST_CONTEXT    Next;
//    USHORT                      Size;
//    USHORT                      Offset;
//    //DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)     UCHAR      ContextData[];
//    UCHAR ContextData[];
//} NET_BUFFER_LIST_CONTEXT, *PNET_BUFFER_LIST_CONTEXT;
//
//typedef union _NET_BUFFER_LIST_HEADER {
//  NET_BUFFER_LIST_DATA NetBufferListData;
//  SLIST_HEADER         Link;
//} NET_BUFFER_LIST_HEADER, *PNET_BUFFER_LIST_HEADER;
//
//typedef struct _NET_BUFFER_LIST_DATA {
//  NET_BUFFER_LIST *Next;
//  NET_BUFFER      *FirstNetBuffer;
//} NET_BUFFER_LIST_DATA, *PNET_BUFFER_LIST_DATA;
//
//typedef struct _NET_BUFFER_LIST
//{
//    union
//    {
//        struct
//        {
//            PNET_BUFFER_LIST Next;           // Next NetBufferList in the chain
//            PNET_BUFFER FirstNetBuffer; // First NetBuffer on this NetBufferList
//        };
//
//        SLIST_HEADER Link;           // used in SLIST of free NetBuffers in the block
//
//        // Duplicate of the above, for source-compatibility
//        NET_BUFFER_LIST_HEADER NetBufferListHeader;
//    };
//
//    PNET_BUFFER_LIST_CONTEXT    Context;
//    PNET_BUFFER_LIST            ParentNetBufferList;
//    NDIS_HANDLE                 NdisPoolHandle;
//    //DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)PVOID NdisReserved[2];
//    //DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)PVOID ProtocolReserved[4];
//    //DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)PVOID MiniportReserved[2];
//    PVOID NdisReserved[2];
//    PVOID ProtocolReserved[4];
//    PVOID MiniportReserved[2];
//
//    PVOID                       Scratch;
//    NDIS_HANDLE                 SourceHandle;
//    ULONG                       NblFlags;   // public flags
//    LONG                        ChildRefCount;
//    ULONG                       Flags;      // private flags used by NDIs, protocols, miniport, etc.
//
//    union
//    {
//        NDIS_STATUS             Status;
//        ULONG                   NdisReserved2;
//    };
//
//    PVOID                       NetBufferListInfo[MaxNetBufferListInfo];
//} NET_BUFFER_LIST, *PNET_BUFFER_LIST;
//
//typedef union _NET_BUFFER_HEADER {
//  NET_BUFFER_DATA NetBufferData;
//  SLIST_HEADER    Link;
//} NET_BUFFER_HEADER, *PNET_BUFFER_HEADER;
//
//typedef struct _NET_BUFFER_DATA {
//  NET_BUFFER             *Next;
//  MDL                    *CurrentMdl;
//  ULONG                  CurrentMdlOffset;
//  NET_BUFFER_DATA_LENGTH NbDataLength;
//  MDL                    *MdlChain;
//  ULONG                  DataOffset;
//} NET_BUFFER_DATA, *PNET_BUFFER_DATA;
//
//typedef struct _NET_BUFFER_SHARED_MEMORY {
//  NET_BUFFER_SHARED_MEMORY *NextSharedMemorySegment;
//  ULONG                    SharedMemoryFlags;
//  NDIS_HANDLE              SharedMemoryHandle;
//  ULONG                    SharedMemoryOffset;
//  ULONG                    SharedMemoryLength;
//} NET_BUFFER_SHARED_MEMORY, *PNET_BUFFER_SHARED_MEMORY;
//
//typedef struct _NET_BUFFER {
//  union {
//    struct {
//      NET_BUFFER *Next;
//      MDL        *CurrentMdl;
//      ULONG      CurrentMdlOffset;
//      union {
//        ULONG  DataLength;
//        SIZE_T stDataLength;
//      };
//      MDL        *MdlChain;
//      ULONG      DataOffset;
//    };
//    SLIST_HEADER      Link;
//    NET_BUFFER_HEADER NetBufferHeader;
//  };
//  USHORT           ChecksumBias;
//  USHORT           Reserved;
//  NDIS_HANDLE      NdisPoolHandle;
//  PVOID            NdisReserved[2];
//  PVOID            ProtocolReserved[6];
//  PVOID            MiniportReserved[4];
//  PHYSICAL_ADDRESS DataPhysicalAddress;
//  union {
//    NET_BUFFER_SHARED_MEMORY *SharedMemoryInfo;
//    SCATTER_GATHER_LIST      *ScatterGatherList;
//  };
//} NET_BUFFER, *PNET_BUFFER;

// from https://github.com/ntdiff/headers/blob/ec39df2a0d463404b8da0facdc4bebd2e838e40f/Win10_21H1_20180/x64/System32/ndis.sys/Standalone/_NET_BUFFER_LIST.h

typedef union _SLIST_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long long Alignment;
      /* 0x0008 */ unsigned long long Region;
    }; /* size: 0x0010 */
    struct
    {
      struct /* bitfield */
      {
        /* 0x0000 */ unsigned long long Depth : 16; /* bit position: 0 */
        /* 0x0000 */ unsigned long long Sequence : 48; /* bit position: 16 */
      }; /* bitfield */
      struct /* bitfield */
      {
        /* 0x0008 */ unsigned long long Reserved : 4; /* bit position: 0 */
        /* 0x0008 */ unsigned long long NextEntry : 60; /* bit position: 4 */
      }; /* bitfield */
    } /* size: 0x0010 */ HeaderX64;
  }; /* size: 0x0010 */
} SLIST_HEADER, *PSLIST_HEADER; /* size: 0x0010 */

typedef struct _NET_BUFFER_LIST_DATA
{
  /* 0x0000 */ struct _NET_BUFFER_LIST* Next;
  /* 0x0008 */ struct _NET_BUFFER* FirstNetBuffer;
} NET_BUFFER_LIST_DATA, *PNET_BUFFER_LIST_DATA; /* size: 0x0010 */

typedef union _NET_BUFFER_LIST_HEADER
{
  union
  {
    /* 0x0000 */ struct _NET_BUFFER_LIST_DATA NetBufferListData;
    /* 0x0000 */ union _SLIST_HEADER Link;
  }; /* size: 0x0010 */
} NET_BUFFER_LIST_HEADER, *PNET_BUFFER_LIST_HEADER; /* size: 0x0010 */

typedef struct _NET_BUFFER_LIST
{
  union
  {
    struct
    {
      /* 0x0000 */ struct _NET_BUFFER_LIST* Next;
      /* 0x0008 */ struct _NET_BUFFER* FirstNetBuffer;
    }; /* size: 0x0010 */
    /* 0x0000 */ union _SLIST_HEADER Link;
    /* 0x0000 */ union _NET_BUFFER_LIST_HEADER NetBufferListHeader;
  }; /* size: 0x0010 */
  /* 0x0010 */ struct _NET_BUFFER_LIST_CONTEXT* Context;
  /* 0x0018 */ struct _NET_BUFFER_LIST* ParentNetBufferList;
  /* 0x0020 */ void* NdisPoolHandle;
  /* 0x0030 */ void* NdisReserved[2];
  /* 0x0040 */ void* ProtocolReserved[4];
  /* 0x0060 */ void* MiniportReserved[2];
  /* 0x0070 */ void* Scratch;
  /* 0x0078 */ void* SourceHandle;
  /* 0x0080 */ unsigned long NblFlags;
  /* 0x0084 */ long ChildRefCount;
  /* 0x0088 */ unsigned long Flags;
  union
  {
    /* 0x008c */ int Status;
    /* 0x008c */ unsigned long NdisReserved2;
  }; /* size: 0x0004 */
  /* 0x0090 */ void* NetBufferListInfo[29];
  /* 0x0178 */ long __PADDING__[2];
} NET_BUFFER_LIST, *PNET_BUFFER_LIST; /* size: 0x0180 */

#endif
