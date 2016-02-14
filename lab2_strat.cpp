class Container {
	protected:
	Sort* sort_function;

	public:
		/* Constructors */
		Container() :  sort_function(NULL){};
		Container(Sort* function) : sort_function(function) {};

		/* Non Virtual Constructors */
		void set_sort_function(Sort* sort_function);

		/* Pure Virtual Functions */
		virtual void add_element(Base* element) = 0;
		virtual void print() = 0;
		virtual void sort() = 0;
		virtual void swap(int i, int j) = 0;
		virtual Base* at(int i) = 0;
		virtual int size() = 0;

};

class Sort {
	public:
		/* Constructors */
		Sort();

		/* Pure Virtual Functions */
		virtual void sort(Container* container) = 0;

};
