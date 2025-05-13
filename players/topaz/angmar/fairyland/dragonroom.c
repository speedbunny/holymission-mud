/* 12.13.93 Airborne: Changed to room/room and clone_list */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "In the dragons cave";
  long_desc =
	"This is where the great dragon lives and hoards his treasures.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/tunnel","south" });
  clone_list = ({ 1, 1, "dragon", "obj/monster",
			     ({	"set_name", "dragon",
				"set_level", 22,
				"set_hp", 800,
				"set_wc", 23,
				"set_ac", 10,
				"set_al", -200,
				"set_short", "A large red dragon",
				"set_long", 
				"A huge dragon. His name is Rumburak.\n",
                                "set_size", 5,
				"set_alias", "rumburak",
				"set_spell_mess1", "The dragon breathes fire!",
				"set_spell_mess2",
                                "The dragon breathes fire at you!",
				"set_chance", 30,
				"set_spell_dam", 50 }),
			-1, 1, "chainmail", "obj/armour",
                             ({ "set_name", "chainmail", 
				"set_short", "mithril chainmail",
				"set_long", "It looks very light.\n",
				"set_alias", "mithril chainmail",
				"set_value", 1000,
				"set_weight", 1,
				"set_size", 3,
				"set_ac", 4,
				"set_type", "armour" })
				});

::reset();
replace_program("room/room");
}
