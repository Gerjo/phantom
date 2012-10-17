#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#define PHANTOM_MESSAGE_IGNORED  0
#define PHANTOM_MESSAGE_HANDLED  1
#define PHANTOM_MESSAGE_CONSUMED 2

#include <graphics/Graphics.h>
#include <sstream>
#include <vector>
#include <string>
#include <CompileConfig.h>
#include <physics/Box3.h>

using namespace std;

namespace phantom {
    class Entity;
    class PhantomGame;
    class Driver;
    class Layer;

    class LIBEXPORT Composite {
    public:
        Composite();
        virtual ~Composite();

        virtual void onParentChange(Composite *parent);
        virtual void onAnsestorChanged();
        virtual void onLayerChanged(Layer* layer);
        virtual void addComponent(Composite *component);
        virtual bool removeComponent(Composite *component);
        virtual bool destroyComponent(Composite *component);
        virtual unsigned int handleMessage(const char *message, void *data);
        virtual void update(const float& elapsed);
        virtual void intergrate(const float& elapsed);
        virtual bool canCollideWith(Composite *other);
        virtual void onCollision(Composite *other);

        std::vector<Composite*>& getComponents();
        Box3& getBoundingBox();
        void setBoundingBox(const Box3& boundingBox);
        Graphics& getGraphics();
        Vector3 getPosition();
        void setPosition(Vector3 position);
        void addPosition(const Vector3& add);
        void removePosition(const Vector3& subtract);
        const string& getType();
        bool isType(const string& type);
        string toString(void);
        PhantomGame* getGame(void);

        template <class T>
        T* findAnsestor();

        template <class T>
        T* getComponentByType(int nth);

        void destroy(void);
    protected:
        Vector3 _position;
        Box3 _boundingBox;
        Layer* _layer;
        void setType(const string& type);
        Driver* getDriver(void);

    private:
        Composite *_parent;
        std::vector<Composite*> _components;
        Graphics *_graphics;
        bool _destroyed;
        string _type;
    };

    template <class T>
    T* Composite::getComponentByType(int nth) {
        for (auto iter = this->_components.begin(); iter != this->_components.end(); ++iter) {
            T* c = dynamic_cast<T*> (*iter);
            if (c != 0) {
                if (nth == 0)
                    return c;
                else
                    --nth;
            }
        }
        return 0;
    }

    template <class T>
    T* Composite::findAnsestor() {
        Composite *c = this->_parent;
        while (c != 0) {
            T* tc = dynamic_cast<T*> (c);
            if (tc != 0)
                return tc;
            c = c->_parent;
        }
        return 0;
    }

}

#endif /* COMPOSITE_H_ */
