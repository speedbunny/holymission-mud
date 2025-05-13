inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("slave");
	set_race("human");
	set_short("Slave");
	set_long("A slave captured from battles and sent here to do work.\n");
	set_alias("slave");
	set_level(6);
	set_al(200);
	set_ac(1);
	set_wc(5);
    }
}
