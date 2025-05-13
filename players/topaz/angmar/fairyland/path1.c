/* 12.14.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "The path to Misty Mountain";
  long_desc = 
	"You are on the path to Misty Mountain. Many people have walked\n"+
	"this path. Not many have returned...\n"+
	"The entrance to Darkwood is to the east.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/path2","west",
	   "players/topaz/angmar/fairyland/darkw_entrance","east",
	   "players/topaz/angmar/fairyland/crossing","south" });
  clone_list = ({ 1, 1, "tramper", "obj/monster",
			     ({ "set_name", "tramper",
				"set_level", 10,
				"set_hp", 150,
				"set_wc", 12,
				"set_ac", 10,
				"set_short", "A wandering tramper",
				"set_alias", "tramper",
				"set_al", 30,
                                "set_long",
       			"The wandering tramper is whistling happily.\n" }),
		-1, 1, "stick", "obj/weapon",
			     ({ "set_name", "stick",
				"set_short", "A long stick",
				"set_class", 7,
				"set_value", 10,
				"set_weight", 1 }),
		-1, 1, "shoes", "obj/armour",
			     ({ "set_name", "shoes",
				"set_short", "Worn shoes",
				"set_long", "A pair of very worn shoes.\n",
				"set_value", 10,
				"set_weight", 1,
				"set_ac", 0,
				"set_type", "boot" })
				});

::reset();
replace_program("room/room");
}
