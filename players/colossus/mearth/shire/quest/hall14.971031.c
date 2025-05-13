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
      "/players/colossus/mearth/shire/quest/hall15", "east",
      "/players/colossus/mearth/shire/quest/hall13", "west",
    });
    set_light(1);
    items = ({
      "torches", "The torches are securely fastened to the walls.\n",
      "walls", "The flickering flame of the torch casts long shadows on the walls.\n",
      "shadows", "The shadows are cast by the flickering flames of the torches.\n",
      "flames", "Bright yellowish-orange flames that cast shadows on the walls.\n",
    });
    MAKE_DOORS("players/colossus/mearth/shire/quest/hall14","south", "players/colossus/mearth/shire/quest/cell2","north","metal","iron","The celldoor is solidly built.\n", 1,1,1);
    if(obj_1){
	obj_1->set_closed(1);
	obj_1->set_locked(1);
	obj_1->set_both_status();
    }
}
