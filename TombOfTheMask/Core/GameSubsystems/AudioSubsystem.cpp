#include "AudioSubsystem.h"

#include "Audio/AudioSample.h"
#include "Core/FunctionLibrary/DataFunctions.h"

UAudioSubsystem::UAudioSubsystem() : UGameSubsystem() {}

void UAudioSubsystem::BeginPlay()
{
    UpdateSoundAndMusicValues();
}

void UAudioSubsystem::Update()
{
    auto isSampleEnds = [](const auto& sample) { return !sample->isContinues(); };
    SoundSamples.erase(std::remove_if(SoundSamples.begin(), SoundSamples.end(), isSampleEnds), SoundSamples.end());
}

void UAudioSubsystem::StartNewMusic(std::string MusicFileName)
{
    assert(BackgroundMusic.openFromFile(RESOURCES_PATH + "Audio/" + MusicFileName + ".wav"));
    BackgroundMusic.setLoop(true);
    BackgroundMusic.setVolume(MusicValue);
    BackgroundMusic.play();
}

void UAudioSubsystem::CreateNewSound(std::string SoundFileName)
{
    SoundSamples.emplace_back(std::make_unique<AudioSample>(SoundFileName, SoundValue));
}

void UAudioSubsystem::UpdateSoundAndMusicValues()
{
    MusicValue = GetDataParameter("MusicValue:") * 1.f;
    SoundValue = GetDataParameter("SoundValue:") * 1.f;
    BackgroundMusic.setVolume(MusicValue);
}
