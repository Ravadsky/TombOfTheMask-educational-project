#include "AudioSubsystem.h"
#include "assert.h"

AudioSubsystem::AudioSubsystem()
{
}

void AudioSubsystem::Update()
{
    auto isSampleEnds = [](const auto &sample) { return !sample->isContinues(); };
    SoundSamples.erase(std::remove_if(SoundSamples.begin(), SoundSamples.end(), isSampleEnds), SoundSamples.end());
}

void AudioSubsystem::StartNewMusic(std::string MusicFileName)
{
    assert(BackgroundMusic.openFromFile(RESOURCES_PATH + "Audio/" + MusicFileName + ".wav"));
    BackgroundMusic.setLoop(true);
    BackgroundMusic.setVolume(10.f);
    BackgroundMusic.play();
}

void AudioSubsystem::CreateNewSound(std::string SoundFileName)
{
    SoundSamples.emplace_back(std::make_unique<AudioSample>(SoundFileName));
}
