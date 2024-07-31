#include <cmath>
#include <numbers>
#include <iostream>
#include "Oscillator.hpp"
#include "Constants.hpp"

void Oscillator::updateSinWave() {
    for (int t = 0; t < 1024; t++) {
        this->phase += frequency * SAMPLE_DURATION;
        if (this->phase >= 1.0f) {
            this->phase -= 1.0f;
        }
        waveForm.signal[t] = sinf(2.0f * PI * this->phase);
    }
}
