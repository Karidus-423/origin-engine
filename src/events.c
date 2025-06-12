#include "origin.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_stdinc.h>
#include <stdio.h>

void TriggerKeyBoardEvents(AppState *app, SDL_Event *event) {
  Uint32 t = event->type;
  SDL_KeyboardEvent k = event->key;

  // Controls
  if (t == SDL_EVENT_KEY_DOWN) {
    if (k.key == SDLK_F3) {
      app->debug = !app->debug;
    }
  }
}

void HandleEvents(AppState *app) {
  SDL_Event *event = &app->event;

  while (SDL_PollEvent(event)) {
    if (event->type == SDL_EVENT_QUIT) {
      app->running = false;
    } else if (event->type >= SDL_EVENT_KEY_DOWN && // Range of Keyboard events.
               event->type <= SDL_EVENT_TEXT_EDITING_CANDIDATES) {
      TriggerKeyBoardEvents(app, event);
    }
  }
}
