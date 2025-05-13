/* 12.11.93 Airborne: change to room/room and clone_list */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "Behind the Misty Mountain";
  long_desc =
	"The path ends here behind Misty Mountain. There seems to be no\n"+
	"way around it.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/dw_path5", "east" });
  clone_list = ({ 1, 1, "troll", "obj/monster",
			     ({ "set_name", "troll",
				"set_level", 17,
				"set_hp", 350,
				"set_wc", 20,
				"set_ac", 11,
				"set_short", "The forestking",
				"set_alias", "king",
				"set_race", "troll",
				"set_long",	
           	"It's an old troll which must be at least 1000 years old.\n"+
	   	"I don't think he likes you...\n",
				"set_al", -350 }),
                 -1, 1, "cloak", "obj/armour",
	                      ({ "set_name", "cloak",
				 "set_short", 
					"A cloak made of twigs and leaves",
				 "set_long",
                           "It once belonged to the troll-king of Darkwood.\n",
				"set_value", 200,
				"set_weight", 1,
				"set_ac", 1,
				"set_type", "cloak" })
                                 });

::reset();
replace_program("room/room");
}
					
