#include "origin.h"
#include <SDL3/SDL_render.h>
#include <stdio.h>
#include <stdlib.h>

void RunApp(AppState *app) {

  // Drawig should be in syc with monitor frame rate.
  while (app->running == true) {
    SDL_SetRenderDrawColor(app->rndr, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(app->rndr);

    UpdateApp(app);

    SDL_RenderTexture(app->rndr, app->txtr, NULL, NULL);
    SDL_RenderPresent(app->rndr);
  }
}

int main(int argc, char *argv[]) {
  AppState app = {
      .title = "Pichoo",
      .width = 1200,
      .height = 900,
      .debug = false,
  };

  if (InitApp(&app) == true) {
    RunApp(&app);
  } else {
    SDL_Quit();
    return 1;
  }

  DenitApp(&app);
  SDL_Quit();
  return 0;
}
