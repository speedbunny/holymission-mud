inherit "obj/weapon";

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_id("pamphlet");
	set_alias("pamflet"); 
	set_class(9);
	set_weight(2);
	set_value(500);
}

get() { return 0; }

