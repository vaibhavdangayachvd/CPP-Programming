#ifndef SIMPLE_BODY
#define SIMPLE_BODY
#include "..\\abstract\\body.h"
class simple_body:public body
{
public:
    simple_body(void);
	std::string get_name(void);
    int get_strength(void);
};
#endif // SIMPLE_BODY
