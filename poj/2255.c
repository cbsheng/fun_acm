#include <stdio.h>
#include <stdlib.h>
typedef struct treenode
{
	char    data;
	struct treenode   *lchild;
	struct treenode   *rchild;
} Node, *PNode;

char     preorder[28];
char     infix[28];
char    *Pr;

void build(char *in, char *pr, PNode *tr);
void postordertraversal(PNode T);
int main()
{
	PNode    T;
	
	while(scanf("%s %s", &preorder[1], &infix[1]) == 2)
	{
		build(&infix[1], &preorder[1], &T);
		postordertraversal(T);
		printf("\n");
	}
	return    0;
}

void build(char *in, char *pr, PNode *tr)
{
	char    *p = in;
	Pr = pr;
	if (*in == 0)
	{
		*tr = NULL;
		return;
	}
	while (1)
	{
		if (*in == 0)
		{
			*tr = NULL;
			return;
		}
		if (*in == *Pr)
		{
			(*tr) = (PNode)malloc(sizeof(Node));
			(*tr)->data = *Pr;
			*in = 0;
			break;
		}
		in++;
	}
	Pr = Pr + 1;
	build(p, Pr, &(*tr)->lchild);
	build(in+1, Pr, &(*tr)->rchild);
}

void postordertraversal(PNode T)
{
	if (T == NULL)
		return;
	postordertraversal(T->lchild);
	postordertraversal(T->rchild);
	printf("%c", T->data);
}