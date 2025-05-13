/* Coded by Llort */
/* Spruced up by Saffrin */

inherit "/room/room";
#include "/players/saffrin/area/tower/quest/cellar.h"

object ob;
int i,rnr;

reset(arg) {
    if (!arg) {

	set_light(0);

	short_desc="Mage Tower Cellar";

	long_desc=
	"You are in a small, cramped rat hole that is in the Mage Tower cellar.  "+
	"It is a place where scared rats flee to when they are attacked.  "+
	"The room smells like rotting wood, stinging your nose.  A rather small hole "+
	"is in the wall, leading to another place.\n";

	dest_dir= ({
	  ROOM+"c6","west"
	});

	items = ({
	  "vault","An old oak-wooden vault",
	  "hole","A small hole in the western wall",
	  "wall","A grey stone wall",
	  "walls","Grey stone walls",
	  "bottom","A dark stone bottom"
	});
	for(i=0;i<5;i++) move_object(clone_object(MONST+"rat"),this_object());
    } 
    ob=all_inventory(this_object());
    for(i=rnr=0;i<sizeof(ob);i++) if(ob[i]->query_npc()) rnr++;
    if(rnr<20) {
	for(i=0;i<5;i++) move_object(clone_object(MONST+"rat"),this_object());
    }
}

init() {
    ::init();
    add_action("enter","enter");
    add_action("leave","leave");
    add_action("leave","crawl");
}

enter(str) { 
    if (str=="hole" || str=="the hole") {
	this_player()->move_player("through the hole#"+ROOM+"c6");
	return 1;
    }
}

leave(str) {
    if (str=="hole" || str=="through the hole" || str=="the hole") {
	this_player()->move_player("through the hole#"+ROOM+"c6");
	return 1;
    }
}

