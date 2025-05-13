inherit "obj/monster";
object mshield;
void reset(int arg) {
    ::reset(arg);
    if(!arg) {
	set_name("purple fungus");
	set_race("fungus");
	set_short("purple fungus");
	set_long("This purple fungus crawls around on its spoores.\n");
	set_alias("fungus");
	set_level(20);
	set_al(400);
	set_ac(8);
	set_wc(20);
	mshield = clone_object("/players/tuppence/fortress/armour/mshield.c");
	transfer(mshield,this_object());
	init_command("wear shield");
    }
}
