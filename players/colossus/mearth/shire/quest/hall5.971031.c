inherit "room/room";
#include "/obj/door.h"
object guard, key;

void reset(int arg){
    ::reset(arg);
    if(!present("shiriff")){
	if(!present("key"), guard){
	    move_object(guard = clone_object("/players/colossus/mearth/shire/shiriff"),
	      this_object());
	    MAKE_KEY(key, "metal", "iron");
	    move_object(key, guard);
	}
    }
    if(arg) return;
    set_light(1);
    short_desc = "Stairway to cells";
    long_desc =
    "A short hallway that ends at a set of stairs leading down to the east.\n"+
    "Set on the walls are scones for holding torches and the main entrance \n"+
    "hall lies at the other end of the hall to the northwest.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/quest/hall", "northwest",
      "/players/colossus/mearth/shire/quest/hall10", "stairs",
    });

    items = ({
      "stairs", "Stone stairs that lead down to the cells",
      "walls", "The walls look stone cold",
      "scones", "These are metal rings sticking out of walls to hold torches",
    });

}
