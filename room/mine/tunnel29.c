/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  set_light(0);
  short_desc = "Dead end";
  long_desc = "This dead end is home to a cave dragon that " +
              "does not enjoy your company. You would be well " +
              "advised not to adgitate this beast. There is also a " +
              "small hole in the floor just large enough for you to fit " +
              "down.\n";
  dest_dir = ({ "room/mine/tunnel28", "west" });
  hidden_dir = ({
                   "players/mangla/rooms/underdark/r5_1", "down",
               });
  clone_list = ({ 1, 1, "dragon", "obj/monster",

			     ({ "set_name", "dragon",
			     	"set_level", 17,
				"set_race", "dragon",
				"set_size", 5,
				"set_al", -900,
				"set_short", "A cave dragon",
				"set_wc", 25,
				"set_ac", 6 }),
		  -1, 1, "sapphire", "obj/treasure", 
			     ({ "set_name", "sapphire",
				"set_id", "sapphire",
				"set_alias", "stone",
				"set_short", "A sapphire",
 				"set_value", 250 }),
  		   -1, 1, "diamond", "obj/treasure",
		             ({ "set_id", "diamond",
				"set_alias", "stone",
				"set_short", "A diamond",
				"set_value", 250 })
					});

::reset();
replace_program("room/room");
}



