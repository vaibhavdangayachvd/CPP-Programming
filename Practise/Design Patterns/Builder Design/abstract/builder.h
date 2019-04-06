#ifndef BUILDER_H
#define BUILDER_H
#include "..\\headers\\plane.h"
class builder
{
protected:
    plane *this_plane;
public:
    virtual void get_parts_done()=0;
    virtual void build_engine()=0;
    virtual void build_body()=0;
    plane *get_plane(void);
    ~builder();
};
#endif // BUILDER_H
