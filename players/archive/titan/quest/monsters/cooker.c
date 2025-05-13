	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("Cook");
	set_alias("man");
	set_race("human");
	set_gender(1);
	set_level(15);
	set_al(50);
	set_short("Cook");
	set_long("Chinese cook which now is cooking one of their national \n"
	+ "speciality. \n");

	load_chat(17,({
		"Cook mixures some dog's soup.\n",
		"Cook tastes soup.\n",
		"Cook stares into the soup.\n",
		"Cook gives some spice into the soup.\n"}));

	move_object(clone_object("players/titan/quest/items/ladle"),this_object());
	command("wield ladle",this_object());
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
