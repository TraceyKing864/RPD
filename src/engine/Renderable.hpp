#ifndef ENGINE_RENDERABLE_HPP
#define ENGINE_RENDERABLE_HPP

#include <SDL2/SDL.h>

#include "RenderManager.hpp"

namespace engine {
enum RENDERABLE_DEFAULT {
   WIDTH = 16,
   HEIGHT = 16,
   SCALE = 1,
   UPDATE_INTERVAL = 200
};
class Renderable {
private:
   int pos_x;
   int pos_y;
   int width;
   int height;
   int frame;
   int frame_count;
   int animation;
   int animation_count;
   double scale;
   int update_interval;
   SDL_Texture* texture;

   void AdvanceFrame();
public:
   Renderable(SDL_Texture* in_texture, int in_x, int in_y);
   ~Renderable();
   Renderable(const Renderable& other);
   Renderable& operator=(const Renderable& rhs);

   void Update(unsigned int ticks);
   void Render();
   void SetAnimation(int in_animation);
   void SetScale(double in_scale);
   void UpdatePosition(int in_x, int in_y);
};

} // namespace engine

#endif // ENGINE_RENDERABLE_HPP