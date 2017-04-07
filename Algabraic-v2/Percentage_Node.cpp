#include "Percentage_Node.h"


Percentage_Node::Percentage_Node()
{

}

Percentage_Node::~Percentage_Node()
{

}

int Percentage_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Percentage_Node(*this);

	return v.result();
}

int Percentage_Node::weight()
{
	return 2;
}