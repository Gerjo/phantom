#ifndef ENTITY_H_
#define ENTITY_H_

#include <Eigen/Geometry>
#include <core/Composite.h>


namespace phantom {
    class Tile;
    class ObjectLayer;
    class Mover;
    class Shape;

    class LIBEXPORT Entity : public Composite {
    public:
        Entity();
        ObjectLayer* objectLayer;

        virtual void addComponent(Composite *component);

        void setX(float x);
        void setY(float y);
        void setTile(Tile* tile);
        void removeTile();
        Tile* getTile();
        bool hasTile();

    protected:
        Mover *mover;
        Shape *shape;
        Tile* _tile;

    };

} /* namespace phantom */
#endif /* ENTITY_H_ */
