#ifndef _NDISSTRUCT_H_
#define _NDISSTRUCT_H_

#include "intro_types.h"
#include "introtypes.h"

//------------------------------------------------NET BUFFER LIST------------------------------------------------------------------
// from https://github.com/ntdiff/headers/blob/ec39df2a0d463404b8da0facdc4bebd2e838e40f/Win10_21H1_20180/x64/System32/ndis.sys/Standalone/_NET_BUFFER_LIST.h

typedef union _SLIST_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long long Alignment; //originally __int64
      /* 0x0008 */ unsigned long long Region;  //originally __int64
    }; /* size: 0x0010 */
    struct
    {
      struct /* bitfield */
      {
        /* 0x0000 */ unsigned long long Depth : 16; /* bit position: 0 */  //originally __int64
        /* 0x0000 */ unsigned long long Sequence : 48; /* bit position: 16 */ //originally __int64
      }; /* bitfield */
      struct /* bitfield */
      {
        /* 0x0008 */ unsigned long long Reserved : 4; /* bit position: 0 */ //originally __int64
        /* 0x0008 */ unsigned long long NextEntry : 60; /* bit position: 4 */ //originally __int64
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

//-------------------------------------------END OF NET BUFFER LIST----------------------------------------------------------------

//--------------------------------------------------NET BUFFER---------------------------------------------------------------------
typedef union _SLIST_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned __int64 Alignment;
      /* 0x0008 */ unsigned __int64 Region;
    }; /* size: 0x0010 */
    struct
    {
      struct /* bitfield */
      {
        /* 0x0000 */ unsigned __int64 Depth : 16; /* bit position: 0 */
        /* 0x0000 */ unsigned __int64 Sequence : 48; /* bit position: 16 */
      }; /* bitfield */
      struct /* bitfield */
      {
        /* 0x0008 */ unsigned __int64 Reserved : 4; /* bit position: 0 */
        /* 0x0008 */ unsigned __int64 NextEntry : 60; /* bit position: 4 */
      }; /* bitfield */
    } /* size: 0x0010 */ HeaderX64;
  }; /* size: 0x0010 */
} SLIST_HEADER, *PSLIST_HEADER; /* size: 0x0010 */

typedef union _NET_BUFFER_DATA_LENGTH
{
  union
  {
    /* 0x0000 */ unsigned long DataLength;
    /* 0x0000 */ unsigned __int64 stDataLength;
  }; /* size: 0x0008 */
} NET_BUFFER_DATA_LENGTH, *PNET_BUFFER_DATA_LENGTH; /* size: 0x0008 */

typedef struct _NET_BUFFER_DATA
{
  /* 0x0000 */ struct _NET_BUFFER* Next;
  /* 0x0008 */ struct _MDL* CurrentMdl;
  /* 0x0010 */ unsigned long CurrentMdlOffset;
  /* 0x0018 */ union _NET_BUFFER_DATA_LENGTH NbDataLength;
  /* 0x0020 */ struct _MDL* MdlChain;
  /* 0x0028 */ unsigned long DataOffset;
  /* 0x002c */ long __PADDING__[1];
} NET_BUFFER_DATA, *PNET_BUFFER_DATA; /* size: 0x0030 */

typedef union _NET_BUFFER_HEADER
{
  union
  {
    /* 0x0000 */ struct _NET_BUFFER_DATA NetBufferData;
    /* 0x0000 */ union _SLIST_HEADER Link;
  }; /* size: 0x0030 */
} NET_BUFFER_HEADER, *PNET_BUFFER_HEADER; /* size: 0x0030 */

typedef union _LARGE_INTEGER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    }; /* size: 0x0008 */
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    } /* size: 0x0008 */ u;
    /* 0x0000 */ __int64 QuadPart;
  }; /* size: 0x0008 */
} LARGE_INTEGER, *PLARGE_INTEGER; /* size: 0x0008 */

typedef struct _NET_BUFFER
{
  union
  {
    struct
    {
      /* 0x0000 */ struct _NET_BUFFER* Next;
      /* 0x0008 */ struct _MDL* CurrentMdl;
      /* 0x0010 */ unsigned long CurrentMdlOffset;
      union
      {
        /* 0x0018 */ unsigned long DataLength;
        struct
        {
          /* 0x0018 */ unsigned __int64 stDataLength;
          /* 0x0020 */ struct _MDL* MdlChain;
          /* 0x0028 */ unsigned long DataOffset;
        }; /* size: 0x0014 */
      }; /* size: 0x0014 */
    }; /* size: 0x0028 */
    /* 0x0000 */ union _SLIST_HEADER Link;
    /* 0x0000 */ union _NET_BUFFER_HEADER NetBufferHeader;
  }; /* size: 0x0030 */
  /* 0x0030 */ unsigned short ChecksumBias;
  /* 0x0032 */ unsigned short Reserved;
  /* 0x0038 */ void* NdisPoolHandle;
  /* 0x0040 */ void* NdisReserved[2];
  /* 0x0050 */ void* ProtocolReserved[6];
  /* 0x0080 */ void* MiniportReserved[4];
  /* 0x00a0 */ union _LARGE_INTEGER DataPhysicalAddress;
  union
  {
    /* 0x00a8 */ struct _NET_BUFFER_SHARED_MEMORY* SharedMemoryInfo;
    /* 0x00a8 */ struct _SCATTER_GATHER_LIST* ScatterGatherList;
  }; /* size: 0x0008 */
} NET_BUFFER, *PNET_BUFFER; /* size: 0x00b0 */

//-----------------------------------------END OF NET BUFFER---------------------------------------------------------------------

#endif
