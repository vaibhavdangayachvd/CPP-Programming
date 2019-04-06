#include "..\\abstract\\builder.h"
plane *builder::get_plane(void)
{
    return this_plane;
}
builder::~builder()
{
    delete this_plane;
}
