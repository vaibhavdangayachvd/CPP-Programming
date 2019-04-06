#ifndef PROPELLER_BUILDER_H
#define PROPELLER_BUILDER_H
#include "..\\abstract\\builder.h"
class propeller_builder:public builder
{
public:
    void get_parts_done(void);
    void build_engine(void);
    void build_body(void);
};
#endif // PROPELLER_BUILDER_H
