inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("Angry lizard");
	set_race("lizard");
	set_short("Mad lizard");
	set_long("He is angry that you have dared enter. He is the mate of the evil\n"+
	  "moat monster Silthar.\n");
	set_alias("lizard");
	set_aggressive(1);
	set_level(29);
	set_al(-900);
	set_ac(13);
	set_wc(20);
    }
}
