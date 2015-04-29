#include "Tree.h"

Root* make_root_node()
{
	Root* tmp = (Root*)calloc(sizeof(Root), 1);
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

TreeNode* make_tree_node()
{
	TreeNode* tmp = (TreeNode*)calloc(sizeof(TreeNode), 1);
	if(!tmp){
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

/** \brief
 *
 * \param pare_node : parent node
 * \param datum : input data1
 * \param isChar : input data2
 * \return self node or new child node
 *
 */
TreeNode* make_child(TreeNode *pare_node, Data datum, int isChar)
{
	if(!pare_node)
	{
		pare_node = make_tree_node();
		pare_node->data = datum;
		pare_node->isChar = isChar;
		return pare_node;
	}
	if(pare_node->left && pare_node->right)
	{
		pare_node = pare_node->parent;
		if(!pare_node)	return NULL;
		return make_child(pare_node, datum, isChar);
	}

	if(!isChar) // number, from right. return self node pointer.
	{
		if(pare_node->right)
		{
			make_left_child(pare_node, datum, isChar);
		}
		else
		{
			make_right_child(pare_node, datum, isChar);
		}
		return pare_node;
	}
	else // operator, from left. return its child node pointer.
	{

		if(pare_node->left)
		{
			make_right_child(pare_node, datum, isChar);
			return pare_node->right;
		}
		else
		{
			make_left_child(pare_node, datum, isChar);
			return pare_node->left;
		}
	}
}

void make_left_child(TreeNode *pare_node, Data datum, int isChar)
{
	TreeNode* tmp = make_tree_node();
	if(!tmp)	return;
	tmp->data = datum;
	tmp->isChar = isChar;
	pare_node->left = tmp;
	tmp->parent = pare_node;
}

void make_right_child(TreeNode *pare_node, Data datum, int isChar)
{
	TreeNode* tmp = make_tree_node();
	if(!tmp)	return;
	tmp->data = datum;
	tmp->isChar = isChar;
	pare_node->right = tmp;
	tmp->parent = pare_node;
}

void print_data(Data datum, int isChar)
{
	if(isChar) {
		printf("%c", datum.opr);
	}
	else {
		printf("%g", datum.num);
	}
}

void traversal(Root *root, int mode)
{
	TreeNode *tmp = root->root;
	switch(mode)
	{
		case PREORDER:
			preorder_traversal(tmp);
			break;
		case INORDER:
			inorder_traversal(tmp);
			break;
		case POSTORDER:
			postorder_traversal(tmp);
			break;
	}
}

void preorder_traversal(TreeNode *tNode)
{
	if(!tNode)	return;
	print_data(tNode->data, tNode->isChar);
	preorder_traversal(tNode->left);
	preorder_traversal(tNode->right);
}

void inorder_traversal(TreeNode *tNode)
{
	if(!tNode)	return;
	inorder_traversal(tNode->left);
	print_data(tNode->data, tNode->isChar);
	inorder_traversal(tNode->right);
}

void postorder_traversal(TreeNode *tNode)
{
	if(!tNode)	return;
	postorder_traversal(tNode->left);
	postorder_traversal(tNode->right);
	print_data(tNode->data, tNode->isChar);
}

void remove_tree_node(TreeNode *tNode)
{
	if(!tNode)	return;
	remove_tree_node(tNode->left);
	remove_tree_node(tNode->right);
	free(tNode);
}

void remove_all_tree_nodes(Root* root)
{
	remove_tree_node(root->root);
}
