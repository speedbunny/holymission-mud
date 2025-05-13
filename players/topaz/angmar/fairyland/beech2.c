/* 12.11.93 Airborne: Changed to room/room and clone_list */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "The beech woods";
  long_desc =
	"You are in the beech woods. The air feels warm, and the birds are\n"+
	"singing. You feel very happy.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/beech1","east",
           "players/topaz/angmar/fairyland/edge2","north" });
  clone_list = ({ 1, 2, "elf", "players/topaz/angmar/elf", 0,
		 -1, 1, "knife", "obj/weapon",
			     ({ "set_class", 9,
				"set_value", 25,
				"set_weight", 1,
				"set_short", "A big knife",
				"set_name", "big knife",
				"set_alt_name", "knife" }),
		 -1, 1, "sword", "obj/weapon",
			     ({ "set_name", "Small sword",
				"set_class", 11,		
				"set_value", 40,
				"set_weight", 2,
				"set_short", "Small sword",
				"set_alt_name", "sword" })
				});

::reset();
replace_program("room/room");
}
