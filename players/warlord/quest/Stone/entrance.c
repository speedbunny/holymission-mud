#include "stone.h"

inherit "room/room";

void reset( int arg ) {
    if (arg) return;
    short_desc= "Stone room";
    long_desc="Stone room\n";
}
void SetUp() {
}
