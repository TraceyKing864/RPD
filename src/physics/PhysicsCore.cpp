#include "PhysicsCore.hpp"

namespace physics {

PhysicsCore::PhysicsCore() {

}

PhysicsCore::~PhysicsCore() {

}

PhysicsCore& PhysicsCore::GetInstance() {
   static PhysicsCore singleton;
   return singleton;
}

void PhysicsCore::Initialize(std::shared_ptr<std::vector<std::unique_ptr<rpd::Actor>>> actors,
      std::shared_ptr<rpd::Stage> stage) {
   x_max_ = stage->GetWidth();
   y_max_ = stage->GetHeight();
   actors_ = actors;
   stage_ = stage;
}

void PhysicsCore::CheckCollisions() {
   for(auto &actor : *actors_) {
      double temp_x = actor->GetPosX();
      double temp_y = actor->GetPosY();
      if(temp_x < x_min_) {
         actor->ForcePosX(x_min_);
      } if(temp_x + actor->GetWidth() > x_max_) {
         actor->ForcePosX(x_max_ - actor->GetWidth());
      } if(temp_y < y_min_) {
         actor->ForcePosY(y_min_);
      } if(temp_y + actor->GetHeight() > y_max_) {
         actor->ForcePosY(y_max_ - actor->GetHeight());
      }
   }
}

}