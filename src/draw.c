#include "origin.h"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

// DRAW A FOKIN TRIANGLE MOTHERUFCKER
typedef struct {
  SDL_Vertex vertices[3];
  int size;
} Triangle;

void DrawApp(AppState *app) {
  SDL_Vertex left, right, top;
  left.position = (SDL_FPoint){250, 150};
  left.color = (SDL_FColor){.0f, .0f, 1.0f, 0.f};

  right.position = (SDL_FPoint){100, 300};
  right.color = (SDL_FColor){.0f, 1.0f, .0f, 0.f};

  top.position = (SDL_FPoint){400, 300};
  top.color = (SDL_FColor){1.0f, .0f, .0f, 0.f};

  Triangle holy = {
      .vertices = {left, right, top},
      .size = 3,
  };

  SDL_RenderGeometry(app->rndr, NULL, holy.vertices, holy.size, NULL, 0);
}
