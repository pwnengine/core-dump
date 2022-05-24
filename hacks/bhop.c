#include "bhop.h"

void bhop(uintptr_t client, entity_t lplayer, offsets_t offsets) {
  int curr_flag = *(int*)(lplayer.entity + offsets.m_fflags);// dont forget to get the updated flags right b4 checking lol
  if(GetAsyncKeyState(VK_SPACE) & 0x8000 && curr_flag != 256) {
    *(int*)(client + offsets.dw_force_jump) = 2;
  }
}
