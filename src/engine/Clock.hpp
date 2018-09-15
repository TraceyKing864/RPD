#ifndef ENGINE_CLOCK_HPP
#define ENGINE_CLOCK_HPP

#include <SDL2/SDL.h>

namespace engine {

class Clock
{
public:
   static Clock& GetInstance();

   void Start();
   void Stop();
   void Pause();
   void Unpause();

   void IncrementFrames();

   Uint32 GetTicks();
   Uint32 GetElapsedTicks();
   inline double GetFPS() { return GetFrames() / GetSeconds(); };
        
   inline bool IsStarted() { return started_; };
   inline bool IsPaused() { return paused_; };

private:
   Clock();
   ~Clock();
   Clock(const Clock&) = delete;
   Clock& operator=(const Clock&) = delete;
   
   int GetFrames() { return frames_; };
   int GetSeconds() { return GetTicks()/1000; };

   Uint32 time_started_;
   Uint32 time_paused_;
   Uint32 ticks_;
   Uint32 curr_ticks_;
   Uint32 prev_ticks_;
   int frames_;
   bool paused_;
   bool started_;
};

} // namespace engine

#endif // ENGINE_CLOCK_HPP
