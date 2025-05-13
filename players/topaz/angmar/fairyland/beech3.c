/* 12.11.93 Airborne: Changed to room/room and clone_list */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc =  "The beech woods";
  long_desc = 
	"You are in the beech woods. The birds are singing.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/beech1","north" });
  clone_list = ({ 1, 1, "elfking", "obj/monster",
			     ({ "set_name", "elfking",
				"set_level", 17,
				"set_hp", 340,
                                "set_ac", 10,
				"set_short", "The elfking",
				"set_alias", "king",
				"set_alt_name", "elf",
				"set_al", 200,
				"set_long", 
				"Gee! That sword looks dangerous!\n" }),
                 -1, 1, "elfsword", "obj/weapon",
			     ({ "set_name", "elfsword",
				"set_short", "An elfsword",
				"set_long", "It looks very sharp.\n",
				"set_class", 17,
				"set_value", 1500,
				"set_weight", 2 })
				});

::reset();
replace_program("room/room");
}
