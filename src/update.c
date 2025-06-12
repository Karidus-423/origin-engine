#include "origin.h"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DrawFrame(AppState *app) {
  // With the current app state. Draw the pixel accordingly.
  Buffer *bfr = malloc(sizeof(Buffer));
  size_t total_pixels = sizeof(Pixel) * (app->height * app->width);
  bfr->pixels = malloc(total_pixels);
  bfr->pitch = app->width * sizeof(Pixel);

  // Rasterizer
  bfr->pixels = Rasterize(app);
  // RayTracer
  // bfr->pixels = RayTrace(app);
}

// TODO: This is temporary. Should replace with my own rendering.
void DebugInfo(AppState *app) {

  // NOTE: If this overflow, we get crash.Add some checks to make sure this
  // does not happen.
  char win_x[50];
  sprintf(win_x, "Win-X:%d", app->width);
  char win_y[50];
  sprintf(win_y, "Win-Y:%d", app->height);

  /* light blue, full alpha */
  SDL_SetRenderDrawColor(app->rndr, 51, 102, 255, SDL_ALPHA_OPAQUE);
  SDL_RenderDebugText(app->rndr, 184, 200, "DEBUG ON");
  SDL_RenderDebugText(app->rndr, 184, 210, win_x);
  SDL_RenderDebugText(app->rndr, 184, 220, win_y);
}

// Handles all updates. Texture update, Event Updates, etc...
void UpdateApp(AppState *app) {

  // Hadle Player Actions
  HandleEvents(app);
  if (app->debug == true) {
    DebugInfo(app);
  }
  // Reflect Changes in Scene
  // UpdateScene(app);

  // Update the buffer for the new Scene and apply to render texture.
  DrawFrame(app);
  SDL_UpdateTexture(app->txtr, NULL, app->bfr->pixels, app->bfr->pitch);
}
