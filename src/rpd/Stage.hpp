#ifndef RPD_STAGE_HPP
#define RPD_STAGE_HPP

#include "../engine/InputData.hpp"
#include "../engine/Renderable.hpp"
#include <memory>
#include <vector>

namespace rpd {

class Stage {
public:
   Stage(int width, int height) : width_(width), height_(height) { ; }
   ~Stage() = default;
   Stage(const Stage& other);
   Stage& operator=(const Stage& rhs);

   void ReceiveInput(engine::InputData input);
   void Update(int ticks);
   void Render();

   inline int GetWidth() { return width_; }
   inline int GetHeight() { return height_; }

private:
   std::unique_ptr<std::vector<std::vector<int>>> tiles;
   int width_ = 0;
   int height_ = 0;
};

} // namespace rpd

#endif // RPD_STAGE_HPP
