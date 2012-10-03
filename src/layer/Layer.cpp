#include "Layer.h"

#include <core/PhantomGame.h>

namespace phantom {

    Layer::Layer(float width, float height) : width(width), height(height)
    {
    }

    Layer::~Layer()
    {
    }

    void Layer::onAdd( Composite *parent )
    {
        Composite::onAdd(parent);
        this->state = dynamic_cast<GameState*>(parent);
    }

    void Layer::onAnsestorChanged()
    {
        Composite::onAnsestorChanged();
        if( this->width == 0 || this->height == 0 )
        {
            PhantomGame *game = this->findAnsestor<PhantomGame>();
            if( game != NULL )
            {
                if( this->width == 0 )
                    this->width = static_cast<float>(game->getWidth());
                if( this->height == 0 )
                    this->height = static_cast<float>(game->getHeight());
            }
        }
    }
    float Layer::getWidth(){
        return width;
    }
    float Layer::getHeight(){
        return height;
    }

} /* namespace phantom */
