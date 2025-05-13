inherit "obj/monster";
object splate,lsword,helmet,shield;


reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("red lieutenant");
	set_alias("lieutenant");
	set_short("A Red Lieutenant");
    set_long("A war experienced profressional that has climbed the ladder of\n" +
" order and success. He fights very well and Cao Cao knows this.\n");
	set_level(27);
    set_gender(1);
	set_race("human");
	add_money(1500);
	set_wc(11);
	set_ac(6);
	set_number_of_arms(2);
    splate=clone_object("/players/tinman/area/armors/splate");
    move_object(splate,this_object());
    shield=clone_object("/players/tinman/area/armors/shield");
    move_object(shield,this_object());
    helmet=clone_object("/players/tinman/area/armors/helmet");
    move_object(helmet,this_object());
    lsword=clone_object("/players/tinman/area/weapons/lsword");
    move_object(lsword,this_object());
command("powerup");
}

