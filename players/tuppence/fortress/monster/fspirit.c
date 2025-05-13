inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("fire spirit");
	set_race("spirit");
	set_short("Fire spirit");
	set_long("This spirit seems to have come from hades. The magical heat flows\n"+
	  "from it.\n");
	set_alias("spirit");
	set_aggressive(1);
	set_level(19);
	set_al(-100);
	set_ac(7);
	set_wc(23);
    }
}
