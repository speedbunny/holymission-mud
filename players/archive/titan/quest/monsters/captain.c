	inherit "obj/monster";
#define CESTA "/players/titan/quest/items/kill_thing"
	object we,ar;

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("captain");
	set_alias("soldier");
	set_race("human");
	set_gender(1);
	set_level(23);
	set_hp(1500);
	set_al(100);
	add_money(505);
	set_short("Captain of king's patrol");
	set_long("Captain is man in middle age. His athletic body\n"
		 "tells you about his brutal force, but he looks\n"
		 "intelligent. His main care is gate guarding.\n");
	set_spell_mess1("Captain bashs his opponent with shield !\n");
	set_spell_mess2("Captain bashs you with shield.\n");
	set_chance(30);
	set_spell_dam(25);

	ar=clone_object("obj/armour");
	ar->set_name("platemail");
	ar->set_alt_name("platemail of Hogan");
	ar->set_alias("plate");
	ar->set_short("Platemail of Hogan");
	ar->set_long("A beautiful armour probably it made long time ago.\n");
	ar->set_type("armour");
	ar->set_size(0);
	ar->set_ac(4);
	ar->set_value(1000);
	ar->set_weight(4);

	we=clone_object("obj/weapon");
	we->set_name("Sword of Hogan");
	we->set_alias("sword");
	we->set_short("Sword of Hogan");
	we->set_long("You see strange dark sword.\n");
	we->set_class(20);
	we->set_weight(3);
	we->set_value(2000);
	transfer(we,this_object());
	transfer(ar,this_object());
	move_object(clone_object("/players/titan/quest/items/helm"),this_object());
	move_object(clone_object("/players/titan/quest/items/shield"),this_object());
	move_object(clone_object("/players/titan/quest/items/boots"),this_object());
	command("wield sword",this_object());
	command("wear armour",this_object());
	command("wear helmet",this_object());
	command("wear shield",this_object());
	command("wear boots",this_object());
}
	attack() {
	object utocnik;
	utocnik=this_player()->query_attack();

  	if(::attack()) {
       	if(!present("kill_thing",utocnik)) {
	move_object(clone_object(CESTA),utocnik);
}}
	return 1;
}
	hit_player(dam) {
	if(dam<15) {
	write("The captain parries your attack with shield.\n");
	say("The captain parries "+this_player()->query_attack()->query_name()+"'s attack with shield.\n");
	return;
}
	return ::hit_player(dam);
}
	init() {
	::init();
	if(present("kill_thing",this_player())) {
	attack_object(this_player());
}
	return 1;
}
