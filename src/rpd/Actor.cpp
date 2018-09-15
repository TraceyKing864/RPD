#include "Actor.hpp"

namespace rpd {

Actor::Actor(double pos_x, double pos_y) :
      pos_x_(pos_x), pos_y_(pos_y),
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
   if(input.input_type == KEY_LEFT) {
      //game_objects_[0]->UpdatePosition(0,0);
   } else if(input.input_type == KEY_RIGHT) {
      //game_objects_[0]->UpdatePosition(100,0);
   }
}

void Actor::Update(int ticks) {
   pos_x_ += vel_x_;
   pos_y_ += vel_y_;
}

} // namespace rpd
