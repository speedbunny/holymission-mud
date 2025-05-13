inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("hound");
	set_race("dog");
	set_short("Hound");
	set_long("This hound is here to help the guards keep the slaves in line.\n");
	set_alias("hound");
	set_level(18);
	set_al(-100);
	set_ac(8);
	set_wc(19);
    }
}
