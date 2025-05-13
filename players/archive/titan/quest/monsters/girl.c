	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("servant girl");
	set_alias("girl");
	set_living_name("dievcatko");
	set_race("human");
	set_gender(2);
	set_level(8);
	set_al(500);
	set_short("Servant girl");
	set_long("Beautiful girl which serves on castle since her slim childhood.\n"
	+ "She usual sweeps room.\n");

	move_object(clone_object("players/titan/quest/items/broom"),this_object());
	command("wield broom",this_object());

	load_chat(10,({		
		"Girl sweeps room.\n"}));
		
	call_out("wandering",30);
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
	wandering() {
	random_move(this_object());
	return 1;
}

