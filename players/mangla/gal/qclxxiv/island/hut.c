inherit "/players/qclxxiv/island/special";

reset(arg) {
	if (arg) return;
	set_inside("/players/qclxxiv/island/in_hut");
	set_id("hut");
	set_alias("old hut");
	set_weight(1000);
	set_short("An old hut"); 
	set_long(
"An old wooden hut. Its door has been removed long ago. It looks decayed.\n"
	);
	hollow = 1;
}
get() { return 0; }
