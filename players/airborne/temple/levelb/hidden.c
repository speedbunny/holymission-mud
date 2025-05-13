inherit "room/room";

reset(arg){
  set_light(0);
  dest_dir = ({"players/airborne/temple/levelb/throne", "south"});
  short_desc = "Small room";
  long_desc = "This is an empty room. Wonder what it was used for.\n";
  clone_list = ({ 1, 1, "crown", "obj/armour", 
			({ "set_name", "crown",
			"set_type", "helmet", 
			"set_id", "crown",
			"set_alias", "crown",
			"set_short", "Golden crown",
			"set_ac", 0,
			"set_value", 100,
			"set_short", "Golden crown",
		"set_long", "A golden crown that looks for for a king.\n",}), });
                                                                              
::reset();
replace_program("room/room");
}
