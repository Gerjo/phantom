#ifndef NODE_H_
#define NODE_H_

#include <CompileConfig.h>
#include <vector>

namespace phantom {
    namespace tree {
        class LIBEXPORT BinaryNode {
        public:
            int         key;
            void        *data;
            BinaryNode  *parent;
            BinaryNode  *left;
            BinaryNode  *right;
        };
    }
}

#endif