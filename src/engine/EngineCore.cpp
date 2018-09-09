#include "EngineCore.hpp"

namespace engine {

EngineCore::EngineCore() {
   RenderManager::GetInstance();

}

EngineCore::~EngineCore() {

}

EngineCore& EngineCore::GetInstance() {
   static EngineCore singleton;
   return singleton;
}

void EngineCore::Destroy() {

}

void EngineCore::Run() {
   bool running = true;

   SDL_Event e;
   Scene look_at_this;
   unsigned int i = 0;

   while(running) {
      SDL_RenderClear(RenderManager::GetInstance().GetRenderer());
      // handle input
      // TEMPORARY MANUAL HANDLING OF INPUT
      while(SDL_PollEvent(&e) != 0) {
         if(e.type == SDL_QUIT) {
            running = false;
         }
         else {
            look_at_this.HandleEvent(e);
         }
      }

      // update scene
      look_at_this.Update(i);

      // render scene
      look_at_this.RenderAll();

      // push scene to screen
      SDL_RenderPresent(RenderManager::GetInstance().GetRenderer());

      i += 100;
      SDL_Delay(1000);
   }
}

} // namespace engine
