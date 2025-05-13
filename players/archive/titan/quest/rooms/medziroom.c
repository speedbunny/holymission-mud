	inherit "room/room";


	reset (arg) {

	set_light(1);
	short_desc = "V oblakoch.";
	long_desc = "You are somewhere between heaven and earth.\n";
	no_obvious_msg="";
}
	init() {
	::init();
	call_out("flying",3);
}
	flying() {
	write("You are flying on the gigantic vulture.\n");
        shout(this_player()->query_name()+" flying on the gigantic vulture across Holy Mission.\n");
	call_out("flying1",3);
}
	flying1() {
	write("You see deep bellow you shadow of your vulture.\n");
	call_out("flying2",3);
}
	flying2() {
	write("You feel that you are flying lower and lower.\n");
	call_out("flying3",3);
}
	flying3() {
	object nicota;
	nicota=present("nomotion",this_player());
	destruct(nicota);
	this_player()->move_player("\b\b\b\b\b\b\blanded#players/titan/quest/rooms/clearing");
	write("Gigantic vulture landed near a beautiful lake.\n");
	write("You dismount from the vulture.\n");
	say(this_player()->query_name()+" dismount from the vulture.\n");
	tell_room("players/titan/quest/rooms/clearing","Vulture waved with its massive wings and fly away.\n");
	return 1;
}	

