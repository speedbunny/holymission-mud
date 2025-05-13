inherit "room/room";

object monster;

reset(arg)
{
  if (arg) return;
  set_light(1);
   short_desc = "Castle Gate";
   long_desc = "You stand at the gates of Ace's Castle. \n" +
               "The castle is quite huge, and you get a sense that you should\n" +
               "Not venture any further unless quite experienced.\n";
   monster = clone_object("/players/ace/castle/monsters/guard.c");
   move_object(monster, this_object());
dest_dir = ({
             "/players/ace/castle/rooms/castle1-1.c", "north",
             "/players/ace/castle/rooms/moat.c", "south"
            });
}

init() {
	::init();
	add_action("north", "north");
	add_action("south", "south");
	}
north() {
	if (present("guard")) {
		write("Guard says: None shall pass!\n");
		say(this_player() -> query_name() + " was stopped by the guard.\n");
		return(1);
		}
	move_object(this_player(), "/players/ace/castle/rooms/castle1-1.c");
	command("look", this_player());
	return(1);
	}
south() {
	move_object(this_player(), "/players/ace/castle/rooms/moat.c");
	command("look", this_player());
	return(1);
	}
