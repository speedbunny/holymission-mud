inherit "obj/monster";
object plate,ssword;


reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("red soldier");
	set_alias("soldier");
	set_short("A Red Soldier");
    set_long("The normal soldiers that make up a large part of Cao Cao's red army."+
" They are not weak for they are heavily trained and moraled to fight til he\n"+
" or his enemies die.\n");
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

