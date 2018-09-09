#include "engine/EngineCore.hpp"

namespace engine {

EngineCore& EngineCore::GetInstance() {
   static EngineCore singleton;
   return singleton;
}

void EngineCore::Destroy() {

}

void EngineCore::Run() {
   
}

} // namespace engine