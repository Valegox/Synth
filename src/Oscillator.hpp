#pragma once

struct WaveForm {
    float signal[1024];
};

class Oscillator {
public:
    float phase;
    float frequency;
    struct WaveForm waveForm;

    Oscillator() : phase(0.0f), frequency(0.0f) {};

    void updateSinWave();
};
