#ifndef ENGINE_ENGINECORE_HPP
#define ENGINE_ENGINECORE_HPP

#include "RenderManager.hpp"
#include "InputManager.hpp"

namespace engine {

class EngineCore {
public:
   ~EngineCore();

   static EngineCore& GetInstance();
   static void Destroy();

   void Run();

private:
   EngineCore();
};

} // namespace engine

#endif // ENGINE_ENGINECORE_HPP
