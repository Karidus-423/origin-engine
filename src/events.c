#include "origin.h"

void HandleEvents(AppState *app) {
  SDL_Event *event = &app->event;
  SDL_PollEvent(event);
  if (event->type == SDL_EVENT_QUIT) {
    app->running = false;
  }
}
