#pragma once
#include "data.h"
ref class data_structure
{
private:
	data* ptr;
	unsigned count;
public:
	data_structure();
	~data_structure();
	void destroy();
	bool add_element(data* value);
	bool insert_element(data* value, unsigned index);
	bool delete_elment(unsigned index);
	bool set_element(data* value, unsigned index);
	unsigned get_count();
	data* get_element(unsigned index);
};

