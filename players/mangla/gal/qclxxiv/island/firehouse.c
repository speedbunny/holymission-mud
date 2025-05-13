inherit "/players/qclxxiv/island/special";

reset(arg) {
	if (arg) return;
	set_inside("/players/qclxxiv/island/in_firehouse");
	set_id("firehouse");
	set_alias("old firehouse");
	set_weight(1000);
	set_short("An old firehouse"); 
	set_long(
"An old firehouse. It looks decayed. The door has been removed long ago.\n"
	 );
	hollow = 1;
}

get() { return 0; }

