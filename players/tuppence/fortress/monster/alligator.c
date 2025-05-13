inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    if(!arg) {
	set_name("alligator");
	set_race("reptil");
	set_short("Alligator");
	set_long("A big black alligator stares at you with yellow piercing eyes.\n");
	set_alias("alligator");
	set_level(19);
	set_al(-600);
	set_ac(7);
	set_wc(20);
    }
}
