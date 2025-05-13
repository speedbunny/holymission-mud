/* 12.12.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "You are deep inside Darkwood";
  long_desc = 
	"You are deep inside Darkwood. You wish you had never come here.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/dw_path5", "south",
	 "players/topaz/angmar/fairyland/darkwood3","east" });
  clone_list = ({ 1, 1, "oak", "obj/monster",
			     ({ "set_name", "oak",
				"set_level", 17,
				"set_hp", 200,
				"set_wc", 20,
				"set_ac", 13,
				"set_short", "A giant oak",
				"set_long", 
                        "The oak is following your movements with its eyes.\n"+
	  		"Maybe you should leave while you can.\n",
				"set_al", -200,
				"add_money", 500 })
				});

::reset();
replace_program("room/room");
}
