inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "stairj";
  long_desc = 
        "You have entered the stairwell.\n"
        "These stairs look old and rickety.\n"
        "proceed with caution.\n";
  items = ({ "stairs", 
   	"These are old and rickety wooden stairs.\nProceed with caution" });
  dest_dir = ({ "players/jake/upstairs2","up",
        "players/jake/staire", "down",
        "players/jake/hallk.c", "south" });
  clone_list = ({ 1, 5, "termite", "obj/monster",
			     ({ "set_name", "termite",
				"set_short", "Termite",
				"set_long",
		"This is a hungry little termite.\n It loves eating wood.\n", 
				"set_level", 2,
				"set_align", 100 })
				});

::reset();
replace_program("room/room");
}

