inherit "room/room";
#include "/obj/door.h"

object obj_1, obj_2;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    short_desc = "Corridor of cells";
    long_desc =
    "You are standing at a narrow corridor that leads to the\n"+
    "cell rooms of the Shire shiriff station. Lit torchs line\n"+
    "the walls of the corridor and the flickering flames cast\n"+
    "dancing shadows on the walls.\n";
    dest_dir = ({
      "/players/colossus/mearth/shire/quest/hall12", "east",
    });
    set_light(1);
    items = ({
      "torches", "The torches are securely fastened to the walls",
      "walls", "The flickering flame of the torch casts long shadows on the walls",
      "shadows", "The shadows are cast by the flickering flames of the torches",
      "flames", "Bright yellowish-orange flames that cast shadows on the walls",
    });
}
