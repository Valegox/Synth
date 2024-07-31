#include <iostream>
#include "raylib.h"
#include "Oscillator.hpp"
#include "Constants.hpp"

int main() {
    const int screenWidth = 1024;
    const int screenHeight = 768;
    InitWindow(screenWidth, screenHeight, "Synth");
    SetTargetFPS(60);
    InitAudioDevice();
    SetMasterVolume(0.25f);

    Oscillator osc = Oscillator();

    SetAudioStreamBufferSizeDefault(STREAM_BUFFER_SIZE);
    AudioStream synthStream = LoadAudioStream(SAMPLE_RATE, 32, 1);

    SetAudioStreamVolume(synthStream, 0.05f);
    PlayAudioStream(synthStream);

    while (!WindowShouldClose()) {
        if (IsAudioStreamProcessed(synthStream)) {
            osc.updateSinWave();
            UpdateAudioStream(synthStream, osc.waveForm.signal, STREAM_BUFFER_SIZE);
            osc.frequency += 5.0f;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("Synth (freq: %f)", osc.frequency), 100, 100, 20, RED);
        for (size_t i = 0; i < 1024; i++) {
            DrawPixel(i, (728/2) + (int)(osc.waveForm.signal[i] * 100), RED);
        }
        EndDrawing();
    }
    UnloadAudioStream(synthStream);
    CloseAudioDevice();
    CloseWindow();
}
