#include "mroom.h"

void reset(int arg){
    if(arg) return;
    set_light(1);
    short_desc = "Intersection";
    long_desc =
    "Several small bushes and some trees line that paths here. This is an\n"+
    "intersection in the roads with paths leading west, east, and south\n"+
    "There also is a signpost here.\n";
    "south.\n";
    dest_dir = ({
      SHIRE+"/road3", "west",
      SHIRE+"/road1", "south",
      SHIRE+"/sheriff1", "east",
    });
    clone_list = ({1,1, "sign", SHIRE+"/signpost", 0});
    ::reset();
    replace_program("room/room");
}
