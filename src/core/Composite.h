#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <graphics/Graphics.h>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <CompileConfig.h>
#include <physics/Box3.h>
#include <messaging/MessageState.h>
#include <messaging/Message.h>
#include <messaging/AbstractMessage.h>
#include <messaging/IHandleMessage.h>
#include <utils/Time.h>

using namespace std;

namespace phantom {
    class Entity;
    class PhantomGame;
    class Driver;
    class Layer;

    class LIBEXPORT Composite : public IHandleMessage {
    public:
        bool isStatic;

        Composite();
        virtual ~Composite();

        // Ancestor related functions.
        virtual void onParentChange(Composite *parent);
        virtual void onAnsestorChanged();
        virtual void onLayerChanged(Layer* layer);
        Composite* getParent();
        PhantomGame* getPhantomGame(void);
        template <class T> T getGame(void) {
            return static_cast<T>(getPhantomGame());
        }

        // Composite related functions.
        virtual void addComponent(Composite *component);
        std::vector<Composite*>& getComponents();
        // If you are calling these two from your game, consider using:
        // - removeFromParent();
        // - destroy();
        // Calling "removeComponent" directly may or may not work, depending
        // on cosmic radiation and the alignment of the stars.
        virtual void removeComponent(Composite* who);
        virtual void destroyComponent(Composite* who);
        virtual void destroy(void);
        virtual void removeFromParent(void);
        template <class T> T* findAnsestor();
        template <class T> T* getComponentByType(int nth);
        bool isDestroyed();

        // Iteration based events.
        virtual MessageState handleMessage(AbstractMessage* message);
        virtual void update(const PhantomTime& time);
        Graphics& getGraphics();

        // Physics related
        virtual bool canCollideWith(Composite *other);
        virtual void onCollision(Composite *other);
        Box3& getBoundingBox();
        void setBoundingBox(const Box3& boundingBox);
        Vector3 getPosition();
        virtual void setPosition(Vector3 position);
        virtual void setX(float x);
        virtual void setY(float y);
        virtual void addPosition(const Vector3& add);
        virtual void removePosition(const Vector3& subtract);
        virtual void setDirection(Vector3 direction);

        // General
        const string& getType() const;
        bool isType(const string& type) const;
        bool isType(const Composite& other) const;
        bool isType(const Composite* other) const;

        string toString(void);
        Layer* getLayer();
    protected:
        Vector3 _position;
        Vector3 _direction;
        Box3 _boundingBox;
        Layer* _layer;
        void setType(const string& type);
        Driver* getDriver(void);
        Composite *_parent;

    private:
        std::vector<Composite*> _components;
        std::vector<Composite*> _componentsBuffer;

        Graphics _graphics;
        string _type;

        bool _remove;
        bool _destroy;
        bool _isUpdating;
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
