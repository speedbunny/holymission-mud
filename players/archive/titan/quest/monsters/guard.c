	inherit "obj/monster";
	object we,ar;
#define CESTA "/players/titan/quest/items/kill_thing"

	reset(arg) {
	::reset(arg);
	if(!arg) {

	set_name("guard");
	set_alias("human");
	set_race("human");
	set_level(20);
	set_al(50);
	set_wimpy(-1);
	set_aggressive(0);
	set_gender(1);
	set_short("Guard");
	set_long("This guard is member of King's patrol.\n");
	set_size(2);
	set_wc(25);
	set_ac(20);
	set_hp(1100);

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
	command("wield sword",this_object());
	command("wear armour",this_object());
}}
	attack() {
	object utocnik;
	utocnik=this_player()->query_attack();

  	if(::attack()) {
       	if(!present("kill_thing",utocnik)) {
	move_object(clone_object(CESTA),utocnik);
}}
	return 1;
}
	init() {
	::init();
	if(present("kill_thing",this_player())) {
	attack_object(this_player());
}
	return 1;
}
