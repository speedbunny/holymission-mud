inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "floor5";
  long_desc = 
        "This appears to be an abandoned room.\n"
	"The students probably got kicked out by the RD.\n"
	"There are empty bottles scattered around the room.\n";
  dest_dir = ({ "players/jake/jhall", "west" });
  clone_list = ({ 1, 1, "beer", "obj/beer", 0 });

::reset();
replace_program("room/room");
}

