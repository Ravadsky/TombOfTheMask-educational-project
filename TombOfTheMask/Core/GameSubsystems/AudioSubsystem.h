#pragma once
#include "GameSubsystem.h"

class AudioSample;

class UAudioSubsystem : public UGameSubsystem
{
private:
    sf::Music BackgroundMusic;
    std::vector<std::unique_ptr<AudioSample>> SoundSamples;

    float MusicValue;
    float SoundValue;

public:
    UAudioSubsystem();

    virtual void BeginPlay() override;
    virtual void Update() override;

    void StartNewMusic(std::string MusicFileName);
    void CreateNewSound(std::string SoundFileName);

    void UpdateSoundAndMusicValues();
};
