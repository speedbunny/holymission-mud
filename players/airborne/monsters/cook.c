inherit "obj/monster";
reset(arg){
 object pot;
	::reset(arg);
	if(arg) return 1;
	set_name("cook");
	set_alias("lizardman");
	set_short("Lizardman cook");
	set_long("The lizardman looks to weak to fight, so they made him the cook!\n");
	set_level(3);

	set_race("lizardman");
   pot = clone_object("players/airborne/armours/pothelm");
  move_object(pot, this_object());
	return 1;
	}
