#ifndef ENGINE_SCENE_HPP
#define ENGINE_SCENE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderManager.hpp"
#include "Renderable.hpp"

namespace engine {

class Scene {
public:
   Scene();
   ~Scene();

   void HandleEvent(const SDL_Event& e); // TODO: remove in favor of inputmanager stuff
   void Update(unsigned int i);
   void RenderAll();

private:
   Renderable* thing_to_render_;
};

} // namespace engine

#endif // ENGINE_SCENE_HPP
