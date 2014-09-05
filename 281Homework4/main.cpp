//
//  main.cpp
//  281Homework4
//
//  Created by Noah Cohen on 11/21/13.
//  Copyright (c) 2013 Noah Cohen. All rights reserved.
//

#include "problem5.cpp"
#include <iostream>
int main(int argc, const char * argv[]) {
    
    Node *node_1 = construct(1, NULL, NULL);
    Node *node_2 = construct(2, NULL, NULL);
    Node *node_4 = construct(4, NULL, NULL);
    Node *node_5 = construct(5, NULL, NULL);
    Node *node_6 = construct(6, NULL, NULL);
    
    node_4->left = node_2;
    node_4->right = node_6;
    
    node_2->left = node_1;
    
    node_6->left = node_5;
    
    //std::cout << flatten(node_4) << std::endl;
    
    clean_up();

     return 0;
}