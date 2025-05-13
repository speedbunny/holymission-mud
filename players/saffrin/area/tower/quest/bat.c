/* coded by Llort */
/* Spruced up by Saffrin */

inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg) {

	set_name("bat");

	set_short("A vampire bat");

	set_alias("vampire bat");

	set_long("A vampire bat that is flying around your head in circles.\n"+
	  "It looks like it is lunging for your neck.\n");

	set_race("bat");

	set_level(1);

	set_wc(6);

	set_whimpy(50);

	set_size(1);

	set_al(-10);
    }
}
init() {
    if (set_light(0) > 0) {
	tell_room(environment(),"The bat gets angry !!!\n");
	attack_object(this_player());
    }
    ::init();
}

