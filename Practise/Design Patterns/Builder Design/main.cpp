#include<iostream>
#include "implementation\\builder.cpp"
#include "implementation\\jet_builder.cpp"
#include "implementation\\propeller_builder.cpp"
#include "implementation\\plane.cpp"
#include "implementation\\director.cpp"
int main()
{
    director *dr;
    propeller_builder pb;
    jet_builder jb;
    plane *p1=dr->create_plane(&pb);
    plane *p2=dr->create_plane(&jb);
    p1->show();
    p2->show();
    delete p1;
    delete p2;
    return 0;
}
