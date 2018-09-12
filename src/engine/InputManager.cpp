#include "InputManager.hpp"

namespace engine {

InputManager::InputManager() {
}

InputManager::~InputManager() {
}

InputManager& InputManager::GetInstance() {
   static InputManager singleton;
   return singleton;
}

InputData InputManager::HandleInput() {
   InputData event_data;

   SDL_Event e;
   while(SDL_PollEvent(&e) != 0) {
      if(e.type == SDL_QUIT) {
         event_data.input_type = QUIT;
      }
      else if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {
         switch(e.key.keysym.sym) {
            case SDLK_UP: ; break;
            case SDLK_DOWN: ; break;
            case SDLK_LEFT: event_data.input_type = KEY_LEFT; break;
            case SDLK_RIGHT: event_data.input_type = KEY_RIGHT; break;
         }
      }
      else if(e.type == SDL_KEYUP && e.key.repeat == 0) {
         switch(e.key.keysym.sym) {
            case SDLK_UP: ; break;
            case SDLK_DOWN: ; break;
            case SDLK_LEFT: ; break;
            case SDLK_RIGHT: ; break;
         }
      }
   }

   return event_data;
}

} // namespace engine
