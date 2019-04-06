#include "..\\headers\\propeller_builder.h"
void propeller_builder::get_parts_done(void)
{
    this_plane=new plane("MIG21 Propeller Plane");
}
void propeller_builder::build_body(void)
{
    this_plane->set_body("MIG21 Body");
}
void propeller_builder::build_engine(void)
{
    this_plane->set_engine("MIG21 Engine");
}
