

inherit "room/room";

reset (arg) {
  set_light(1);
  short_desc = "hole";
  long_desc = 
        "You have entered some sort of a cave.\n"
        "You see a pair of glowing red eyes.\n"
        "They don't seem happy to see you.\n";
   dest_dir = ({ "players/jake/westbase.c","hole" });
   clone_list = ({ 1, 1, "wolf", "obj/monster", 
			     ({ "set_name", "wolf",
				"set_short", "wolf",
				"set_long",
       "This is a mean old wolf.\nHe doesn't seem very happy to see you.\n",
				"set_level", 10,
                                "set_al", 100,
				"set_ac", 5,
				"set_wc", 10,
				"add_money", 30,
				"set_aggressive", 1 }),
		-1, 1, "fangs", "obj/weapon",
			     ({ "set_name", "fangs",
				"set_class", 10,
				"set_short", "Wolf fangs",
				"set_long", "These are the fangs of a wolf.\n",
                                "set_value", 100,
				"set_weight", 1 })
				});

::reset();
replace_program("room/room");
}

