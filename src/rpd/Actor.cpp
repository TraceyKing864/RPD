#include "Actor.hpp"

namespace rpd {

Actor::Actor(double pos_x, double pos_y) :
      pos_x_(pos_x), pos_y_(pos_y), max_velocity_(1),
      renderable_(std::make_unique<engine::Renderable>("../assets/archer.png", pos_x, pos_y)) {
   // lol idunno
}

Actor::~Actor() {

}

Actor::Actor(const Actor& other) {

}

Actor& Actor::operator=(const Actor& rhs) {

}

void Actor::ReceiveInput(engine::InputData input) {
   if(input.input_type == engine::InputType::MOVE_UP) {
      vel_y_ -= max_velocity_ * input.input_value;
      renderable_->SetAnimation(3);
   } else if(input.input_type == engine::InputType::MOVE_DOWN) {
      vel_y_ += max_velocity_ * input.input_value;
      renderable_->SetAnimation(0);
   } else if(input.input_type == engine::InputType::MOVE_LEFT) {
      vel_x_ -= max_velocity_ * input.input_value;
      renderable_->SetAnimation(1);
   } else if(input.input_type == engine::InputType::MOVE_RIGHT) {
      vel_x_ += max_velocity_ * input.input_value;
      renderable_->SetAnimation(2);
   }
}

void Actor::Update(int ticks) {
   pos_x_ += vel_x_;
   pos_y_ += vel_y_;

   renderable_->Update(ticks);
}

void Actor::Render() {
   renderable_->Render(pos_x_, pos_y_);
}

} // namespace rpd
