	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("lackey");
	set_alias("footman");
	set_race("human");
	set_gender(1);
	set_level(13);
	set_short("lackey");
	set_long("Old lackey with grey hair. His eyes are sadly and glitter by tear.\n"
	+ "When princes Silvia losts he begin drink.\n");

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
