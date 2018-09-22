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

std::queue<InputData> InputManager::HandleInput() {
   std::queue<InputData> event_data;

   SDL_Event e;
   while(SDL_PollEvent(&e) != 0) {
      InputData input;
      if(e.type == SDL_QUIT) {
         input.input_type = QUIT;
         event_data.push(input);
         return event_data;
      }
      else if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {
         switch(e.key.keysym.sym) {
            case SDLK_UP:
               input.input_type = MOVE_UP;
               input.input_value = 1;
               event_data.push(input);
               break;
            case SDLK_DOWN:
               input.input_type = MOVE_DOWN;
               input.input_value = 1;
               event_data.push(input);
               break;
            case SDLK_LEFT:
               input.input_type = MOVE_LEFT;
               input.input_value = 1;
               event_data.push(input);
               break;
            case SDLK_RIGHT:
               input.input_type = MOVE_RIGHT;
               input.input_value = 1;
               event_data.push(input);
               break;
         }
      }
      else if(e.type == SDL_KEYUP && e.key.repeat == 0) {
         switch(e.key.keysym.sym) {
            case SDLK_UP:
               input.input_type = MOVE_UP;
               input.input_value = -1;
               event_data.push(input);
               break;
            case SDLK_DOWN:
               input.input_type = MOVE_DOWN;
               input.input_value = -1;
               event_data.push(input);
               break;
            case SDLK_LEFT:
               input.input_type = MOVE_LEFT;
               input.input_value = -1;
               event_data.push(input);
               break;
            case SDLK_RIGHT:
               input.input_type = MOVE_RIGHT;
               input.input_value = -1;
               event_data.push(input);
               break;
         }
      }
   }

   return event_data;
}

} // namespace engine
