	inherit "obj/monster";
	int i;

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("nixie");
	set_race("human");
	set_alias("nymph");
	set_level(15);
	set_al(-1000);
	set_gender(2);
	set_short("nixie");
	set_long("Water nixie which lives in nerly lake.\n");
}
	init() {
	::init();
	add_action("daj","give");
}
	daj(str) {
	object nahrdelnik;
	if(str=="necklace to nixie"&&present("necklace",this_player())) {	
	if(this_player()->query_gender_string()=="male") {
	write("Nixie tells you: thank you my hero\n");
}
	if(this_player()->query_gender_string()=="female") {
	write("Nixie tells you: thank you my heroin\n");
}
	if(this_player()->query_gender_string()=="neuter") {
	write("Nixie tells you: thank you monster :)\n");
} 
	move_object(clone_object("players/titan/quest/items/sleeping_thing"),this_player());
	write("Nixie happily waves to you and disappears in puff of smoke.\n");
	nahrdelnik=present("necklace",this_player());
	destruct(nahrdelnik);
	destruct(this_object());
	return 1;
}}
	
