#include "Multiplication_Node.h"


Multiplication_Node::Multiplication_Node()
{
}

Multiplication_Node::~Multiplication_Node()
{

}

int Multiplication_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Multiplication_Node(*this);

	return v.result();

}

int Multiplication_Node::weight()
{
	return 2;
}