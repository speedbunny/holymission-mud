/* hut7 : A beach hut including the entrance to a labyrinth -> Quest */

#include "path.h"
inherit "room/room";

  object cat, table;

reset(arg) {

     if(!arg) {

      set_light(1);
      short_desc = "A beach hut";
      long_desc =
"You are standing in an empty beach hut.\n";
      dest_dir = ({
       ROOM+"path4", "north"
		 });
	       }
    if (!cat) {
       cat = clone_object("/players/firestone/cat");
       move_object(cat, this_object());
       }
    if (!table) {
    	table = clone_object(OBJ+"table");
    	move_object(table, this_object());
    }
}
init() {
	add_action("down", "down");
	add_action("north", "north");
}

down() {
	object log;
        write("You fall down into a hole on the ground.\n");
/*      if(!(present("log", this_player()))) { 
        	log=clone_object(OBJ+"invis/log");
        	move_object(log, this_player());
        } */ /* The logfile gets too long ... :-) */
        this_player()->move_player("falling down#/players/randyandy/beach/cave/entr");
        return 1;
}
north() {
	this_player()->move_player("north#/players/randyandy/beach/path4");
	return 1;
}

