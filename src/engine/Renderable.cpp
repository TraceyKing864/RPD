#include "Renderable.hpp"

namespace engine{

Renderable::Renderable(SDL_Texture* in_texture, int in_x, int in_y) : 
      pos_x(in_x), pos_y(in_y), 
      width(engine::RENDERABLE_DEFAULT::WIDTH), height(engine::RENDERABLE_DEFAULT::HEIGHT), 
      frame(0), frame_count(0), 
      animation(0), animation_count(0), 
      scale(engine::RENDERABLE_DEFAULT::SCALE), 
      update_interval(engine::RENDERABLE_DEFAULT::UPDATE_INTERVAL),
      texture(in_texture){
   frame_count = 4;
   animation_count = 4;
}

Renderable::~Renderable() {

}

Renderable::Renderable(const Renderable& other) {

}

Renderable& Renderable::operator=(const Renderable& rhs) {

}

void Renderable::AdvanceFrame() {
   frame++;
   if(frame == frame_count)
      frame = 0;
}

void Renderable::Update(unsigned int ticks) {
   static int since_last_update = 0;
   since_last_update += ticks;
   if(since_last_update > update_interval){
      AdvanceFrame();
      since_last_update = 0;
   }
}

void Renderable::Render() {
   SDL_Rect src = {(width * frame), (height * animation), width, height};
   SDL_Rect dest = {pos_x, pos_y, width, height};
   RenderManager::GetInstance().Render(texture, &src, &dest);
}

void Renderable::SetAnimation(int in_animation) {
   if (in_animation < animation_count)
      animation = in_animation;
}

void Renderable::SetScale(double in_scale) {
   scale = in_scale;
}

void Renderable::UpdatePosition(int in_x, int in_y) {
   pos_x = in_x;
   pos_y = in_y;
}

} // namespace engine