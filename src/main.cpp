#include "engine/EngineCore.hpp"

int main(int argc, char *argv[])
{
   engine::EngineCore the_core = engine::EngineCore::GetInstance();

   the_core.Run();
}
