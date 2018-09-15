#ifndef ENGINE_RENDERABLE_HPP
#define ENGINE_RENDERABLE_HPP

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
   void Render(int pos_x, int pos_y);
   void SetAnimation(int animation);
   void SetScale(double scale);
   // void UpdatePosition(int pos_x, int pos_y);

private:
   void AdvanceFrame();

   int width_ = 0;
   int height_ = 0;
   int frame_ = 0;
   int frame_count_ = 0;
   int animation_ = 0;
   int animation_count_ = 0;
   double scale_ = 0.0;
   int update_interval_ = 0.0;
   std::string texture_id_ = "";
};

} // namespace engine

#endif // ENGINE_RENDERABLE_HPP