inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "lintm";
  long_desc = 
        "This appears to be an old storage room.\n"
	"There are big piles of dust and lint on the floor.\n"
        "Wait! is one coming to life?\n";
  dest_dir = ({ "players/jake/basee.c", "west" });
  clone_list = ({ 1, 1, "lint", "players/jake/monster/lint", 0 });
  
::reset();
replace_program("room/room");
}


