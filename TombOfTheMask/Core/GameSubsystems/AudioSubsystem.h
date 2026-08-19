#pragma once
#include "GameSubsystem.h"

class AudioSample : public UObject
{
private:
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;

public:
    AudioSample(std::string SoundFileName, float value);

    bool isContinues();
};


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
    virtual void Update(float deltaTime) override;

    void StartNewMusic(std::string MusicFileName);
    void PlaySound(std::string soundName);

    void UpdateSoundAndMusicValues();
};
