#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#define PHANTOM_MESSAGE_IGNORED  0
#define PHANTOM_MESSAGE_HANDLED  1
#define PHANTOM_MESSAGE_CONSUMED 2

#include <graphics/Graphics.h>

#include <sstream>
#include <vector>
#include <CompileConfig.h>



namespace phantom {
    class Entity;

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
        virtual void afterCollision(Composite *other);

        template <class T>
        T* getComponentByType(int nth);

        std::vector<Composite *> *getComponents() {
            return &components;
        };

        Graphics& getGraphics() {
            return graphics;
        }

        template <class T>
        T* findAnsestor();

        friend std::ostream& operator<<(std::ostream &s, const Composite *c) {
            return s << "Composite(" << c->components.size() << ")";
        }

    public:
        const Eigen::Vector3f& getPosition();

    protected:
        Eigen::Vector3f _position;

    private:
        Composite *parent;
        std::vector<Composite*> components;
        Graphics graphics;
        Entity* _entity;
    };

    template <class T>
    T* Composite::getComponentByType(int nth) {
        std::vector<Composite*>::iterator iter;
        for (iter = this->components.begin(); iter != this->components.end(); ++iter) {
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
