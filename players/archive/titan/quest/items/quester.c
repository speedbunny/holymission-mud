	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("quester");
	set_short("Pomuocka");
	set_long("Spravenie questu 'sprav <meno>'\n"
		 "Zvysenie skillov 'zvys <meno skilu>'\n");
	set_alias("Titanov quester");
}
	init() {
	::init();
	add_action("done","sprav");
	add_action("skills","zvys");
}
	done(str) {
	this_player()->set_quest(str);
	return 1;
}
	skills(str) {
	int sk;
	sk = this_player()->query_name()->increase_skill95(this_player(),
	this_player()->get_spell_skill(str),95);
	this_player()->set_spell_skill(str,sk);
	return (sk);
}
