#include "iterator.h"

//--------------------------------------------------------------------------
// Unary Iterator Class
//--------------------------------------------------------------------------
UnaryIterator::UnaryIterator( Base* ptr ){ self_ptr = ptr; }
void UnaryIterator::first(){ current_ptr = self_ptr.get_left(); }
void UnaryIterator::next(){ current_ptr = NULL; }
bool UnaryIterator::is_done(){
	if(current_ptr == NULL){ return true; }
	else{ return false; }
}
Base* UnaryIterator::current(){ return current_ptr; }

//--------------------------------------------------------------------------
// Operator  Iterator Class
//--------------------------------------------------------------------------
OperatorIterator::OperatorIterator( Base* ptr ){ self_ptr = ptr; }
void OperatorIterator::first( current_ptr = self_ptr.get_left(); }
void OperatorIterator::next(
	if(current_ptr == ptr_left){ current_ptr = ptr_right; }
	else{ current_ptr = NULL; }
)
bool OperatorIterator::is_done(a
	if(current_ptr == NULL){ return true; }
	else{ return false; }
}
Base* OperatorIterator::current(){ return current_ptr; }

//--------------------------------------------------------------------------
// PreOrder Iterator Class
//--------------------------------------------------------------------------
PreOrderIterator::PreOrderIterator( Base* ptr ){ self_ptr = ptr; }
void PreOrderIterator::first(){ 
void PreOrderIterator::next(){}
bool PreOrderIterator::is_done(){ return false; }
Base* OperatorIterator::current(){ return current_ptr; }

//--------------------------------------------------------------------------
// Null Iterator Class
//--------------------------------------------------------------------------
NullIterator::NullIterator( Base* ptr ){ self_ptr = ptr; }
void NullIterator::first(){}
void NullIterator::next(){}
bool NullIterator::is_done(){ return true; }
Base* OperatorIterator::current(){ return self_ptr; }
