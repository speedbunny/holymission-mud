	inherit"obj/monster";

	void reset(int arg) {
	::reset(arg);
	if(arg) return;
	set_name("salmon");
	set_alias("zmrd");
	set_race("fish");
	set_short("Sea salmon");
	set_long("This is big salmon. He appears very angry.\n");
	set_level(12);
	set_hp(500);
	set_wimpy(50);
	set_has_gills();
	set_aggressive(0);

	move_object(clone_object("players/titan/quest/items/sextract"),this_object());
}
