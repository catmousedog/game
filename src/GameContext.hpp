#pragma once

struct GameTime
{
    // lag/overshoot times
    float lagUpdate;
    float lagRender;

    // actual update times
    float sfml;
    float update;
    float render;
};