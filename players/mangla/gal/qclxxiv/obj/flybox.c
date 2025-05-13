#define PLAYERNAME this_player()->query_name()
int flies;
id(str) { return str == "box" || str == "fly box" || str == "box_1" ; }
short() { if (flies<=0) return "An empty fly box"; 
		return "fly box (containing "+flies+" flies)"; }
long()  { 
	write("A fly box for keeping telepatic flies.\n");
	write("The telepatic flies have been trained to be sent forward in\n"+
		"some direction and send back a view of where they arrive. This\n"+
		"way you can check some place without being harmed unexpectedly.\n");
	write("Also some other uses can be thought out by the smarter.\n");
	write("A fly can be send with command: fly <direction>.\n");
	write("It will show the view, but will not return once it is freed.\n");
	if (flies<=0) write("The fly box is empty.\n"); 
	else write( "The fly box contains "+flies+" flies.\n"); 
}
get()	{ return 1; }
query_weight() { return 1; }
query_value() { return flies*25; }

reset(arg) {
	if (arg) return;
	flies = 15;
	return 1;
}

init()  { 
	add_action("sendfly", "fly" );
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
	fly = clone_object("/players/qclxxiv/obj/telefly");
	flies--;
	move_object( fly, environment(this_player()) );
    say(PLAYERNAME+" sends out a telepatic fly.\n");
	call_other(fly,"set_sender",this_object()); 
	call_other(fly,"go_check",str); 
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
	for (i=0; i<sizeof(obj); i++)
		if (obj[i]->short()) write(obj[i]->short()+".\n");
	return 1;
}

