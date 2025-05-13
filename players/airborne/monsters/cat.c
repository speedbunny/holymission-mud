inherit "/obj/monster";

reset(arg) {
	::reset(arg);
    if(arg) return 1;
	set_name("teufel");
	set_level(5);
	set_alias("cat");
	set_race("cat");
	set_whimpy(20);
	set_short("Teufel");
	set_long("Malia's cat 'Teufel'.  They seem to have an uncanny bond.\n");
	set_aggressive();
   return 1;
}
