#ifndef __ITERATOR_CLASS__
#define __ITERATOR_CLASS__
#include "composite.h"
#include <stack>

class Base;

class Iterator;
class OperatorIterator;
class NullIterator;
class UnaryIterator;

class Iterator{
	protected:
		Base* self_ptr;
		Base* current_ptr;

	public:
		Iterator(){ self_ptr = NULL; current_ptr = NULL; }
		Iterator(Base* ptr){ this-> self_ptr = ptr; }

		// Sets up the iterator to start at the beginning of transversal
		virtual void first() = 0;

		// Move to the next element
		virtual void next() = 0;

		// Returns whether or not you've finished iterating
		virtual bool is_done() = 0;

		// Returns the element currently being pointed at
		virtual Base* current() = 0;
};

class OperatorIterator : public Iterator{
	public:
		OperatorIterator(Base* ptr);

		void first();
		void next();
		bool is_done();
		Base* current();
};

class NullIterator : public Iterator{
	public:
		NullIterator(Base* ptr);

		void first();
		void next();
		bool is_done(); 
		Base* current();
};

class UnaryIterator : public Iterator{
	public:
		UnaryIterator(Base* ptr);

		void first();
		void next(); 
		bool is_done();
		Base* current();
};

class PreOrderIterator : public Iterator{
	protected:
		stack<Iterator*> iterators;

	public:
		PreOrderIterator( Base* ptr );
		
		void first();
		void next();
		bool is_done();
		Base* current();
};
#endif
