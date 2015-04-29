#include <ctype.h> // for 'isdigit()'
#include "Tree.h"
#include "Stack.h"

char token; // variable for reading a charactor
Root *root;
Stack *st;

void GotError()
{
	puts("error found.\nplease check your input message.");
	exit(1);
}

void CheckAndGetChar(char tmp)
{
	if(tmp != token){
		GotError();
	}
	token = getchar();
}
double term();
double sum();
double factor();

/** main function
 *
 */
int main()
{
	double value;
	StackNode tmp;
	TreeNode *tn = NULL;
	/// make data structures for each cases
	root = make_root_node();
	st = make_stack();

	/// process
    token = getchar();
    value = sum();
	// now, stack is already built

	/// construct tree
	while(!isEmpty_stack(st))
	{
		// As the stack is being removed, constructs tree
		tmp = pop(st);
		while(tmp.isChar)
		{
			// operator
			tn = make_child(tn, tmp.data, tmp.isChar);
			if(root->root == NULL)	root->root = tn;
			tmp = pop(st);
		}
		// number
		tn = make_child(tn, tmp.data, tmp.isChar);
		if(root->root == NULL)	root->root = tn;
	}
    /// printing
    printf("prefix : ");
    traversal(root, PREORDER);
    puts("");
    printf("infix : ");
    traversal(root, INORDER);
    puts("");
    printf("postfix : ");
    traversal(root, POSTORDER);
    puts("");
    printf("Evaluation result : %g\n", value);

    /// delete
    remove_all_tree_nodes(root);
    return 0;
}

/** \brief
 * push data in the stack with the method of post-fix
 * calculate addition and subtraction
 */
double sum()
{
	double temp = term();
	Data datum;
	while(token == '+' || token == '-')
	{
		if(token == '+')
		{
			datum.opr = '+';
			CheckAndGetChar('+');
			temp += term();
			push(st, datum, TRUE);
		}
		else if(token == '-')
		{
			datum.opr = '-';
			CheckAndGetChar('-');
			temp -= term();
			push(st, datum, TRUE);
		}
	}
	return temp;
}

/** \brief
 * push data in the stack with the method of post-fix
 * calculate multiple and devision
 */
double term()
{
	double temp = factor();
	Data datum;
	while(token == '*' || token == '/')
	{
		if(token == '*')
		{
			datum.opr = '*';
			CheckAndGetChar('*');
			temp *= factor();
			push(st, datum, TRUE);
		}
		else if(token == '/')
		{
			datum.opr = '/';
			CheckAndGetChar('/');
			temp /= factor();
			push(st, datum, TRUE);
		}
	}
	return temp;
}

/** \brief
 * push data in the stack with the method of post-fix
 * regards factor as a number
 */
double factor()
{
	double temp = 0.0;
	Data datum;
	if(token == '(')
	{
		// start with new sum again
		CheckAndGetChar('(');
		temp = sum();
		CheckAndGetChar(')');
	}
	else if(token == '-')
	{
		// negation
		CheckAndGetChar('-');
		datum.opr = '-';
		temp = -factor();
		push(st, datum, TRUE);
		return temp;
	}
	else if(token == '+')
	{
		// there is no meaning, but just exception dealing
		CheckAndGetChar('+');
		return factor();
	}
	else if(isdigit(token))
	{
		ungetc(token, stdin);
		scanf("%lf", &temp);
		datum.num = temp;
		push(st, datum, FALSE);
		token = getchar();
	}
	else GotError();
	return temp;
}
