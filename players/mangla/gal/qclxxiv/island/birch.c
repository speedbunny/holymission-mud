inherit "/players/qclxxiv/island/tree";

reset(arg) {
	if (arg) return;
	set_id("birch");
	set_alias("birch");
	set_weight(0);
	set_value(10);
	set_short("A birch"); 
	set_long("A birch, with its petioled leaves.\n" );
}

get() { return 0; }
