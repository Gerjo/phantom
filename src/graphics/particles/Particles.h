#ifndef PARTICLES_H_
#define PARTICLES_H_

#include <core/Composite.h>
#include <graphics/particles/Particle.h>

namespace phantom {
    class ImageCacheItem;

    class LIBEXPORT Particles : public Composite {
    public:
        float density;
        unsigned randomness;
        float randomnessHalf;
        unsigned count;
        float lifetime;
        float speed;
        Vector3 scale;
        Vector3 direction;
        Color color;
        ImageCacheItem *texture;

        Particles(unsigned count = 500, string texturename = "", Color color = Colors::WHITE, float lifetime = 1.5f, float speed = 5.0f, Vector3 scale = Vector3(5.0f, 5.0f, 1.0f), Vector3 direction = Vector3(0.0f, -0.5f), float density = 0.015f, unsigned randomness = 200);
        ~Particles();

        void update(const phantom::PhantomTime& time);

        vector<Particle*> *getParticles() { return &_particles; };
    
    private:
        vector<Particle*> _particles;
        float _currentdensity;

        void createNewParticle();
    };
}
#endif