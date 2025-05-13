	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("whale shark");
	set_alias("shark");
	set_race("fish");
	set_has_gills();
	set_level(25);
	set_wc(40);
	set_ac(4);
	set_size(5);
	set_hp(3000);
	set_al(-400);
	set_short("a whale shark");
	set_long("You see gigantic shark with dangerous teeth.\n");
	set_aggressive(1);
	if(intp(experience)) {
	experience = experience * 3;
}

	set_chance(30);
	set_spell_mess2("Shark makes CAK CAK CAK CAK CAK with teeth.\n\n");
	set_spell_mess1("Shark makes CAK CAK CAK CAK CAK with teeth.\n\n");
	set_spell_dam(random(50));

	move_object(clone_object("players/titan/quest/items/hteeth"),this_object());
	command("wield teeth",this_object());
}

	monster_died(ob) {
	tell_room("Shark last slaps with teeth and then die.\n");
}
