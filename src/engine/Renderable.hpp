#ifndef ENGINE_RENDERABLE_HPP
#define ENGINE_RENDERABLE_HPP

#include <SDL2/SDL.h>
#include <string>
#include "RenderManager.hpp"

namespace engine {

enum RENDERABLE_DEFAULT {
   WIDTH = 16,
   HEIGHT = 16,
   SCALE = 1,
   UPDATE_INTERVAL = 200
};

class Renderable {
public:
   Renderable(std::string texture_id, int pos_x, int pos_y);
   ~Renderable();
   Renderable(const Renderable& other);
   Renderable& operator=(const Renderable& rhs);

   void Update(unsigned int ticks);
   void Render();
   void SetAnimation(int animation);
   void SetScale(double scale);
   void UpdatePosition(int pos_x, int pos_y);

private:
   int pos_x_;
   int pos_y_;
   int width_;
   int height_;
   int frame_;
   int frame_count_;
   int animation_;
   int animation_count_;
   double scale_;
   int update_interval_;
   std::string texture_id_;

   void AdvanceFrame();
};

} // namespace engine

#endif // ENGINE_RENDERABLE_HPP