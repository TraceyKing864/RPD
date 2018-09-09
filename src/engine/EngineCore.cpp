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

/* void EngineCore::Destroy() {

} */

void EngineCore::Run() {
   bool running = true;

   SDL_Event e;

   Clock& game_clock = Clock::GetInstance();
   RenderManager& render_manager = RenderManager::GetInstance();
   // InputManager& input_manager = InputManager::GetInstance();
   std::unique_ptr<Scene> scene = std::make_unique<Scene>();

   game_clock.Start();

   while(running) {
      // handle input
      // TEMPORARY MANUAL HANDLING OF INPUT
      while(SDL_PollEvent(&e) != 0) {
         if(e.type == SDL_QUIT) {
            running = false;
         }
         else {
            scene->HandleEvent(e);
         }
      }

      // update scene
      scene->Update(game_clock.GetElapsedTicks());

      // clear last frame from renderer
      render_manager.ClearRenderer();

      // render scene
      scene->RenderAll();

      // push scene to screen
      render_manager.SceneToScreen();

      // TEMPORARY delay to ensure simple functionality is working
      SDL_Delay(1000);
   }
}

} // namespace engine
