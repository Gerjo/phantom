#include "BinaryTree.h"

namespace phantom {
    namespace tree {
        void BinaryTree::destroy() {
            destroy(_root);
        }

        void BinaryTree::destroy(BinaryNode *leaf) {
            if(leaf != nullptr) {
                if(leaf->left  != nullptr) destroy(leaf);
                if(leaf->right != nullptr) destroy(leaf);
                delete leaf;
            }
        }

        void BinaryTree::push(int key) {
            if(_root == nullptr) {
                _root        = new BinaryNode();
                _root->parent= nullptr;
                _root->key   = key;
                _root->left  = nullptr;
                _root->right = nullptr;
            }
        }

        void BinaryTree::push(int key, BinaryNode *leaf) {
            if(key < leaf->key)
            {
                if(leaf->left != nullptr)
                    push(key, leaf->left);
                else
                {
                    leaf->left         = new BinaryNode();
                    leaf->left->parent = leaf;
                    leaf->left->key    = key;
                    leaf->left->left   = nullptr;
                    leaf->left->right  = nullptr;
                }  
            }
            else if(key >= leaf->key)
            {
                if(leaf->right != nullptr)
                    push(key, leaf->right);
                else
                {
                    leaf->right         = new BinaryNode();
                    leaf->right->parent = leaf;
                    leaf->right->key    = key;
                    leaf->right->left   = nullptr;
                    leaf->right->right  = nullptr;
                }
            }
        }

        BinaryNode *BinaryTree::find(int key) {
            return find(key, _root);
        }

        BinaryNode *BinaryTree::find(int key, BinaryNode *leaf) {
            if(leaf != nullptr) {
                if(key == leaf->key) {
                    return leaf;
                }
                else if(key < leaf->key) {
                    return find(key, leaf->left);
                }
                else {
                    return find(key, leaf->right);
                }
            }
            else{
                return nullptr;
            }
        }

        void BinaryTree::erase(int key) {
            erase(key, _root);
        }

        void BinaryTree::erase(int key, BinaryNode *leaf) {
            BinaryNode *node = find(key, leaf);
            
            if(node == nullptr)
                return;

            if(node == _root) {
                _root = _root->left;
            }
            else
                return;

            if(node == node->parent->left) {
                node->parent->left = node->left;
            }
            
            else if(node == node->parent->right) {
                node->parent->right = node->left;
            }

            delete node;
        }
    }
}
