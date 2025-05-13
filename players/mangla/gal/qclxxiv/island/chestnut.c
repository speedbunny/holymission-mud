inherit "/players/qclxxiv/island/tree";

reset(arg) {
	if (arg) return;
	set_id("chestnut");
	set_alias("chestnut");
	set_weight(0);
	set_value(10);
	set_short("A chestnut");  
	set_long(
	"A chestnut, a grayish brown tree with its typical fingered leaves.\n" );
}

get() { return 0; }
