inherit "/obj/treasure";

reset(arg) {
	if (arg) return;
	set_id("ink-bottle");
	set_alias("ink");
	set_weight(1);
	set_value(20);
	set_short("An ink-bottle"); 
	set_long("An ink-bottle. A nice portable indian ink-well.\n" );
}

