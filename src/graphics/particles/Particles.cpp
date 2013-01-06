#include <pch.h>
#include "Particles.h"
#include <graphics/ImageLoader.h>
#include <graphics/ImageCache.h>


namespace phantom {
    Particles::Particles(unsigned count, string texturename, Color color, float lifetime, float speed, Vector3 scale, Vector3 direction, float density, unsigned randomness) {
        this->count = count;
        this->scale = scale;
        this->direction = direction;
        this->density = density;
        this->lifetime = lifetime;
        this->texture = nullptr;
        this->color = color;
        this->speed = speed;
        this->randomness = randomness + 1;
        this->randomnessHalf = this->randomness / 2.0f;

        ImageCache *imagecache = ImageCache::getInstance();

        if(texturename != "") {
            if(!imagecache->isCached(texturename)) {
                imagecache->insertIntoCache(texturename, ImageLoader::createPNG(texturename));
            }

            this->texture = imagecache->getFromCache(texturename);
        }
    }

    Particles::~Particles() {
        while(_particles.size() > 0) {
            delete _particles[_particles.size()-1];
            _particles.erase(_particles.end()-1);
        }
    }

    void Particles::update(const phantom::PhantomTime& time) {
        this->_currentdensity -= time.getElapsed();
        for(auto particle = _particles.begin(); particle != _particles.end();) {
            (*particle)->lifetime -= time.getElapsed();
            if((*particle)->lifetime < 0.0f) {
                delete (*particle);
                particle = _particles.erase(particle);
                createNewParticle();

                continue;
            }
            Vector3 random((float)(rand() % randomness) - randomnessHalf, (float)(rand() % randomness) - randomnessHalf, (float)(rand() % randomness) - randomnessHalf);
            random.x = random.x / 100.0f;
            random.y = random.y / 100.0f;
            random.z = random.z / 100.0f;
            (*particle)->acceleration = this->direction + random;
            (*particle)->velocity += (*particle)->acceleration * speed * time.getElapsed();
            (*particle)->position += (*particle)->velocity;

            ++particle;
        }

        if(_particles.size() < count && this->_currentdensity < 0) {
            this->_currentdensity = this->density;
            createNewParticle();
        }
    }

    void Particles::createNewParticle() {
        auto particle = new Particle();
        particle->position = Vector3(0, 0, 0);
        particle->color = this->color;
        particle->lifetime = this->lifetime;
        particle->scale = this->scale;
        _particles.push_back(particle);
    }
}