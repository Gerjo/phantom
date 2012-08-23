/*
 * Graphics.cpp
 *
 *  Created on: Aug 23, 2012
 *      Author: koen
 */

#include <graphics/Graphics.h>
#include <core/PhantomGame.h>
#include <iostream>

namespace phantom
{

void Graphics::onAdd( Composite *parent )
{
    PhantomGame *game = dynamic_cast<PhantomGame*>(parent);
    if( game == NULL )
    {
        std::cerr << "Graphics need to be added to a PhantomGame" << std::endl;
        exit(1);
    }
    this->setup( game );

}

} /* namespace phantom */
