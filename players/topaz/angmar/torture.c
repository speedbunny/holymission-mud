/* 12.11.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc =  "Torture chamber";
  long_desc =
	"This is the torturechamber of the castle. Around the walls\n"
	"hang various tools for inflicting as much pain as possible to\n"
	"the victims. Their screams still seem to linger in the air.\n";
  dest_dir = ({ "players/topaz/angmar/downstairs", "north" });
  clone_list = ({ 1, 1, "whip", "obj/weapon",
			    ({  "set_name", "whip",
				"set_short", "A whip",
				"set_long", 
			"A leather whip. It is black with dried blood.\n",
				"set_class", 6,
				"set_weight", 1,
				"set_value", 15 })
				});

::reset();
replace_program("room/room");
}
