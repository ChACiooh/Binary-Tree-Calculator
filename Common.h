#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

/// this header file is consisting of common things

#include <stdlib.h>
#include <stdio.h>

#define PREORDER	0
#define INORDER		1
#define POSTORDER	2

#define TRUE		1
#define FALSE	 	0

typedef union
{
	double num;
	char opr;
} Data;

const static Data dummy_data = {0};

#endif // COMMON_H_INCLUDED
