#define LEAF4 "/players/qclxxiv/leaf4/"
object regionmaster, tidemaster;
id(str) { return str == "tidemon"; }
short() { return "A tidemon"; }
long()  { write("commands: print_heights, print_tide\n"); }
get()	{ return 1; }
query_weight() { return 0; }

reset(arg) {
	if (!regionmaster) 
		set_regionmaster();
	if (!tidemaster) 
		set_tidemaster();
}

init()  { 
	add_action("print_heights", "print_heights" );
	add_action("print_tide", "print_tide" );
}

print_heights(arg) {
	if (!regionmaster) write("no regionmaster!\n");
	regionmaster->print_heights(arg);
	return 1;
}

print_tide(arg) {
	if (!tidemaster) write("no tidemaster!\n");
	tidemaster->print_tide(arg);
	return 1;
}

set_regionmaster() {
	regionmaster = present( "regionmaster",
					find_object("/players/qclxxiv/leaf4/grifroom"));
}

set_tidemaster() {
	tidemaster = present( "tidemaster",
					find_object("/players/qclxxiv/leaf4/grifroom"));
}
