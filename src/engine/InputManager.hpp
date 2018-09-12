#ifndef ENGINE_INPUTMANAGER_HPP
#define ENGINE_INPUTMANAGER_HPP

#include <SDL2/SDL.h>
#include "InputData.hpp"

namespace engine {

class InputManager {
public:
   static InputManager& GetInstance();
   // static void Destroy();

   InputData HandleInput();

private:
   InputManager();
   ~InputManager();
   InputManager(const InputManager&) = delete;
   InputManager& operator=(const InputManager&) = delete;
};

} // namespace engine

#endif // ENGINE_INPUTMANAGER_HPP