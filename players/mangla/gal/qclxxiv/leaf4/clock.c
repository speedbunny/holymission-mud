inherit "/obj/treasure";
object tidemaster;

reset(arg) {
	if (!tidemaster) 
		set_tidemaster();
	if (arg) return;
	set_id("clock");
	set_short("An old clock");
}

long()  { 
	tidemaster->long();
}

get() { return 0; }

set_tidemaster() {
	tidemaster = present( "tidemaster",
					find_object("/players/qclxxiv/leaf4/grifroom"));
}

