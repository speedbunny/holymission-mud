inherit "obj/monster";
void reset(int arg) {
    ::reset(arg) ;
    if(!arg) {
	set_name("water sprite");
	set_race("sprite");
	set_short("Water sprite");
	set_long("This small water sprite flys around on top of the water.\n");
	set_alias("sprite");
	set_level(16);
	set_al(400);
	set_ac(5);
	set_wc(16);
    }
}
