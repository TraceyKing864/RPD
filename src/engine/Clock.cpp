#include "Clock.hpp"

namespace engine {

Clock& Clock::GetInstance()
{
    static Clock clock;
    return clock;
}

Clock::Clock()
{
    time_started_ = 0;
    time_paused_ = 0;
    ticks_ = 0;

    paused_ = false;
    started_ = false;
}

Clock::~Clock()
{

}

void Clock::Start()
{
   started_ = true;
   paused_ = false;

   ticks_ = SDL_GetTicks();
}

void Clock::Stop()
{
    
}

void Clock::Pause()
{
   if(started_ && !paused_) {
      time_paused_ = SDL_GetTicks() - time_started_;
      paused_ = true;
   }
}

void Clock::Unpause()
{
   if(started_ && paused_) {
      time_started_ = SDL_GetTicks() - time_paused_;
      paused_ = false;
   }
}

void Clock::IncrementFrames()
{
   if(!paused_)
      frames_++;
}

Uint32 Clock::GetTicks()
{
   return paused_ ? time_paused_ : SDL_GetTicks() - time_started_;
}

Uint32 Clock::GetElapsedTicks()
{
   if(paused_)
      return 0;

   curr_ticks_ = GetTicks();
   ticks_ = curr_ticks_ - prev_ticks_;
   prev_ticks_ = curr_ticks_;

   return ticks_;
}

} // namespace engine
