#include "Scene.hpp"

namespace engine {

Scene::Scene() {
   game_objects_.push_back(
      std::move(std::make_unique<Renderable>("../assets/archer.png", 0, 0)));
   game_objects_.back()->SetScale(4.0);
}

Scene::~Scene() {

}

void Scene::HandleInput(InputData input_data) {
   // lol events
   if(input_data.input_type == KEY_LEFT) {
      game_objects_[0]->UpdatePosition(0,0);
   } else if(input_data.input_type == KEY_RIGHT) {
      game_objects_[0]->UpdatePosition(100,0);
   }
}

void Scene::UpdateAll(unsigned int ticks) {
   for(auto &object : game_objects_) {
      object->Update(ticks);
   }
}

void Scene::RenderAll() {
   // CURRENTLY RENDERS IN ARBITRARY ORDER.
   for(auto &object : game_objects_) {
      object->Render();
   }
}

} // namespace engine