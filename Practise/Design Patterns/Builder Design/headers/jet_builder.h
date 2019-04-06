#ifndef JET_BUILDER_H
#define JET_BUILDER_H
#include "..\\abstract\\builder.h"
class jet_builder:public builder
{
public:
    void get_parts_done(void);
    void build_engine(void);
    void build_body(void);
};
#endif // JET_BUILDER_H
