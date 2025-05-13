#define PLAYERNAME this_player()->query_name()

int flies;
object thelastfly;
id(str) { return str == "box" || str =="smart fly box"; }
short() { if (flies<=0) return "An empty fly box"; 
		return "smart fly box (containing "+flies+" Smart flies)"; }
long()  { 
	write("A fly box for keeping Smart telepatic flies.\n");
	write("The telepatic flies have been trained to i.e. be sent forward in\n"+
		"some direction and send back a view of where they arrive. This\n"+
		"way you can check some place without being harmed unexpectedly.\n");
	write("A fly can be send with command: fly <direction>.\n");
	write("It will show the view, but will not return once it is freed.\n");
	write(
"Instead of directions, these smarter flies also accept further commands.\n");
write("However in their current training stage they merely dig directions.\n");
write("But you can lastfly them around and check out area's.\n");
write("To command the latest freed fly: 'lastfly <command>'.\n");
	if (flies<=0) write("The fly box is empty.\n"); 
	else write( "The fly box contains "+flies+" flies.\n"); 
}
get()	{ return 1; }
query_weight() { return 1; }
query_value() { return flies*700; }

reset(arg) {
	if (arg) return;
	flies = 3;
	return 1;
}

init()  { 
	add_action("sendfly", "fly" );
	add_action("lastfly", "lastfly" );
	add_action("lastflyfollow", "lastflyfollow" );
	add_action("lastflyprefix", "lastflyprefix" );
	add_action("lastflydest", "lastflydest" );
}

sendfly(str) {
	object fly;
	if (!str) { return 0; }
	if (flies<=0) {
		write("All flies have been used. Time to buy a new box!.\n");
    	say(PLAYERNAME + " peers in an empty fly box.\n");
		return 1;
	}
	write("You send out a telepatic fly.\n");
	fly = clone_object("/players/qclxxiv/obj/myfly");
	flies--;
	move_object( fly, environment(this_player()) );
    /*say(PLAYERNAME+" sends out a telepatic fly.\n");*/
	call_other(fly,"set_sender",this_object()); 
	call_other(fly,"go_check",str); 
	thelastfly = fly;
	return 1;
}

lastfly(str) {
	if (!str) { return 0; }
	if (!thelastfly) {
		write("You did not send out a fly, or it has died or so.\n");
		return 1;
	}
	call_other(thelastfly,"go_check",str); 
	return 1;
}

lastflyfollow(str) {
	object obj;
	if (!str) { return 0; }
	if (!thelastfly) {
		write("You did not send out a fly, or it has died or so.\n");
		return 1;
	}
	obj=find_living(str);
	if (obj) {
		thelastfly->set_followed(obj);
	}
	else {
		write("Can't find any living "+str+".\n");
		thelastfly->set_follow(0);
	}
	return 1;
}

lastflyprefix(str) {
	object obj;
	if (!str) { return 0; }
	if (!thelastfly) {
		write("You did not send out a fly, or it has died or so.\n");
		return 1;
	}
	thelastfly->set_prefix(str);
	return 1;
}


lastflydest() {
	if (!thelastfly) {
		write("You did not send out a fly, or it has died or so.\n");
		return 1;
	}
	thelastfly->self_dest();
	return 1;
}

/* fly is supposed to call back the box with as arg: it's environment */
/* Box can then actually show player the fly's env. */
receivefly(arg)
{
	int i;
	object obj;
	write("The fly shows you the following view:\n");
	arg->long();
	obj = all_inventory(arg);
	for (i=0; i<sizeof(obj); i++) {
		/* filter out ppl sitting on chairs etc. */
		/* as chairs do display them already.    */
		/* also filter out things we are sitting on ourselves */
		if (living(obj[i])) {
			if (present("qchairsoul",obj[i])) 
				continue;
		}
		if (obj[i]->short()) write(obj[i]->short()+".\n");
	}
	return 1;
}

