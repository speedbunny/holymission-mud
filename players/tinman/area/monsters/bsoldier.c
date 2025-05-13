inherit "obj/monster";
object plate,ssword;


reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("blue soldier");
	set_alias("soldier");
	set_short("A Blue Soldier");
    set_long("Normal foot soldiers of Liu Bei's blue army. Becareful that\n" +
" you don't get involve in this war. He might kill you in the heat of the\n" +
" battle.\n");
	set_level(22);
    set_gender(1);
	set_race("human");
	add_money(200);
	set_wc(10);
	set_ac(4);
	set_number_of_arms(2);
    plate=clone_object("/players/tinman/area/armors/plate");
    move_object(plate,this_object());
    ssword=clone_object("/players/tinman/area/weapons/ssword");
    move_object(ssword,this_object());
command("powerup");
}

