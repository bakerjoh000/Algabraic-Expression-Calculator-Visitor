#include "Calculator_Visitor.h"
#include "Eval_Expr_Tree.h"
#include "Expr_Tree_Builder.h"
#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

Calculator_Visiter::Calculator_Visiter()
{

}

Calculator_Visiter::~Calculator_Visiter()
{

}

bool Calculator_Visiter::parse_expr(const std::string & infix, Expr_Tree_Builder &b)
{

	std::istringstream input(infix, std::istringstream::in);

	std::string token;

	int number = 0;
	int countnum = 0;
	int countops = 0;

	while (input >> token)
	{
		if (token == "+")
		{

			if (countnum == countops + 1)
			{
				countops++;
				b.build_addition_operand();
			}
			else break;
		}
		else if (token == "-")
		{
			if (countnum == countops + 1)
			{
				countops++;
				b.build_subtraction_operand();
			}
		}
		else if (token == "*")
		{
			if (countnum == countops + 1)
			{
				countops++;
				b.build_multiplication_operand();
			}
		}
		else if (token == "/")
		{
			if (countnum == countops + 1)
			{
				countops++;
				b.build_division_operand();
			}
		}
		else if (token == "%")
		{
			if (countnum == countops + 1)
			{
				countops++;
				b.build_percentage_operand();
			}
		}
		else if (token == "(")
			b.build_open_parenthesis();
		else if (token == ")"){
			b.build_close_parenthesis();

		}
		else if (!(atoi(token.c_str()) == 0 & token[0] != '0'))
		{
			std::istringstream token_num(token);
			token_num >> number;
			countnum++;
			b.build_number(number);
		}

		else if (IsAlpha(token)) {

			std::string variableValue;

			std::cout << "Please enter the value of " << token << ": " << std::endl;
			std::cin >> variableValue;

			std::istringstream numberInput(variableValue);
			std::string num;
			numberInput >> num;

			if (!(atoi(num.c_str()) == 0 & num[0] != '0'))
			{
				std::istringstream token_num(num);
				token_num >> number;
				countnum++;
				b.build_number(number);
			}

			else {
				std::cout << "Invalid entry. " << std::endl;
			}


		}

		else{
			std::cout << "The expression is invalid ";
			return false;
		}
	}
	if (countnum == countops + 1)
	{
		b.build_expression();
		return true;
	}
	else
	{
		std::cout << "The expression is invalid";
		return false;
	}

}

bool Calculator_Visiter::evaluate_expr(const std::string &infix)
{

	Expr_Tree_Builder builder;
	Eval_Expr_Tree eval;

	if (!parse_expr(infix, builder))
		return false;

	Expr_Node *expr;


	expr = builder.get_expression();


	if (0 == expr)
		return false;


	expr->accept(eval);

	int result = eval.result();

	delete expr;
	std::cout << "Result: " << result;


	return true;
}

bool Calculator_Visiter::ArePair(char opening, char closing)
{
	if (opening == '(' && closing == ')')
		return true;
	else
		return false;
}

bool Calculator_Visiter::AreParanthesesBalanced(std::string exp)
{

	Stack<char>  S;
	for (int i = 0; i<exp.length(); i++)
	{
		if (exp[i] == '(')
			S.push(exp[i]);
		else if (exp[i] == ')')
		{
			if (S.size() == 0 || !ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	if (S.size() == 0)
		return true;
	else
		return false;
}

bool Calculator_Visiter::IsAlpha(std::string c) {

	char temp = c[0];

	static const char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	return (strchr(alpha, temp) != nullptr);
}



