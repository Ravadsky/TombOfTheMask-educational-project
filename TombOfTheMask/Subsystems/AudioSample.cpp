#include "AudioSample.h"

AudioSample::AudioSample(std::string SoundFileName, float value)
{
    soundBuffer.loadFromFile(RESOURCES_PATH + "Audio/" + SoundFileName + ".wav");
    sound.setBuffer(soundBuffer);
    sound.setVolume(value);
    sound.play();
}

bool AudioSample::isContinues()
{
    return sound.getStatus() == sf::SoundSource::Playing;
}
