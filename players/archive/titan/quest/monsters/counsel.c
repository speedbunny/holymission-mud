	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("counsel");
	set_race("human");
	set_alias("wizard");
	set_level(50);
	set_al(1500);
	set_short("counsel");
	set_long("This is old man with white beard and long\n"
	       + "grey hair. His robe is black like night sky\n"
	       + "with strange signs. He must be very wise \n"
	       + "because he is student of great wizard.\n");
	add_money(40000);
	load_chat(15,({
		"Counsel turns page.\n",
		"Counsel says: It's real thing.\n",
		"Counsel asks: Can I help you ?\n",
		"Counsel studies old book.\n",
		"Counsel looks at shelves.\n",
		"Counsel opens some book.\n",
		"HHHHMMMM.\n",
		"Counsel asks you: Any questions for me ?\n",
		"Counsel asks you: Do you heard about princess ?\n"}));
	move_object(clone_object("/players/titan/quest/items/mirror"),this_object());
}
	attack() {
	object utocnik;
	utocnik=this_player()->query_attack();

	if(::attack()) {
       	if(!present("kill_thing",utocnik)) {
	move_object(clone_object("players/titan/quest/items/kill_thing"),utocnik);
}
	tell_room(environment(this_object()),"Counsel vanished before your eyes.\n");
	destruct(this_object());
}
	return 1;
}
	catch_tell(arg) {
	string str1;
	object zrkadlo;

	if((sscanf(arg,"%s help %s",str1)==1)||(sscanf(arg,"%s help",str1)==1)) {
	if(!present("silver mirror",this_player())) {
	write("Counsel have gave you small silver mirror.\n");
	zrkadlo=present("silver mirror",this_object());
	destruct(zrkadlo);
	move_object(clone_object("players/titan/quest/items/mirror"),this_player());
}
	else {
	write("I see that you have already one silver mirror.\n");
}
	call_out("rec",3);
}
	return 1;
}
	rec() {
	write("Counsel friendly looks at you.\n"); 
	write("Counsel tells you: This small silver mirror protect you before evil eyes.\n");
	write("Counsel tells you: But you must show it and evil will be defeated.\n");
}                                                 
