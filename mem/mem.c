#include "mem.h"

int patch(BYTE* address, BYTE* to_write, SIZE_T size) {
  DWORD protect;
  VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &protect);
  memcpy(address, to_write, size);
  VirtualProtect(address, size, protect, &protect);
}
