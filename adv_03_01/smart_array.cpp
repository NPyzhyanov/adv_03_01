#include <stdexcept>
#include <iostream>
#include <string>

#include "smart_array.h"

smart_array::smart_array(int size_)
{
    if (size_ <= 0)
    {
        throw std::runtime_error("Invalid size of array.");
    }
    
    size = size_;
    filled_elements_amount = 0;
    
    address = new int[size];
    std::cout << "ctor: address = " << address << std::endl;
}

smart_array::~smart_array()
{
    delete[] address;
    address = nullptr;
    std::cout << "dtor: address = " << address << std::endl;
}

void smart_array::add_element(int value)
{
    if (filled_elements_amount >= size)
    {
        throw std::runtime_error("Cannot add a new element. The array is completely filled.");
    }
    
    address[filled_elements_amount] = value;
    filled_elements_amount++;
}

int smart_array::get_element(int position)
{
    if (position >= size || position < 0)
    {
        throw std::out_of_range("Cannot get element outside of array");
    }
    if (position >= filled_elements_amount)
    {
        throw std::runtime_error("The element with this index does not yet exist");
    }
    
    return address[position];
}
