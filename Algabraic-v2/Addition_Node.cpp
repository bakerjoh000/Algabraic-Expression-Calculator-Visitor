#include "Addition_Node.h"

Addition_Node::Addition_Node()
{

}

Addition_Node::~Addition_Node()
{

}

int Addition_Node::accept(Expr_Node_Visitor & v)
{
	//the object is passed to the visitor
	//the visitor stores the result
	v.Visit_Addition_Node(*this);

	return v.result();
}

int Addition_Node::weight()
{
	return 1;
}