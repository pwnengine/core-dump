#include "include.h"
#include "structs.h"
#include "entity/entity.h"
#include "hacks/hacks.h"

void hack(HINSTANCE hinstDLL) {
  AllocConsole();
  FILE* fp = freopen("CONOUT$", "w+", stdout);

  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hcon, 4);
  printf("b1g hack!\n");

  offsets_t offsets;
  offsets.dw_entity_list = 0x4DD69DC;
  offsets.dw_glow_object_manager = 0x531F608;
  offsets.m_iglow_index = 0x10488;
  offsets.dw_force_jump = 0x5280924;//0x527D360
  offsets.dw_local_player = 0xDBA5BC;
  offsets.m_fflags = 0x104;
  offsets.m_ihealth = 0x100;
  offsets.m_iteam_num = 0xF4;

  entity_t lplayer;
  game_t game;
  game.game_module = (uintptr_t)GetModuleHandle("client.dll");
  //uintptr_t client = game.module;
  //local_player.entity = *(uintptr_t*)(client + LPLAYER);
  //uintptr_t glow_manager = *(uintptr_t*)(game.game_module + 0x537E5F0);
  //uintptr_t entity_list  = *(uintptr_t*)(client + ENTLIST);
  //int local_team = *(int*)(lplayer.entity + 0xF4);
  
  /* main loop */
  for (;;) {
    if(GetKeyState(VK_END) & 0x1000)
      break;

    if(lplayer.entity) {
      printf("local player health: %d\n", lplayer.health);
      
      // hacks 
      bhop(game.game_module, lplayer, offsets);

    }
    else {
      local_player(game.game_module , &lplayer, offsets);
    }
    
    
    /*
    // do meme shit
    */

    Sleep(5);
  }
  
  fclose(fp);
  FreeConsole();
  FreeLibraryAndExitThread(hinstDLL, 0);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
  if(fdwReason == DLL_PROCESS_ATTACH) {
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)hack, hinstDLL, 0, 0);
  }

  return TRUE;
}








