	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("observer");
	set_race("human");
	set_level(17);
	set_alias("man");
	set_short("observer");
	set_long("This is one of many observers which examine surroundings of castle.\n");
	set_gender(1);
	set_whimpy(-1);

	load_chat(30,({
		"Observer shakes head no.\n",
		"Observer says: nothing, nothing\n",
		"Observer says: bad day\n",
		"Observer whistles old hit.\n",
		"Observer says: I am bored\n",
		"Observer looks at you.\n",
		"Observer yawns sleeply.\n"}));
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
