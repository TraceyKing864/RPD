#ifndef RPD_ACTOR_HPP
#define RPD_ACTOR_HPP

#include "../engine/Renderable.hpp"
#include "../engine/InputData.hpp"
#include <memory>

namespace rpd {

class Actor {
public:
   Actor(double pos_x, double pos_y);
   ~Actor();
   Actor(const Actor& other);
   Actor& operator=(const Actor& rhs);

   void ReceiveInput(engine::InputData input);
   void Update(int ticks);
   void Render();

private:
   std::unique_ptr<engine::Renderable> renderable_ = nullptr;
   double pos_x_ = 0;
   double pos_y_ = 0;
   double pos_z_ = 0;
   double vel_x_ = 0;
   double vel_y_ = 0;
   double max_velocity_ = 0;
};

} // namespace rpd

#endif // RPD_ACTOR_HPP
