#include "..\\headers\\director.h"
plane * director::create_plane(builder *d)
{
    d->get_parts_done();
    d->build_engine();
    d->build_body();
    return d->get_plane();
}
