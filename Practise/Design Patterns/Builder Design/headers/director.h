#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "..\\abstract\\builder.h"
#include "..\\headers\\plane.h"
class director
{
public:
    plane * create_plane(builder *d);
};
#endif // DIRECTOR_H
