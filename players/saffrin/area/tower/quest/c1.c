/* Coded by Llort */
/* Spruced up by Saffrin */

inherit "/room/room";
#include "/players/saffrin/area/tower/quest/cellar.h"

object ob;
int i;

reset(arg) {

    if (!arg) {

	set_light(0);

	short_desc="Mage Tower Cellar Stairway";

	long_desc=
	"You are in the dark and musty cellar of the Mage Tower.  "+
	"It is cold and wet here, but oddly enough you can smell cheese all around you.  "+
	"The smell is making your mouth water.  The cellar is made up of slightly rotting wood.  "+
	"There is a spiral staircase leading up into the Mage Tower.\n";

	dest_dir = ({
	  ROOM+"c2","north",
	  ROOM+"c3","west",
	  ROOM+"c6","south",
      "/players/saffrin/area/tower/room/hall1", "up",
	});

	items = ({
	  "vault","An old oak-wooden vault",
	  "wall","A grey stone wall",
	  "walls","Grey stone walls",
	  "bottom","A dark stone bottom",
	  "staircase","Spiral staircase",
	});
    }
    if (!ob) {
	for (i=1;i<3;i++) {
	    ob=clone_object(MONST+"rat");
	    move_object(ob,this_object());
	}
    }
} 

init() {
    ::init();
    if(this_player()->id("rat"))
	add_action("up","up",1);
}

up() {
    if(this_player()->query_guild()!=5) {
	write("Sorry, but you are not allowed to enter the Mage Tower.\n");
	return 1;
    } else return ::move();
}
