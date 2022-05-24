#ifndef __STRUCTS__
#define __STRUCTS__
#include "include.h"

typedef struct offsets_t {
  uintptr_t dw_entity_list;
  uintptr_t dw_glow_object_manager;
  uintptr_t m_iglow_index;
  uintptr_t dw_force_jump;
  uintptr_t dw_local_player;
  uintptr_t m_fflags;
  uintptr_t m_ihealth;
  uintptr_t m_iteam_num;
} offsets_t;

typedef struct game_t {
  uintptr_t game_module;
  uintptr_t glow_object_manager;
  uintptr_t force_jump;
} game_t;

typedef struct entity_t {
  uintptr_t entity;
  int health;
  int flags;
  int team;
} entity_t;
#endif