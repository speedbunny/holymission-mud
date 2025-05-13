	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(!arg) {

	set_name("octopus");
	set_level(37);
	set_size(3);
	set_al(-100);
	set_race("fish");
	add_money(3000);
	set_short("Poisonous octopus");
	set_long("Big poisonous octopus lazy sits near you.\n"+
		"It looks dangerous.\n");
	set_aggressive(0);
	set_no_steal(); /* sneak is accept */
}}
	attack() {
	object utocnik;
	utocnik=this_player()->query_attack();

        if(::attack()) {
	if(random(100)<10) {
	say(this_object()->query_name()+" lets off strange liquid.\n");
	write("Octopus lets off black liquid.\n");
	utocnik->add_poison(utocnik->query_level()-3);
}}
	return 1;
}
	
