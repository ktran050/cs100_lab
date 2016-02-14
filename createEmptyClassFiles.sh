#!/bin/sh
touch MyClass.cc
touch MyClass.hh
cat kevin_861172609.txt >> MyClass.cc
cat kevin_861172609.txt >> MyClass.hh
echo "#ifndef MyClass_hh
#define MyClass_hh

class MyClass
{
		public:
		MyClass();
" >> MyClass.hh
