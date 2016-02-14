class Base
{
	public:
	/* Constructors */
	Base() {};
	/* Pure virtual functions */
	virtual double evaluate() = 0;
};

// Base class children
//
//
class Op : public Base
{
	double value;
	public:
		Op()
		{
			value = 0;
		}
		Op(double val){
			value = val;
		}
		
		void changeVal(double val)
		{
			value = val;
		}
		double evaluate()
		{
			return value;
		}
};
// Leaf node that contains numbers

class Composite1 : public Base
{
	public:
		Op Op1;
};
// Composite class containing one operand

class Composite2 : public Base
{
	public:
		Op Op1;
		Op Op2;
};
// Composite class containing two operands

// Composite Children
//
//
class Sub : public Composite2
{
	public:
		Sub(Op OpOne, Op OpTwo)
		{
			Op1.changeVal( OpOne.evaluate() );
			Op2.changeVal( OpTwo.evaluate() );
		}
		double evaluate(){
			return Op1.evaluate() - Op2.evaluate();
		}
};
// Inherits two operands from Composite2 and performs subtraction

class Add : public Composite2
{
	public:
		Add(Op OpOne, Op OpTwo){
			Op1.changeVal( OpOne.evaluate() );
			Op2.changeVal( OpTwo.evaluate() );
		}
		double evaluate(){
			return Op1.evaluate() + Op2.evaluate();
		}
};
// Inherits two operands from Composite2 and performs addition

class Div : public Composite2
{
	public:
		Div(Op OpOne, Op OpTwo){
			Op1.changeVal( OpOne.evaluate() );
			Op2.changeVal( OpTwo.evaluate() );
		}
		double evaluate(){
			return Op1.evaluate() / Op2.evaluate();
		}
};
// Inherits two operands from Composite2 and performs division

class Mult : public Composite2
{
	public:
		Mult(Op OpOne, Op OpTwo){
			Op1.changeVal( OpOne.evaluate() );
			Op2.changeVal( OpTwo.evaluate() );
		}
		double evaluate(){
			return Op1.evaluate() * Op2.evaluate();
		}
};
// Inherits two operands from Composite2 and performs multiplication

class Sqr : public Composite1
{
	public:
		Sqr(Op OpOne)
		{
			Op1.changeVal( OpOne.evaluate() );
		}
		double evaluate(){
			return Op1.evaluate();
			
		}
};
// Inherits an operand from Composite1 and squares it

int main(){
	return 0;
}
// Write classes
// Operators can perform the operations with Op objects
// Operators can perform operations with ints/doubles
// Calculations are called according to EMDAS
