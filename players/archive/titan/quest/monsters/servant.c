 inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("feeder");
	set_race("human");
	set_level(12);
	set_al(50);
	set_short("Feeder");
	set_long("Young man with friendly looking eyes. His care is help everywhere where\n"
	+ "need. Usual he works in stable.\n");
}
	attack() {
	object utocnik;
	utocnik=this_player()->query_attack();

  	if(::attack()) {
       	if(!present("kill_thing",utocnik)) {
	move_object(clone_object("players/titan/quest/items/kill_thing"),utocnik);
}}
	return 1;
}
