#include "origin.h"

typedef struct Vector2 {
  float x;
  float y;
} Vector2;

float Dot(Vector2 a, Vector2 b) { return (a.x * b.x) + (a.y * b.y); }

Vector2 Perpendicular(Vector2 p) { return (Vector2){.x = p.y, .y = -p.x}; }

bool PointOnRightSide(Vector2 a, Vector2 b, Vector2 p) {
  Vector2 ap = (Vector2){.x = p.x - a.x, .y = p.y - a.y};
  Vector2 ab_perp = Perpendicular((Vector2){.x = b.x - a.x, .y = b.y - a.y});

  return Dot(ap, ab_perp) >= 0;
}

bool PointInTriangle(Vector2 a, Vector2 b, Vector2 c, Vector2 p) {
  bool side_AB = PointOnRightSide(a, b, p);
  bool side_BC = PointOnRightSide(b, c, p);
  bool side_CA = PointOnRightSide(c, a, p);

  return side_AB == side_BC && side_BC == side_CA;
}

void Rasterize(AppState *app) {
  Buffer *bfr = app->bfr;

  Vector2 a = {.x = 0.2f * app->width, .y = 0.2f * app->height};
  Vector2 b = {.x = 0.7f * app->width, .y = 0.4f * app->height};
  Vector2 c = {.x = 0.4f * app->width, .y = 0.8f * app->height};

  Vector2 d = {.x = 0.5f * app->width, .y = 0.5f * app->height};
  Vector2 e = {.x = 0.1f * app->width, .y = 0.3f * app->height};
  Vector2 f = {.x = 0.4f * app->width, .y = 0.8f * app->height};

  for (int y = 0; y < app->height; y++) {
    for (int x = 0; x < app->width; x++) {
      int i = (y * app->width) + x;
      Vector2 p = {.x = x, .y = y};
      Vector2 p2 = {.x = x - 20, .y = y - 20};

      bool p_inside = PointInTriangle(a, b, c, p);
      if (p_inside) {
        bfr->pixels[i] = (Pixel){255, 120, 120, 0};
      }

      bool inside = PointInTriangle(d, e, f, p2);
      if (inside) {
        bfr->pixels[i] = (Pixel){255, 0, 120, 120};
      }
    }
  }
}
