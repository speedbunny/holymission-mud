inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("baby");
	set_race("reptile");
	set_short("Lizard baby");
	set_long("This is the baby of the horrible moat monster silthar.\n");
	set_alias("baby");
	set_level(15);
	set_ac(6);
	set_wc(15);
	set_al(-100);
    }
}
