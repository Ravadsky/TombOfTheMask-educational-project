#include "AudioSubsystem.h"

#include "AudioSample.h"
#include "DataFunctions.h"

AudioSubsystem::AudioSubsystem()
{
    UpdateSoundAndMusicValues();
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
    BackgroundMusic.setVolume(MusicValue);
    BackgroundMusic.play();
}

void AudioSubsystem::CreateNewSound(std::string SoundFileName)
{
    SoundSamples.emplace_back(std::make_unique<AudioSample>(SoundFileName, SoundValue));
}

void AudioSubsystem::UpdateSoundAndMusicValues()
{
    MusicValue = GetDataParameter("MusicValue:") * 1.f;
    SoundValue = GetDataParameter("SoundValue:") * 1.f;
    BackgroundMusic.setVolume(MusicValue);
}
