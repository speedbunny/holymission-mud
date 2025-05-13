#define PLAYERNAME this_player()->query_name()

int cockroaches;
object thelastcockroach;
id(str) { return str == "box" || str =="smart cockroach box"; }
short() { if (cockroaches<=0) return "An empty cockroach box"; 
		return "smart cockroach box (containing "+cockroaches+" Smart cockroaches)"; }
long()  { 
	write("A cockroach box for keeping Smart telepatic cockroaches.\n");
	write("The telepatic cockroaches have been trained to i.e. be sent forward in\n"+
		"some direction and send back a view of where they arrive. This\n"+
		"way you can check some place without being harmed unexpectedly.\n");
	write("A cockroach can be send with command: cockroach <direction>.\n");
	write("It will show the view, but will not return once it is freed.\n");
	write(
"Instead of directions, these smarter cockroaches also accept further commands.\n");
write("However in their current training stage they merely dig directions.\n");
write("But you can lastcockroach them around and check out area's.\n");
write("To command the latest freed cockroach: 'lastcockroach <command>'.\n");
	if (cockroaches<=0) write("The cockroach box is empty.\n"); 
	else write( "The cockroach box contains "+cockroaches+" cockroaches.\n"); 
}
get()	{ return 1; }
query_weight() { return 1; }
query_value() { return cockroaches*1250; }

reset(arg) {
	if (arg) return;
	cockroaches = 3;
	return 1;
}

init()  { 
	add_action("sendcockroach", "cockroach" );
	add_action("lastcockroach", "lastcockroach" );
}

sendcockroach(str) {
	object cockroach;
	if (!str) { return 0; }
	if (cockroaches<=0) {
		write("All cockroaches have been used. Time to buy a new box!.\n");
    	say(PLAYERNAME + " peers in an empty cockroach box.\n");
		return 1;
	}
	write("You send out a telepatic cockroach.\n");
	cockroach = clone_object("/players/qclxxiv/obj/telecockroach");
	cockroaches--;
	move_object( cockroach, environment(this_player()) );
    say(PLAYERNAME+" sends out a telepatic cockroach.\n");
	call_other(cockroach,"set_sender",this_object()); 
	call_other(cockroach,"go_check",str); 
	thelastcockroach = cockroach;
	return 1;
}

lastcockroach(str) {
	if (!str) { return 0; }
	if (!thelastcockroach) {
		write("You did not send out a cockroach, or it has died or so.\n");
		return 1;
	}
	call_other(thelastcockroach,"go_check",str); 
	return 1;
}

/* cockroach is supposed to call back the box with as arg: it's environment */
/* Box can then actually show player the cockroach's env. */
receivecockroach(arg)
{
	int i;
	object obj;
	write("The cockroach shows you the following view:\n");
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

