#include "entity.h"
#include "../structs.h"

void local_player(uintptr_t client, entity_t* lplayer, offsets_t offsets) {
  lplayer->entity = *(intptr_t*)(client + offsets.dw_local_player);
  if(lplayer->entity) {
    lplayer->health = *(int*)(lplayer->entity + offsets.m_ihealth);
    lplayer->flags = *(int*)(lplayer->entity + offsets.m_fflags);
    lplayer->team = *(int*)(lplayer->entity + offsets.m_iteam_num);
  }
}
