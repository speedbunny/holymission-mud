inherit "obj/monster";
object splate,lsword,helmet,boot;


reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name("red sergeant");
	set_alias("sergeant");
	set_short("A red Sergeant");
    set_long("Loyal training sergeant of Cao Cao's red army. He is hacking\n"+
"away at a blue soldier.\n");
	set_level(26);
    set_gender(1);
	set_race("human");
	add_money(1400);
	set_wc(11);
	set_ac(5);
	set_number_of_arms(2);
    splate=clone_object("/players/tinman/area/armors/splate");
    move_object(splate,this_object());
    boot=clone_object("/players/tinman/area/armors/boot");
    move_object(boot,this_object());
    helmet=clone_object("/players/tinman/area/armors/helmet");
    move_object(helmet,this_object());
    lsword=clone_object("/players/tinman/area/weapons/lsword");
    move_object(lsword,this_object());
command("powerup");
}

