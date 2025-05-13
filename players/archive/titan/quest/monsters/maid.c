	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(!arg) {

	set_name("maid");
	set_alias("woman");
	set_level(5);
	set_al(100);
	set_hp(150);
	set_race("human");
	set_gender(2);
	set_short("Old maid");
	set_long("You see old maid which serve on castle many years.\n");
	set_whimpy(90);
	move_object(clone_object("players/titan/quest/items/needle"),this_object());
	move_object(clone_object("players/titan/quest/items/duster"),this_object());
}}
	attack() {
	object utocnik;
	utocnik=this_player()->query_attack();

  	if(::attack()) {
       	if(!present("kill_thing",utocnik)) {
	move_object(clone_object("players/titan/quest/items/kill_thing"),utocnik);
}}
	return 1;
}
	init() {
	::init();
	add_action("kiss","kiss");
}
	object ihla;
	kiss(str) {
	if(!str) {
	notify_fail("Kiss whom ?\n");
	return 0;
}
	if(str=="maid") {
	write("You kiss old maid.\n");
	write("Oh !!! 'Whats happen ?' asked maid surprisely.\n");
	say("Oh !!! 'Whats happen ?' asked maid surprisely.\n");
	ihla=present("needle",this_object());
	destruct(ihla);
	move_object(clone_object("players/titan/quest/items/needle"),environment(this_object()));
	return 1;
}}
