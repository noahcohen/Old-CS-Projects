#pragma once

// Do not modify this file, include it in problem4.cpp

struct Node {
	int value;
	Node* left;
	Node* right;
};

Node* flatten(Node* root);
