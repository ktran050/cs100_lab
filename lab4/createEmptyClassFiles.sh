#!/bin/sh
touch $1.cc
touch $1.hh
cat kevin_861172609.txt >> $1.cc
cat kevin_861172609.txt >> $1.hh
echo "#ifndef $1_hh 
#define $1_hh 

class $1
{
	public:
	$1();
	~$1();

	private:
};
#endif" >> $1.hh
echo "include \"./$1\"

$1::$1()
{}

$1::~$1()
{}" >> $1.cc
