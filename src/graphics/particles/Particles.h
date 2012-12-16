#ifndef PARTICLES_H_
#define PARTICLES_H_

#include <core/Composite.h>
#include <graphics/particles/Particle.h>

namespace phantom {
    class ImageCacheItem;

    class LIBEXPORT Particles : public Composite {
    public:
        float density;
        unsigned count;
        float lifetime;
        float speed;
        Vector3 scale;
        Color color;
        ImageCacheItem *texture;

        Particles(unsigned count = 100, string texturename = "", Color color = Colors::WHITE, float lifetime = 0.5f, float speed = 50.0f, Vector3 scale = Vector3(1.0f, 1.0f, 1.0f), float density = 1.0f);
        ~Particles();

        void update(const phantom::PhantomTime& time);

        vector<Particle*> getParticles() { return _particles; };
    
    private:
        vector<Particle*> _particles;

        void createNewParticle();
    };
}
#endif