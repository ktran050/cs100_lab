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
	//Iterator* point = NULL;
	//if(self_ptr->get_right() == NULL){
	//	if(self_ptr->get_left() == NULL){
	//		point =  new NullIterator(self_ptr);
	//	}
	//	else{
	//		point = new UnaryIterator(self_ptr);
	//	}
	//}
	//else{
	//point = new OperatorIterator(self_ptr);
	//}

	Iterator* point = self_ptr->create_iterator();
	
	point->first();

	// Initialize that iterator and push it onto the stack
	iterators.push(point);
}

void PreOrderIterator::next(){
	Iterator* temp = iterators.top()->current()->create_iterator();
    temp->first();
	iterators.push(temp);
	while(iterators.top()->is_done() && iterators.size() != 0)
	{
		iterators.pop();
		if(iterators.size() == 0){break;}
		iterators.top()->next();
	}

 }
bool PreOrderIterator::is_done(){ return iterators.empty(); }
Base* PreOrderIterator::current(){
	if(iterators.size() > 0)
	{
		return iterators.top()->current(); 
	}
	else{
		return NULL;
	}
}

//--------------------------------------------------------------------------
// Null Iterator Class
//--------------------------------------------------------------------------
NullIterator::NullIterator( Base* ptr ) { this->self_ptr = ptr; }
void NullIterator::first(){}
void NullIterator::next(){}
bool NullIterator::is_done(){ return true; }
Base* NullIterator::current(){ return NULL; }
