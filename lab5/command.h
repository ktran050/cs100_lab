#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:	
		OpCommand(int num): Command()
		{	
			this->root = new Op(num);
		};
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
		AddCommand(Command* userLeft, int value): Command()
		{
			this->root = new Add(userLeft->get_root(), new Op(value));
		};
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
		SubCommand(Command* userLeft, int value): Command()
		{
			this->root = new Sub(userLeft->get_root(), new Op(value));
		};
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
		MultCommand(Command* userLeft, int value): Command()
		{
			this->root = new Mult(userLeft->get_root(), new Op(value));
		};
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
		SqrCommand(Command* userLeft): Command()
		{
			this->root = new Sqr(userLeft->get_root());
		};
};

#endif //__COMMAND_CLASS__
