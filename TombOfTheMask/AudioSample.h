#pragma once
#include "UObject.h"
class AudioSample : public UObject
{
  private:
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;

  public:
    AudioSample(std::string SoundFileName);
    bool isContinues();
};
