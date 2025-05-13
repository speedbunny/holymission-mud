inherit "/room/room";
#include "/obj/door.h"
#define EXIT "players/colossus/mearth/shire/quest/hall10"
#define THISROOM "players/colossus/mearth/shire/quest/hall11"

object obj_1, obj_2;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Stairs leading up";
    long_desc = 
    "You are standing at the bottom of a flight of stairs leading\n"+
    "up to the ground level of the shiriff station. Lying to your\n"+
    "east is a small celldoor that leads to the cells.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/quest/hall5", "stairs",
    });

    items = ({
      "stairs", "A flight of stone stairs leading up",
    });
    MAKE_DOORS("/players/colossus/mearth/shire/quest/hall10", "east", "/players/colossus/mearth/shire/quest/hall11", "west", "metal", "iron", "A small but sturdy celldoor.\n", 1, 1, 1);
    if(obj_1){
	obj_1->set_closed(1);
	obj_1->set_locked(1);
	obj_1->set_both_status();
    }
    return  ;
}
