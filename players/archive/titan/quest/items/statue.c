	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("statue");
	set_weight(50);
	set_short("Statue of Medusa");
	set_long("Statue of evil Medusa. You should leave quickly\n" +
		"because Medusa is still alive.\n");
	call_out("back",20+random(20));
}
	back() {
	tell_room(environment(this_object()),"Statue suddenly blasted.\n");
	call_out("back1",2);
	return;
}
	back1() {
	object meduska;
	tell_room(environment(this_object()),"Medusa shouts: I AM BACK AGAIN !!!\n");
	meduska=clone_object("players/titan/quest/monsters/medusa");
	transfer(meduska,environment(this_object()));
	tell_room(environment(this_object()),"Medusa laughs devilish at you.\n");
	destruct(this_object());
	return 1;
}

