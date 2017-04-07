#include "Division_Node.h"


Division_Node::Division_Node()
{

}

Division_Node::~Division_Node()
{

}

int Division_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Division_Node(*this);

	return v.result();
}

int Division_Node::weight()
{
	return 2;
}