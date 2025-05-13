/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  set_light(0);
  short_desc = "small room";
  long_desc = "A small room with rough cut walls.\n";
  dest_dir = ({ "players/silas/caves/tunnel1", "north",
         "room/mine/tunnel5", "south" });
  clone_list = ({ 1, 1, "hobgoblin", "obj/monster", 
			     ({ "set_name", "hobgoblin",
				"set_alias", "goblin",
                                "set_level", 5,
				"set_race", "goblin",
				"set_size", 2,
				"set_wc", 9,
				"set_short", "A hobgoblin",
				"set_long", 
                                   "This hobgoblin looks really nasty.\n",
				"add_money", 50 }) 
					});


::reset();
replace_program("room/room");
}
