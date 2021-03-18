#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
struct data
{
private:
	double age;
	std::string name;
public:
	data()
	{
		this->age = 0.0;
		this->name = "";
	}
	~data() {}
	void set_name(System::String^ name)
	{
		System::String^ systemstring = gcnew System::String(name);
		msclr::interop::marshal_context context;
		this->name = context.marshal_as<std::string>(name);
	}
	System::String^ get_name()
	{
		return gcnew System::String(this->name.c_str());
	}
	void set_age(double age)
	{
		this->age = age;
	}
	double get_age()
	{
		return this->age;
	}
};

