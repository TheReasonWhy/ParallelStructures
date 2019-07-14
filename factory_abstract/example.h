#ifndef EXAMPLE_H
#define EXAMPLE_H
//#include"array"

class example{

public:
    using Index_type = unsigned;
    example(unsigned index):m_index(index){}
    ~example(){}
    unsigned index(){return m_index;}
private:
    unsigned m_index;
};
#endif // EXAMPLE_H
