#ifndef ENGINE_ENGINECORE_HPP
#define ENGINE_ENGINECORE_HPP

#include <SDL2/SDL.h>
#include "RenderManager.hpp"
#include "engine/InputManager.hpp"

namespace engine {

class EngineCore {
public:
   static EngineCore& GetInstance();
   static void Destroy();

   void Run();

private:
   EngineCore();
   ~EngineCore();
};

} // namespace engine

#endif // ENGINE_ENGINECORE_HPP
