#include "Particles.h"
#include <graphics/ImageLoader.h>
#include <graphics/ImageCache.h>


namespace phantom {
    Particles::Particles(unsigned count, string texturename, Color color, float lifetime, float speed, Vector3 scale, float density) {
        this->count = count;
        this->scale = scale;
        this->density = density;
        this->lifetime = lifetime;
        this->texture = nullptr;
        this->color = color;

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

            (*particle)->acceleration = Vector3(1.0f, 0.0f);
            (*particle)->velocity += (*particle)->acceleration;
            (*particle)->position += (*particle)->velocity * time.getElapsed();

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