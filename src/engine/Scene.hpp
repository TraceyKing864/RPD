#ifndef ENGINE_SCENE_HPP
#define ENGINE_SCENE_HPP

/*#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>*/
#include "../rpd/Actor.hpp"
#include "InputData.hpp"
#include "RenderManager.hpp"
#include "Renderable.hpp"

namespace engine {

class Scene {
public:
   Scene();
   ~Scene();

   void HandleInput(InputData input_data);
   void UpdateAll(unsigned int ticks);
   void RenderAll();

private:
   std::vector<std::unique_ptr<rpd::Actor>> game_objects_;
};

} // namespace engine

#endif // ENGINE_SCENE_HPP
