/* 12.13.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "Eagle's nest";
  long_desc =
    "You are on the top of Misty Mountain. It's very cold up here, although\n"
    "the view of the fairyland below is terrific. There is a bird-nest here.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/mountain","down" });
  clone_list = ({ 1, 1, "eagle", "obj/monster",
			     ({ "set_name", "eagle",
				"set_level", 9,
				"set_hp", 100,
				"set_wc", 10,
				"set_ac", 4,
				"set_short", "An eagle",
				"set_long", 
		"The eagle glares at you. He doesn't want to be disturbed.\n",
				"set_al", 50 }),
		-1, 1, "ruby", "obj/treasure",
			     ({ "set_id", "ruby",
				"set_short", "A small ruby",
				"set_value", 100 })
				});

::reset();
replace_program("room/room");
}

