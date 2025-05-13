	inherit "obj/monster";
	int i;
	string s;

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("minstrel");
	set_living_name("spevak");
	set_alias("singer");
	set_race("human");
	set_gender(1);
	set_level(23);
	set_al(50);
	set_short("minstrel");
	set_long("He looks like lives long time on abandoned island. He has long grey hair.\n"
		+ "His clothes is very dusty. He looks very experienced and his foreign accent\n"
		"tells you that this man visits many countries.\n");
	load_chat(14,({
		"Minstrel spits on ground.\n",
		"Minstrel tunes his lute.\n",
		"Minstrel whistles strange melody.\n",
		"Minstrel sings 'You are personal Jesus ... \n",
		"Minstrel is waiting apploud.\n",
		"Minstrel plays the lute.\n",
		"Minstrel yodels.\n",
		"Minstrel looks at you.\n",
		"Minstrel sings 'Free your mind ...\n"}));

	
	move_object(clone_object("players/titan/quest/items/lute"),this_object());
        command("wield lute",this_object());

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
