#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <algorithm>

namespace forest {
        namespace binary_search_tree {
                template <typename key_t>
                struct node {
                        key_t key;
                        node *parent;
                        node *left;
                        node *right;
                        node(key_t key) {
                                this->key = key;
                                this->parent = nullptr;
                                this->left = nullptr;
                                this->right = nullptr;
                        }
                        void info() {
                                std::cout << this->key << "\t";
                                if (this->left != nullptr) {
                                        std::cout << this->left->key << "\t";
                                } else {
                                        std::cout << "null" << "\t";
                                }
                                if (this->right != nullptr) {
                                        std::cout << this->right->key << "\t";
                                } else {
                                        std::cout << "null" << "\t";
                                }
                                if (this->parent != nullptr) {
                                        std::cout << this->parent->key << std::endl;
                                } else {
                                        std::cout << "null" << std::endl;
                                }
                        }
                };
                template <typename key_t>
                class tree {
                private:
                        node <key_t> *root;
                        void pre_order_traversal(node <key_t> *x) {
                                if (x == nullptr) return;
                                x->info();
                                pre_order_traversal(x->left);
                                pre_order_traversal(x->right);
                        }
                        void in_order_traversal(node <key_t> *x) {
                                if (x == nullptr) return;
                                in_order_traversal(x->left);
                                x->info();
                                in_order_traversal(x->right);
                        }
                        void post_order_traversal(node <key_t> *x) {
                                if (x == nullptr) return;
                                post_order_traversal(x->left);
                                post_order_traversal(x->right);
                                x->info();
                        }
                        unsigned long long height(node <key_t> *x) {
                                unsigned long long tree_height = 0;
                                if (x != nullptr) {
                                        unsigned long long left_height = height(x->left);
                                        unsigned long long right_height = height(x->right);
                                        tree_height = std::max(left_height, right_height) + 1;
                                }
                                return tree_height;
                        }
                public:
                        tree() {
                                root = nullptr;
                        }
                        ~tree() {

                        }
                        void pre_order_traversal() {
                                pre_order_traversal(root);
                        }
                        void in_order_traversal() {
                                in_order_traversal(root);
                        }
                        void post_order_traversal() {
                                post_order_traversal(root);
                        }
                        void insert(key_t key) {
                                node <key_t> *current = root;
                                node <key_t> *previous = nullptr;
                                while(current!=nullptr) {
                                        previous = current;
                                        if (key > current->key) {
                                                current = current->right;
                                        } else if (key < current->key) {
                                                current = current->left;
                                        }
                                }
                                current = new node <key_t> (key);
                                current->parent = previous;
                                if(previous == nullptr) {
                                        root = current;
                                } else if (current->key > previous->key) {
                                        previous->right = current;
                                } else if (current->key < previous->key) {
                                        previous->left = current;
                                }
                        }
                        bool contains(key_t key) {
                                return (search(key) != nullptr) ? true : false;
                        }
                        node <key_t> *search(key_t key) {
                                node <key_t> *x = root;
                                while (x != nullptr) {
                                        if (key > x->key) {
                                                x = x->right;
                                        } else if (key < x->key) {
                                                x = x->left;
                                        } else {
                                                return x;
                                        }
                                }
                                return nullptr;
                        }
                        node <key_t> *minimum() {
                                node <key_t> *x = root;
                                while(x->left != nullptr) x = x->left;
                                return x;
                        }
                        node <key_t> *maximum() {
                                node <key_t> *x = root;
                                while(x->right != nullptr) x = x->right;
                                return x;
                        }
                        unsigned long long height() {
                                return height(root);
                        }
                };
        }
}

#endif