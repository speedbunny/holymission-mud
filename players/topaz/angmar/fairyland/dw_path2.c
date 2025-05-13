/* 12.13.93 Airborne: Change to room/room and clone_list */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "On a path in Darkwood";
  long_desc =
    	"You are walking on a twisty path in the legendary Darkwood. You feel\n"
	"very uncomfortable.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/dw_path3","north",
	   "players/topaz/angmar/fairyland/dw_path1","south",
	   "players/topaz/angmar/fairyland/darkwood1","east" });
  clone_list = ({ 1, 1, "oak", "obj/monster",
			     ({ "set_name", "oak",
				"set_level", 18,
				"set_hp", 300,
				"set_wc", 22,
				"set_ac", 9,
				"set_short", "A big oak",
				"set_long",
         		"The oak is watching you with small gleaming eyes\n"+
	  		"and waves it's branches menacingly.\n",	
                         	"set_al", -200 }),
			-1, 1, "branch", "obj/weapon",
			     ({ "set_name", "branch",
				"set_short", "A branch",
				"set_long", 
				"Seems to be a branch from an oak.\n",
				"set_class", 13,
				"set_value", 500,
				"set_weight", 4 })
				});

::reset();
replace_program("room/room");
}
