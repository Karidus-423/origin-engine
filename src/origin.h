#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

// TODO: SETUP ARENA
typedef union Arena {

} Arena;

typedef struct Pixel {
  unsigned char a;
  unsigned char b;
  unsigned char g;
  unsigned char r;
} Pixel;

typedef struct {
  Pixel *pixels;
  size_t size;
  int pitch;
} Buffer;

typedef struct AppState {
  bool running;
  bool debug;
  int width;
  int height;
  const char *title;
  SDL_Window *win;
  SDL_Renderer *rndr;
  Buffer *bfr;
  SDL_Texture *txtr;
  SDL_Event event;
} AppState;

typedef struct GameState {
} GameState;

bool InitApp(AppState *app);
void DenitApp(AppState *app);
void HandleEvents(AppState *app);
void UpdateApp(AppState *app);

void Rasterize(AppState *app);
Pixel *RayTrace(AppState *app);
