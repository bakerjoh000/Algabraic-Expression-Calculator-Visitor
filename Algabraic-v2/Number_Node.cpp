#include "Number_Node.h"


Number_Node::Number_Node(int n)
:n_(n)
{

}

Number_Node::~Number_Node()
{

}

int Number_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Number_Node(*this);
	return v.result();

}

int Number_Node::weight()
{
	return -1;
}

int Number_Node::getNumber()
{
	return n_;
}