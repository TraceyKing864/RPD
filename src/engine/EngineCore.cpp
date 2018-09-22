#include "EngineCore.hpp"

namespace engine {

EngineCore::EngineCore() {
   RenderManager::GetInstance();
   InputManager::GetInstance();
   Clock::GetInstance();
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

   Clock& game_clock = Clock::GetInstance();
   RenderManager& render_manager = RenderManager::GetInstance();
   InputManager& input_manager = InputManager::GetInstance();
   std::unique_ptr<Scene> scene = std::make_unique<Scene>();

   game_clock.Start();
   render_manager.LoadTextures(std::vector<std::string>({"../assets/archer.png"}));

   std::queue<InputData> input_data;
   while(running) {
      // handle input
      input_data = input_manager.HandleInput();

      if(!input_data.empty() && input_data.back().input_type == InputType::QUIT) {
         running = false;
      } else {
         // pass the received input to the scene
         scene->HandleInput(input_data);

         // update scene
         scene->UpdateAll(game_clock.GetElapsedTicks());

         // clear last frame from renderer
         render_manager.ClearRenderer();

         // render scene
         scene->RenderAll();

         // push scene to screen
         render_manager.SceneToScreen();
      }

      // TEMPORARY delay to ensure simple functionality is working
      //SDL_Delay(250);
   }
}

} // namespace engine
