/* 12.05.92 Airborne - Re-written to allow use of clone_list and
   replace_program. Changed over to inherit "room/room" as well. */


inherit "room/room";

reset(){
  set_light(1);
  short_desc = "Attic";
  long_desc = "You are in the attic.\n"
	"This is a spacious, airy loft. It is very empty.\n";
  dest_dir = ({ "players/padrone/inside/stairs2", "down" });
  clone_list = ({ 1, 1, "paper", "players/padrone/obj/thing",
                	({ "set_name", "paper", 
			"set_alias", "piece of paper",
			"set_short", "A piece of paper", 
			"set_long", "This is a small piece of paper, with something written on it.\n",
                        "set_can_get", 1, 
			"set_weight", 1, 
			"set_value", 1,
			"set_read", "The writing on the paper has a strangely other-worldly quality about it.\n" +
				"It says \"Email: padrone@lysator.liu.se\".\n",
					}) });

::reset();
replace_program("room/room");
}
