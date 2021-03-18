#include "data_structure.h"
#include "data_structure.h"
#include <stdlib.h>
#include <cstring>

data_structure::data_structure()
{
	this->ptr = nullptr;
	this->count = 0;
}

data_structure::~data_structure()
{
	this->destroy();
}

void data_structure::destroy()
{
	delete this->ptr;
	this->count = 0;
}

bool data_structure::add_element(data* value)
{
	data* tmp = (data*)realloc(this->ptr, (this->count + 1) * sizeof(data));
	if (tmp == nullptr)
		return false;
	tmp[this->count] = *value;
	this->ptr = tmp;
	this->count += 1;
	return true;
}

bool data_structure::insert_element(data* value, unsigned index)
{
	if (index >= this->count)
		return add_element(value);
	data* tmp = (data*)realloc(this->ptr, (this->count + 1) * sizeof(data));
	if (tmp == nullptr)
		return false;
	memmove(&tmp[index + 1], &tmp[index], (this->count - index) * sizeof(value));
	tmp[index] = *value;
	this->ptr = tmp;
	this->count += 1;
	return true;
}

bool data_structure::delete_elment(unsigned index)
{
	if ((index < 0) || (index >= this->count))
		return false;
	data* tmp = this->ptr;
	memmove(&tmp[index], &tmp[index + 1],
		(this->count - index - 1) * sizeof(data));
	this->ptr = (data*)realloc(tmp, (this->count - 1) * sizeof(data));
	this->count -= 1;
	return true;
}

bool data_structure::set_element(data* value, unsigned index)
{
	if ((index < 0) || (index >= this->count))
		return false;
	this->ptr[index] = *value;
	return true;
}

unsigned data_structure::get_count()
{
	return this->count;
}


data* data_structure::get_element(unsigned index)
{
	return &this->ptr[index];
}
