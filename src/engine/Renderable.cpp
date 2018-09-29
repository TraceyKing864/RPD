#include "Renderable.hpp"

namespace engine {

Renderable::Renderable(std::string texture_id, int pos_x, int pos_y) : 
      // pos_x_(pos_x), pos_y_(pos_y),
      width_(engine::RENDERABLE_DEFAULT::WIDTH), height_(engine::RENDERABLE_DEFAULT::HEIGHT),
      frame_(0), frame_count_(0), animation_(0), animation_count_(0),
      scale_(engine::RENDERABLE_DEFAULT::SCALE),
      update_interval_(engine::RENDERABLE_DEFAULT::UPDATE_INTERVAL),
      texture_id_(texture_id) {
   frame_count_ = 4;
   animation_count_ = 4;
}

Renderable::~Renderable() {

}

Renderable::Renderable(const Renderable& other) {

}

Renderable& Renderable::operator=(const Renderable& rhs) {

}

void Renderable::Update(unsigned int ticks) {
   static int since_last_update = 0;
   since_last_update += ticks;
   if(since_last_update > update_interval_) {
      AdvanceFrame();
      since_last_update = 0;
   }
}

void Renderable::Render(int pos_x, int pos_y) {
   SDL_Rect src = {(width_ * frame_), (height_ * animation_), width_, height_};
   // TODO: scale_ is a double whereas size must be an int, currently gimmicking it a bit to avoid warnings
   SDL_Rect dest = {pos_x, pos_y, (int)(width_ * scale_), (int)(height_ * scale_)};
   RenderManager::GetInstance().Render(texture_id_, &src, &dest);
}

void Renderable::SetAnimation(int animation) {
   if(animation < animation_count_ && animation >= 0) {
      animation_ = animation;
   }
}

void Renderable::SetScale(double scale) {
   if(scale >= 0.0) {
      scale_ = scale;
   }
}

/* void Renderable::UpdatePosition(int pos_x, int pos_y) {
   pos_x_ = pos_x;
   pos_y_ = pos_y;
} */

void Renderable::AdvanceFrame() {
   frame_++;
   if(frame_ == frame_count_) {
      frame_ = 0;
   }
}

} // namespace engine