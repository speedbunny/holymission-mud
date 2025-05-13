inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("black monk");
	set_race("human");
	set_short("Black monk");
	set_long("This is a black monk, who dwells in the black art of making poisons\n"+
	  ", diseases and other potions.\n");
	set_alias("monk");
	set_level(25);
	set_al(-900);
	set_ac(15);
	set_wc(26);
    }
}
