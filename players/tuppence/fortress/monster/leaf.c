inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("gold leaf");
	set_race("plant");
	set_short("Golden leaf");
	set_long("This leaf seems to be made out of gold, but it is alive.\n");
	set_alias("leaf");
	set_level(19);
	set_al(100);
	set_ac(9);
	set_wc(20);
    }
}
