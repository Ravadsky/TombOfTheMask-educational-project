#include "AudioSubsystem.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"
#include "Core/DataFunctions.h"

AudioSample::AudioSample(std::string SoundFileName, float value)
{
    sound.setBuffer(GetResourceSubsystem()->GetSoundBuffer(SoundFileName));
    sound.setVolume(value);
    sound.play();
}

bool AudioSample::isContinues()
{
    return sound.getStatus() == sf::SoundSource::Playing;
}

UAudioSubsystem::UAudioSubsystem() : UGameSubsystem() {}

void UAudioSubsystem::BeginPlay()
{
    UpdateSoundAndMusicValues();
}

void UAudioSubsystem::Update(float deltaTime)
{
    auto isSampleEnds = [](const auto& sample) { return !sample->isContinues(); };
    SoundSamples.erase(std::remove_if(SoundSamples.begin(), SoundSamples.end(), isSampleEnds), SoundSamples.end());
}

void UAudioSubsystem::StartNewMusic(std::string MusicFileName)
{
    assert(BackgroundMusic.openFromFile(RESOURCES_PATH + "Audio/" + MusicFileName + ".wav"));
    BackgroundMusic.setLoop(true);
    BackgroundMusic.setVolume(MusicValue * 10.0f);
    BackgroundMusic.play();
}

void UAudioSubsystem::PlaySound(std::string soundName)
{
    SoundSamples.emplace_back(std::make_unique<AudioSample>(soundName, SoundValue));
}

void UAudioSubsystem::UpdateSoundAndMusicValues()
{
    MusicValue = GetDataParameter("MusicValue:") * 10.f;
    SoundValue = GetDataParameter("SoundValue:") * 10.f;
    BackgroundMusic.setVolume(MusicValue * 10);
}
