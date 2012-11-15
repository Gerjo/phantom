#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <utils/tree/BinaryNode.h>
#include <CompileConfig.h>

namespace phantom {
    namespace tree {
        class LIBEXPORT BinaryTree {
        public:
            BinaryTree () { _root = nullptr; }
            ~BinaryTree() { destroy();       }

            void        push    (int key);
            BinaryNode  *find   (int key);
            void        erase   (int key);
            void        destroy ();

        private:
            BinaryNode *_root;

            void        push    (int key, BinaryNode *leaf);
            BinaryNode  *find   (int key, BinaryNode *leaf);
            void        erase   (int key, BinaryNode *leaf);
            void        destroy (BinaryNode *leaf);
        };
    }
}

#endif