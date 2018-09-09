#include "engine/EngineCore.hpp"

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

}

} // namespace engine