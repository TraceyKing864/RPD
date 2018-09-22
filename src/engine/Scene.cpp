#include "Scene.hpp"

namespace engine {

Scene::Scene() {
   game_objects_.push_back(
      std::move(std::make_unique<rpd::Actor>(0, 0)));
   // game_objects_.back()->SetScale(4.0);
}

Scene::~Scene() {

}

void Scene::HandleInput(std::queue<InputData> input_data) {
   // lol events
   while(!input_data.empty()) {
      game_objects_[0]->ReceiveInput(input_data.front());
      input_data.pop();
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