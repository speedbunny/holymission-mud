#include <std.h>

inherit "room/room";

reset(arg) {
    ::reset(arg);
    if(!arg) {
    set_light(1);
    short_desc="The real workroom of Aaa";
    long_desc="The real workroom of Aaa. Since it's not open to the public "
            + "all of that trashy scenery :) is neglected. \n";
    dest_dir=({"/players/aaa/castle/qwrkroom.c","down",
               "/room/church","church"});
    }
}
