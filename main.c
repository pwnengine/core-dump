File Edit Options Buffers Tools C Help
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
gcc -c -m32 -std=c99 -pedantic -Wall main.c microui.c renderer.c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_ttf
gcc --shared -m32 -std=c99 -pedantic -Wall main.c microui.c renderer.c -o cheat `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_ttf
 */

void hack(HINSTANCE hinstDLL) {
  AllocConsole();
  FILE* fp = freopen("CONOUT$", "w+", stdout);

  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hcon, 4);
  printf("b1g hack! \n");

  /* main loop */
  for (;;) {
    if(GetKeyState(VK_END) & 0x1000)
      break;

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
