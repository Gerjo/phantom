#ifndef PARTICLES_H_
#define PARTICLES_H_

#include <core/Composite.h>
#include <graphics/particles/Particle.h>

namespace phantom {
    class ImageCacheItem;

    class LIBEXPORT Particles : public Composite {
    public:
        float           density;
        unsigned        randomness;
        float           randomnessHalf;
        unsigned        count;
        float           lifetime;
        float           currentLifetime;
        float           totalLifetime;
        float           speed;
        Vector3         scale;
        Vector3         direction;
        Color           color;
        ImageCacheItem  *texture;

        /**
        * This large constructor has to be called to create particles.
        *
        * @param count The ammount of particles to be active at most.
        * @param texturename The image you want the particles to have.
        * @param color The color you want the particles to have.
        * @param lifetime The lifetime of each particle.
        * @param totalLifetime The lifetime of all particles. -1.0f means there is no end of life.
        * @param speed The movement speed of the particles.
        * @param scale The scale of the particles.
        * @param direction The direction the particles should move.
        * @param density The spread of the particles.
        * @param randomness How random the particles should act.
        */
        Particles(unsigned count = 500, 
            string texturename = "",
            Color color = Colors::WHITE,
            float lifetime = 1.5f,
            float totalLifetime = -1.0f,
            float speed = 5.0f,
            Vector3 scale = Vector3(5.0f, 5.0f, 1.0f),
            Vector3 direction = Vector3(0.0f, -0.5f),
            float density = 0.015f,
            unsigned randomness = 200);
        ~Particles();

        void update(const phantom::PhantomTime& time);

        /**
        * Returns the particles that are currently active.
        *
        * @return Returns the particles that are currently active.
        */
        vector<Particle*> *getParticles() { return &_particles; };
    
    private:
        vector<Particle*> _particles;
        float _currentdensity;

        void createNewParticle();
    };
}
#endif