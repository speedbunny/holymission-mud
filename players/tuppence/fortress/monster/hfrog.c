inherit "obj/monster";
void reset(int arg) {
::reset(arg);
    if(!arg){
	set_name("horned frog");
	set_race("frog");
	set_short("Horned frog");
	set_long("Evil horned frog with red horns looks at you with its evil eyes.\n");
	set_alias("frog");
	set_level(18);
	set_ac(8);
	set_wc(19);
	set_al(-160);
    }
}
