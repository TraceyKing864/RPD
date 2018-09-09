#ifndef ENGINE_ENGINECORE_HPP
#define ENGINE_ENGINECORE_HPP

#include "Clock.hpp"
#include "RenderManager.hpp"
#include "InputManager.hpp"
#include "Scene.hpp"
#include <memory>
#include <string>
#include <vector>

namespace engine {

class EngineCore {
public:
   static EngineCore& GetInstance();
   // static void Destroy();

   void Run();

private:
   EngineCore();
   ~EngineCore();
   EngineCore(const EngineCore&) = delete;
   EngineCore& operator=(const EngineCore&) = delete;
};

} // namespace engine

#endif // ENGINE_ENGINECORE_HPP
