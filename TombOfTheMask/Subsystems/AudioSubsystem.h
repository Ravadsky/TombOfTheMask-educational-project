#pragma once
#include "UObject.h"

#include "VectorFunctions.h"

class AudioSample;

class AudioSubsystem : public UObject
{
  private:
    sf::Music BackgroundMusic;
    std::vector<std::unique_ptr<AudioSample>> SoundSamples;

    float MusicValue;
    float SoundValue;

  public:
    AudioSubsystem();

    virtual void Update() override;

    void StartNewMusic(std::string MusicFileName);
    void CreateNewSound(std::string SoundFileName);

    void UpdateSoundAndMusicValues();
};
