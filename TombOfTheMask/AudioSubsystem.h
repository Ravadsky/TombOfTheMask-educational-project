#pragma once
#include "UObject.h"
#include <vector>
#include "AudioSample.h"

class AudioSubsystem : public UObject
{
  private:
    sf::Music BackgroundMusic;
    std::vector<std::unique_ptr<AudioSample>> SoundSamples;

    public:
    AudioSubsystem();

    void Update() override;

    void StartNewMusic(std::string MusicFileName);
    void CreateNewSound(std::string SoundFileName);
};
