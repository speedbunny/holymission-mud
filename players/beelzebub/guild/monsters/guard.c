inherit "obj/monster";
reset(arg) {
	::reset(arg);
	if (arg) return;
set_name("guard");
set_level(16);
set_ep(10000);
	set_gender(1);
set_race("human");
set_short("A Dragon guard.");
set_long("A large guard in a karate gi.  He looks adept in fighting.\n");
add_money(150);
}
