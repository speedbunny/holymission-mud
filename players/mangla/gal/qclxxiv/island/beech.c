inherit "/players/qclxxiv/island/tree";

reset(arg) {
	if (arg) return;
	set_id("beech");
	set_alias("beech");
	set_weight(0);
	set_value(10);
	 set_short("A beech");  
	set_long("A beech, a hardwood tree with smooth gray bark.\n" );
}

get() { return 0; }
