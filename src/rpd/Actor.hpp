#ifndef RPD_ACTOR_HPP
#define RPD_ACTOR_HPP

#include "../engine/InputData.hpp"
#include "../engine/Renderable.hpp"
#include <memory>

namespace rpd {

class Actor {
public:
   Actor(double width, double height, double pos_x, double pos_y);
   ~Actor();
   Actor(const Actor& other);
   Actor& operator=(const Actor& rhs);

   void ReceiveInput(engine::InputData input);
   void Update(int ticks);
   void Render();

   inline int GetWidth() { return width_; }
   inline int GetHeight() { return height_; }
   inline double GetPosX() { return pos_x_; }
   inline double GetPosY() { return pos_y_; }
   inline double ForcePosX(double pos_x) { pos_x_ = pos_x; }
   inline double ForcePosY(double pos_y) { pos_y_ = pos_y; }

private:
   std::unique_ptr<engine::Renderable> renderable_ = nullptr;
   double width_ = 0;
   double height_ = 0;
   double pos_x_ = 0;
   double pos_y_ = 0;
   double pos_z_ = 0;
   double vel_x_ = 0;
   double vel_y_ = 0;
   double max_velocity_ = 0;
};

} // namespace rpd

#endif // RPD_ACTOR_HPP
