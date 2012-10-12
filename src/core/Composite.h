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

    class LIBEXPORT Composite {
    public:
        unsigned int flags;
        bool destroyed;

        Composite();
        virtual ~Composite();

        virtual void onAdd(Composite *parent);
        virtual void onAnsestorChanged();

        virtual void addComponent      (Composite *component);
        virtual bool removeComponent   (Composite *component);
        virtual bool destroyComponent  (Composite *component);
        virtual bool destroyComponentAt(size_t index);

        virtual unsigned int handleMessage(const char *message, void *data);

        virtual void update    (const float& elapsed);
        virtual void intergrate(const float& elapsed);

        virtual bool canCollideWith(Composite *other);
        virtual void onCollision(Composite *other);

        template <class T>
        T* getComponentByType(int nth);

        std::vector<Composite*>& getComponents() {
            return _components;
        };

        Box3& getBoundingBox() {
            _boundingBox.origin = getPosition();
            return _boundingBox;
        }

        void setBoundingBox(const Box3& boundingBox) {
            _boundingBox = boundingBox;
        }

        Graphics& getGraphics() {
            return *graphics;
        }

        template <class T>
        T* findAnsestor();

        Vector3 getPosition();
        void setPosition(Vector3 position);
        void addPosition(const Vector3& add);
        void removePosition(const Vector3& subtract);

        const string& getType();
        bool isType(const string& type);
        string toString(void);

        PhantomGame* getGame(void);
    protected:
        Vector3 _position;
        Box3 _boundingBox;

        void setType(const string& type);
        Driver* getDriver(void);
    private:
        Composite *parent;
        std::vector<Composite*> _components;
        Graphics *graphics;
        
        Entity* _entity;
        string _type;
    };

    template <class T>
    T* Composite::getComponentByType(int nth) {
        std::vector<Composite*>::iterator iter;
        for (iter = this->_components.begin(); iter != this->_components.end(); ++iter) {
            T* c = dynamic_cast<T*> (*iter);
            if (c != NULL) {
                if (nth == 0)
                    return c;
                else
                    --nth;
            }
        }
        return NULL;
    }

    template <class T>
    T* Composite::findAnsestor() {
        Composite *c = this->parent;
        while (c != NULL) {
            T* tc = dynamic_cast<T*> (c);
            if (tc != NULL)
                return tc;
            c = c->parent;
        }
        return NULL;
    }

}

#endif /* COMPOSITE_H_ */
