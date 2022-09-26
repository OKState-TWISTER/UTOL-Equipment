// This is the main DLL file.

// Link to ws2_32.lib:
#pragma comment (lib, "ws2_32.lib")
#include <winsock2.h>
#include <ws2tcpip.h>
// Link to lphlpapi.lib:
#pragma comment (lib, "Iphlpapi.lib")
#include <iphlpapi.h>

#include <stdlib.h>

#include "IPconnections.h"

#pragma unmanaged

BOOL APIENTRY DllMain( HANDLE hModule,
                        DWORD  ul_reason_for_call,
                        LPVOID lpReserved )
{
    return TRUE;
}

extern "C"{
 __declspec(dllexport)
int
nIPconnections
(){
  PMIB_IPADDRTABLE pIPAddrTable;
  DWORD dwSize = 0;
  DWORD dwRetVal = 0;
  int retval;

  pIPAddrTable = (MIB_IPADDRTABLE *) malloc(sizeof (MIB_IPADDRTABLE));

  if(pIPAddrTable){
    if(GetIpAddrTable(pIPAddrTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER){
      // Not enough space, re-allocate...
      free(pIPAddrTable);
      pIPAddrTable = (MIB_IPADDRTABLE *) malloc(dwSize);
      if (pIPAddrTable == NULL){
        // Memory re-allocation failed for GetIpAddrTable()
        return -1;
      }
    }
  }
  if((dwRetVal = GetIpAddrTable( pIPAddrTable, &dwSize, 0 )) != NO_ERROR)
    // "GetIpAddrTable() failed with error %d\n", dwRetVal
    return -1;
  retval = pIPAddrTable->dwNumEntries;
  if (pIPAddrTable){
    free(pIPAddrTable);
    pIPAddrTable = NULL;
  }
  return retval;
}
} // extern "C"

extern "C"{
 __declspec(dllexport)
int
IPconnections
(u_long *addresses,
 u_long *broadcast,
 int n){
  // (minor) YUCK: Would like to use the Qt solution for determination
  // of broadcast address (see #else)
  PMIB_IPADDRTABLE pIPAddrTable;
  DWORD dwSize = 0;
  DWORD dwRetVal = 0;
  int i;

  pIPAddrTable = (MIB_IPADDRTABLE *) malloc(sizeof (MIB_IPADDRTABLE));

  if(pIPAddrTable){
    if(GetIpAddrTable(pIPAddrTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER){
      // Not enough space, re-allocate...
      free(pIPAddrTable);
      pIPAddrTable = (MIB_IPADDRTABLE *) malloc(dwSize);
      if (pIPAddrTable == NULL){
        // Memory re-allocation failed for GetIpAddrTable()
        return -1;
      }
    }
  }
  if((dwRetVal = GetIpAddrTable( pIPAddrTable, &dwSize, 0 )) != NO_ERROR)
    // "GetIpAddrTable() failed with error %d\n", dwRetVal
    return -1;

  if((int) pIPAddrTable->dwNumEntries != n)
	return -1;

  for(i=0; i < (int) pIPAddrTable->dwNumEntries; ++i){
	addresses[i] = (u_long)pIPAddrTable->table[i].dwAddr;
	broadcast[i] = ((u_long)pIPAddrTable->table[i].dwAddr |
       (~(u_long)pIPAddrTable->table[i].dwMask))
      & 0xffffffff;
  }
  if (pIPAddrTable){
    free(pIPAddrTable);
    pIPAddrTable = NULL;
  }
  return 0;
}
} // extern "C"