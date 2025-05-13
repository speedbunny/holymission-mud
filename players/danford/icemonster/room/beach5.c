/* 
   Hier stand frueher mal Surf City.
*/  

inherit "/players/randyandy/basis/room";

object sign;

init() {
	::init();
	add_action("south", "south");
}

reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A small Path on a nice beach";
      long_desc = 
"You are walking on a small path leading to a dike. The sea lies to the east.\n";
      dest_dir = ({
       "players/xio/room/path3", "south",
       "players/tares/coast/dike2", "north" 
                });

 }
     if (!sign) {
	sign = clone_object(OBJ+"newsign");
	move_object(sign, this_object());
	}
}

south() {
	this_player()->move_player("south#/players/xio/room/path3");
/*	log_file("randyandy.city", ctime(time())+" "+this_player()->query_name()+" leaves Surf City to the south.\n"); */
	return 1;
}

