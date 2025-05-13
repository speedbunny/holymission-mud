inherit "obj/monster";
object mirror;

reset(arg){
   ::reset(arg);
   if(!arg){
	set_name("zombie priest");
	set_level(14);
	set_race("undead");
	set_alt_name("zombie");
	set_alias("priest");
	set_short("Zombie Priest");
	set_long("The zombie that stands before you is finely dressed in thick black\n" + "robes.  He has the markings of a priest of the Old Ones and that means\n" + "he has been around for centuries!\n");
	set_aggressive(1);
	load_chat( 8, ({
		"Priest yells: The Old ones shall rule again!\n",
		"Priest says: I curse your very soul!\n" }));
	set_dead_ob(this_object());
	set_spell_mess1("You feel your body rot as the Zombie touches you.\n");
	set_spell_mess2("Great pain shoots through your body!\n");
	set_chance(20);
	set_spell_dam(20);
  mirror=clone_object("players/airborne/obj/mirror");
  move_object(mirror, this_object());
    }
}
monster_died(ob){
	say("The powerof the Old Ones is dealt a mighty blow.\n");
	return 0;
}

