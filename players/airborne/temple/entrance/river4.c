inherit "room/room";

reset(arg){
  set_light (1);
  dest_dir = ({"players/airborne/temple/entrance/river3", "upstream",
	       "players/airborne/temple/entrance/river5", "downstream",});
  short_desc = "River";
  long_desc = "The river bends to an east/west flow.\n"
	"Upstream flows from north to south and downstream drifts off to the west.\n";

   clone_list = ({ 1, 1, "demon", "obj/monster",
			({ "set_name", "water demon", 
			"set_alias", "demon",
			"set_race", "demon", 
			"set_level", 10, 
			"set_short", "Water Demon", 
			"set_long", "A foul looking demon of the waters below" 
				"is in front\nof you. Its black eyes and foul" 
				"stench can scare the hell\n out of you!\n", 
			"set_al", -50, 
			"set_aggressive", 1,
			"set_ac", 4,
			"set_wc", 12 }),
		-1, 1, "pearl", "players/airborne/obj/pearl", 0 });

::reset();
replace_program("room/room");

}
		

