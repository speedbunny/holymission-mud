inherit "obj/monster";
object splate,lsword,shield,gauntlet,boot;


reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("blue guard");
	set_alias("guard");
	set_short("A Blue Guard");
    set_long("A strong blue guard will the skills to be trusted in guarding"+
" the most valuable tents. He is looking at you suspicously.\n");
	set_level(25);
    set_gender(1);
	set_race("human");
	add_money(200);
	set_wc(15);
	set_ac(5);
	set_number_of_arms(2);
   splate=clone_object("/players/tinman/area/armors/splate");
    move_object(splate,this_object());
    lsword=clone_object("/players/tinman/area/weapons/lsword");
    move_object(lsword,this_object());
   gauntlet=clone_object("/players/tinman/area/armors/gauntlet");
   move_object(gauntlet,this_object());
   shield=clone_object("/players/tinman/area/armors/shield");
   move_object(shield,this_object());
   boot=clone_object("/players/tinman/area/armors/boot");
   move_object(boot,this_object());
command("powerup");
}

