#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

class smart_array
{
public:
    smart_array(int size_);
    ~smart_array();
    
    void add_element(int value);
    int get_element(int position);
    
private:
    int* address;
    int size;
    int filled_elements_amount;
    
};

#endif // SMART_ARRAY_H
