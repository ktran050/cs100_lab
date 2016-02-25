#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include <vector>
#include "command.h"

using namespace std;

class Menu {
	private:
		int history_index;
		vector<Command*> history;

	public:
		Menu() {
			//Base constructor to set up all necessary members
		};
		void execute() {
			if( history_index > 0 ){
				cout << history.at(history_index-1)->execute() << endl;
			}
			else{
				cout << "0" << endl;
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			}
		};
		bool initialized() {
			//Return true if the history has been primed with a single op instruction
			//This is necessary because that is the base of a calculation
			if(history.size() > 0){
				return true;
			}
			else{
				return false;
			}
		};
		void add_command(Command* cmd) {
			//Adds a command to history in the appropriate posiiton (based on history_index)
			cout << "History index: " << history_index << " History.size(): " << history.size() << endl;
			if( (unsigned)history_index == history.size() - 1)
			{
				history.push_back(cmd);
			}
			else
			{
				vector<Command*>::iterator it = history.begin();
				history.insert(it+history_index, cmd);
			}
			history_index++;
		};
		Command* get_command() {
			//Returns the command in history we are currently referring to (based on history_index)
			return history.at(history_index-1);
		};
		void undo() {
			//Moves to the last command in history (if possible)
			if(history_index > 0)
			{
				history_index -= 1;
			}
			else
			{
				cout << "Cannot undo" << endl;
			}
		};
		void redo() {
			//Moves to the next command in history (if possible)
			history_index++;
		};
};

#endif //__MENU_CLASS__
