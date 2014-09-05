//
//  problem5.cpp
//  281Homework4
//
//  Created by Noah Cohen on 11/22/13.
//  Copyright (c) 2013 Noah Cohen. All rights reserved.
//

#include "problem5.h"



#include <iostream>
#include <queue>
#include <string>
#include <map>


std::vector<Node *> nodes;
Node * construct(int value, Node *left, Node *right) {
    Node *test = new Node;
    nodes.push_back(test);
    
    test->left = left;
    test->right = right;
    test->value = value;
    
    return test;
}

void clean_up() {
    for (Node *n : nodes) {
        delete n;
    }
}

std::pair<Node *, Node *> flattenHelper(Node *root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            return {root, root};
        } else {
            auto left_tree = flattenHelper(root->left);
            auto right_tree = flattenHelper(root->right);
            
            if (left_tree.first == NULL) {
                root->left = NULL;
                left_tree.first = root;
            } else {
                left_tree.second->right = root;
                root->left = left_tree.second;
            }
            
            if (right_tree.first == NULL) {
                root->right = NULL;
                right_tree.second = root;
            } else {
                right_tree.first->left = root;
                root->right = right_tree.first;
            }
            
            return {left_tree.first, right_tree.second};
        }
    }
    return {NULL, NULL};
}

void printList(Node *left) {
    while (left != NULL) {
        std::cout << left->value << ',';
        left = left->right;
    }
}

Node * flatten(Node *root) {
    if (root) {
        return flattenHelper(root).first;
    }
    return NULL;
}

void print_in_order(Node *root) {
    if (root != NULL) {
        print_in_order(root->left);
        std::cout << root->value << ' ';
        print_in_order(root->right);
    }
}

