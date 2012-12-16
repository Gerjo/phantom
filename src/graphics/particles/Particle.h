#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <CompileConfig.h>
#include <graphics/VerticeData.h>
#include <graphics/Color.h>
#include <physics/Vector3.h>

namespace phantom {
    struct LIBEXPORT Particle {
        Vector3 position, velocity, acceleration, scale;
        Color color;
        float lifetime;
    };
}

#endif