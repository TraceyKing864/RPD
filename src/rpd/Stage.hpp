#ifndef RPD_STAGE_HPP
#define RPD_STAGE_HPP

#include "../engine/Renderable.hpp"
#include "../engine/InputData.hpp"
#include <memory>
#include <vector>

namespace rpd {

class Stage {
public:
   Stage(double width, double height);
   ~Stage();
   Stage(const Stage& other);
   Stage& operator=(const Stage& rhs);

   void ReceiveInput(engine::InputData input);
   void Update(int ticks);
   void Render();

private:
   std::vector<std::vector<double>> tiles;
   double width_ = 0;
   double height_ = 0;
};

} // namespace rpd

#endif // RPD_STAGE_HPP
