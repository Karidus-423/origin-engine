#include "origin.h"

void RunApp(AppState *app) {
  while (app->running == true) {
    HandleEvents(app);

    SDL_SetRenderDrawColor(app->rndr, 0xCC, 0xCC, 0xCC, 0x00);
    SDL_RenderClear(app->rndr);

    SDL_SetRenderTarget(app->rndr, NULL);
    DrawApp(app);
    SDL_RenderPresent(app->rndr);
  }
}

int main(int argc, char *argv[]) {
  AppState app = {
      .title = "Pichoo",
      .width = 500,
      .height = 500,
  };

  if (!InitApp(&app)) {
    SDL_Quit();
    return 1;
  }

  if (app.running == true) {
    RunApp(&app);
  }

  DenitApp(&app);
  SDL_Quit();
  return 0;
}
