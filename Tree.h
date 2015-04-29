#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "Common.h"

typedef struct TreeNode
{
	int isChar;
	Data data;
	struct TreeNode *parent;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct Root
{
	TreeNode *root;
} Root;

Root* make_root_node();
TreeNode* make_tree_node();
TreeNode* make_child(TreeNode *pare_node, Data datum, int isChar);
void make_left_child(TreeNode *pare_node, Data datum, int isChar);
void make_right_child(TreeNode *pare_node, Data datum, int isChar);
void print_data(Data datum, int isChar);
void traversal(Root *root, int mode);
void preorder_traversal(TreeNode *tNode);
void inorder_traversal(TreeNode *tNode);
void postorder_traversal(TreeNode *tNode);
void remove_all_tree_nodes(Root* root);
void remove_tree_node(TreeNode *tNode);
#endif // TREE_H_INCLUDED
