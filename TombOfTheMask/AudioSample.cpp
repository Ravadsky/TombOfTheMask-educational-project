#include "AudioSample.h"

AudioSample::AudioSample(std::string SoundFileName)
{
    soundBuffer.loadFromFile(RESOURCES_PATH + "Audio/" + SoundFileName + ".wav");
    sound.setBuffer(soundBuffer);
    sound.setVolume(7.f);
    sound.play();
}

bool AudioSample::isContinues()
{
    return sound.getStatus() == sf::SoundSource::Playing;
}
