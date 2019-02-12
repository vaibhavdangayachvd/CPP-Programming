#ifndef LUXURY_BODY
#define LUXURY_BODY
#include "..\\abstract\\body.h"
class luxury_body:public body
{
public:
    luxury_body(void);
    std::string get_name(void);
    int get_strength(void);
};
#endif // LUXURY_BODY
