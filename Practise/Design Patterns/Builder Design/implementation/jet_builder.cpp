#include "..\\headers\\jet_builder.h"
void jet_builder::get_parts_done(void)
{
    this_plane=new plane("F16 Jet Plane");
}
void jet_builder::build_body(void)
{
    this_plane->set_body("F16 Body");
}
void jet_builder::build_engine(void)
{
    this_plane->set_engine("F16 Engine");
}
