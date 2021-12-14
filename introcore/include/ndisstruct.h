#ifndef _NDISSTRUCT_H_
#define _NDISSTRUCT_H_

#include "introtypes.h"
#include "intro_types.h"

//----------NOT ACTUAL STRUCTURES----------------------
// Used as placeholders

typedef uint8_t SLIST_HEADER [16]; //16 bytes for 64 bit systems


//--------------------------------------------------------------

// TODO: PHYSICAL_ADDRESS, NET_BUFFER_DATA_LENGTH, SCATTER_GATHER_LIST


#define MEMORY_ALLOCATION_ALIGNMENT 16

//--------Questionable -----------------
typedef union {
   struct {
       ULONG LowPart;
       LONG HighPart;
   } u;
   LONGLONG QuadPart;
} PHYSICAL_ADDRESS;

typedef void NET_BUFFER_DATA_LENGTH(
   _NB
);

//-------------------------------------

typedef 
PVOID NDIS_HANDLE,
*PNDIS_HANDLE;

typedef int NDIS_STATUS, *PNDIS_STATUS;

typedef struct _NET_BUFFER_LIST_CONTEXT
{
    PNET_BUFFER_LIST_CONTEXT    Next;
    USHORT                      Size;
    USHORT                      Offset;
    DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)     UCHAR      ContextData[];
} NET_BUFFER_LIST_CONTEXT, *PNET_BUFFER_LIST_CONTEXT;

typedef union _NET_BUFFER_LIST_HEADER {
  NET_BUFFER_LIST_DATA NetBufferListData;
  SLIST_HEADER         Link;
} NET_BUFFER_LIST_HEADER, *PNET_BUFFER_LIST_HEADER;

typedef struct _NET_BUFFER_LIST_DATA {
  NET_BUFFER_LIST *Next;
  NET_BUFFER      *FirstNetBuffer;
} NET_BUFFER_LIST_DATA, *PNET_BUFFER_LIST_DATA;

typedef struct _NET_BUFFER_LIST
{
    union
    {
        struct
        {
            PNET_BUFFER_LIST Next;           // Next NetBufferList in the chain
            PNET_BUFFER FirstNetBuffer; // First NetBuffer on this NetBufferList
        };

        SLIST_HEADER Link;           // used in SLIST of free NetBuffers in the block

        // Duplicate of the above, for source-compatibility
        NET_BUFFER_LIST_HEADER NetBufferListHeader;
    };

    PNET_BUFFER_LIST_CONTEXT    Context;
    PNET_BUFFER_LIST            ParentNetBufferList;
    NDIS_HANDLE                 NdisPoolHandle;
    DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)PVOID NdisReserved[2];
    DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)PVOID ProtocolReserved[4];
    DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)PVOID MiniportReserved[2];
    PVOID                       Scratch;
    NDIS_HANDLE                 SourceHandle;
    ULONG                       NblFlags;   // public flags
    LONG                        ChildRefCount;
    ULONG                       Flags;      // private flags used by NDIs, protocols, miniport, etc.

    union
    {
        NDIS_STATUS             Status;
        ULONG                   NdisReserved2;
    };

    PVOID                       NetBufferListInfo[MaxNetBufferListInfo];
} NET_BUFFER_LIST, *PNET_BUFFER_LIST;

typedef struct _NET_BUFFER {
  union {
    struct {
      NET_BUFFER *Next;
      MDL        *CurrentMdl;
      ULONG      CurrentMdlOffset;
      union {
        ULONG  DataLength;
        SIZE_T stDataLength;
      };
      MDL        *MdlChain;
      ULONG      DataOffset;
    };
    SLIST_HEADER      Link;
    NET_BUFFER_HEADER NetBufferHeader;
  };
  USHORT           ChecksumBias;
  USHORT           Reserved;
  NDIS_HANDLE      NdisPoolHandle;
  PVOID            NdisReserved[2];
  PVOID            ProtocolReserved[6];
  PVOID            MiniportReserved[4];
  PHYSICAL_ADDRESS DataPhysicalAddress;
  union {
    NET_BUFFER_SHARED_MEMORY *SharedMemoryInfo;
    SCATTER_GATHER_LIST      *ScatterGatherList;
  };
} NET_BUFFER, *PNET_BUFFER;

typedef struct _MDL {
  struct _MDL      *Next;
  CSHORT           Size;
  CSHORT           MdlFlags;
  struct _EPROCESS *Process;
  PVOID            MappedSystemVa;
  PVOID            StartVa;
  ULONG            ByteCount;
  ULONG            ByteOffset;
} MDL, *PMDL;

typedef union _NET_BUFFER_HEADER {
  NET_BUFFER_DATA NetBufferData;
  SLIST_HEADER    Link;
} NET_BUFFER_HEADER, *PNET_BUFFER_HEADER;

typedef struct _NET_BUFFER_DATA {
  NET_BUFFER             *Next;
  MDL                    *CurrentMdl;
  ULONG                  CurrentMdlOffset;
  NET_BUFFER_DATA_LENGTH NbDataLength;
  MDL                    *MdlChain;
  ULONG                  DataOffset;
} NET_BUFFER_DATA, *PNET_BUFFER_DATA;

typedef struct _NET_BUFFER_SHARED_MEMORY {
  NET_BUFFER_SHARED_MEMORY *NextSharedMemorySegment;
  ULONG                    SharedMemoryFlags;
  NDIS_HANDLE              SharedMemoryHandle;
  ULONG                    SharedMemoryOffset;
  ULONG                    SharedMemoryLength;
} NET_BUFFER_SHARED_MEMORY, *PNET_BUFFER_SHARED_MEMORY;
