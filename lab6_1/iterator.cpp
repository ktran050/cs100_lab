#include "iterator.h"

//--------------------------------------------------------------------------
// Unary Iterator Class
//--------------------------------------------------------------------------
UnaryIterator::UnaryIterator( Base* ptr ) { this->self_ptr = ptr; }
void UnaryIterator::first(){ current_ptr = self_ptr->get_left(); }
void UnaryIterator::next(){ current_ptr = NULL; }
bool UnaryIterator::is_done(){
	if(current_ptr == NULL){ return true; }
	else{ return false; }
}
Base* UnaryIterator::current(){ return current_ptr; }

//--------------------------------------------------------------------------
// Operator  Iterator Class
//--------------------------------------------------------------------------
OperatorIterator::OperatorIterator( Base* ptr ) { this->self_ptr = ptr; }
void OperatorIterator::first(){ current_ptr = self_ptr->get_left(); }
void OperatorIterator::next(){
	if(current_ptr == self_ptr->get_left() ){ current_ptr = self_ptr->get_right(); }
	else{ current_ptr = NULL; }
}
bool OperatorIterator::is_done(){
	if(current_ptr == NULL){ return true; }
	else{ return false; }
}
Base* OperatorIterator::current(){ return current_ptr; }

//--------------------------------------------------------------------------
// PreOrder Iterator Class
//--------------------------------------------------------------------------
PreOrderIterator::PreOrderIterator( Base* ptr ) { this->self_ptr = ptr; }
void PreOrderIterator::first(){
	// Empty the stack
	for(unsigned i = 0; i < iterators.size(); ++i){ iterators.pop(); }

	// Create an iterator for the base*
	Iterator* point = NULL;
	if(self_ptr->get_right() == NULL){
		if(self_ptr->get_left() == NULL){
			point =  new NullIterator(self_ptr);
		}
		else{
			point = new UnaryIterator(self_ptr);
		}
	}
	else{
		point = new OperatorIterator(self_ptr);
	}

	// Initialize that iterator and push it onto the stack
	iterators.push(point);
}

void PreOrderIterator::next(){ iterators.pop(); }
bool PreOrderIterator::is_done(){ return iterators.empty(); }
Base* PreOrderIterator::current(){ return (iterators.top())->current(); }

//--------------------------------------------------------------------------
// Null Iterator Class
//--------------------------------------------------------------------------
NullIterator::NullIterator( Base* ptr ) { this->self_ptr = ptr; }
void NullIterator::first(){}
void NullIterator::next(){}
bool NullIterator::is_done(){ return true; }
Base* NullIterator::current(){ return self_ptr; }
