#ifndef LAYER_H_
#define LAYER_H_

#include <utils/PhantomException.h>
#include <core/Composite.h>
#include <CompileConfig.h>
#include <iostream>

using namespace std;

namespace phantom {

    class LIBEXPORT Layer : public Composite {
    public:
        Layer(void);
        void addComponent(Composite* component);
        virtual void disposeObjects();

        friend class Composite;
    private:
        vector<Composite*> _disposables;
        void dispose(Composite* composite);

    };

} /* namespace phantom */
#endif /* LAYER_H_ */
