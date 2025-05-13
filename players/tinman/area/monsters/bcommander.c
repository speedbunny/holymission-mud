inherit "obj/monster";
object gplate,lsword,ghelmet,gshield,boot,pant,gshield,gauntlet;


reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name("blue commander");
	set_alias("commander");
	set_short("A Blue Commander");
    set_long("Field commander of Liu Bei's army. Ranked closest to Liu Bei's\n"+
" generals. He fights through the battlefield like a madman.\n");
	set_level(55);
    set_gender(1);
	set_race("human");
	add_money(10000);
	set_n_wc(20);
	set_n_ac(30);
	set_number_of_arms(2);
    gplate=clone_object("/players/tinman/area/armors/gplate");
    move_object(gplate,this_object());
    boot=clone_object("/players/tinman/area/armors/boot");
    move_object(boot,this_object());
   ghelmet=clone_object("/players/tinman/area/armors/ghelmet");
   move_object(ghelmet,this_object());
   pant=clone_object("/players/tinman/area/armors/pant");
   move_object(pant,this_object());
    lsword=clone_object("/players/tinman/area/weapons/lsword");
    move_object(lsword,this_object());
    gshield=clone_object("/players/tinman/area/armors/gshield");
    move_object(gshield,this_object());
    gauntlet=clone_object("/players/tinman/area/armors/gauntlet");
    move_object(gauntlet,this_object());
command("powerup");
}

