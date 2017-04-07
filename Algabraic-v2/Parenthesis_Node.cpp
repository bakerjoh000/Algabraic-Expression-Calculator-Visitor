#include "Parenthesis_Node.h"


Parenthesis_Node::Parenthesis_Node()
{
}

Parenthesis_Node::~Parenthesis_Node()
{

}

int Parenthesis_Node::accept(Expr_Node_Visitor &v)
{
	return 0;
}

int Parenthesis_Node::weight()
{
	return 0;
}