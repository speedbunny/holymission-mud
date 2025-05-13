/* 12.12.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "Walking in the Darkwood";
  long_desc = 
	"You are walking somewhere the Darkwood. It's almost pitch black.\n"+
	"Are there any nasty monsters lurking around here?\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/dw_path4", "north" });
  clone_list = ({ 1, 1, "witch", "obj/monster",
			     ({ "set_name", "witch",
				"set_level", 14,
				"set_sp", 400,
				"set_ac", 8,
				"set_short", "A nasty witch",
				"set_long",
				"This witch is not to be tampered with.\n",
				"set_al", -200,
				"set_spell_mess1",
		"The witch stares at you...\n"+"You feel a sudden pain",
                                "set_spell_mess2",
		"The witch stares at you...\n"+"You feel a sudden pain",
                  		"set_chance", 30,
				"set_spell_cost", 20 }),
			-1, 1, "broom", "obj/weapon",
			     ({ "set_name", "broom",
				"set_short", "A broom",
				"set_long", 
				"This broom once belonged to a witch.\n",
				"set_class", 12,
				"set_value", 400,
				"set_weight", 1 })
				});

::reset();
replace_program("room/room");
}
