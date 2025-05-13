inherit "obj/monster";
object snake,gplate,ghelmet,gauntlet,pant,boot;

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Zhang Fei");
	set_alias("zhang");
	set_short("Zhang Fei, the Blue General");
	set_alt_name("fei");
    set_long("A large hot temper man dressed all in black. He is the blood"+
" brother of Guan Yu and Liu Bei and also one of Liu bei's great generals\n");
	set_level(70);
    set_gender(1);
	set_race("human");
	add_money(5000+random(5000));
	set_n_wc(25);
	set_n_ac(40);
    set_number_of_arms(2);
    snake=clone_object("/players/tinman/area/weapons/snake");
    move_object(snake,this_object());
    gplate=clone_object("/players/tinman/area/armors/gplate");
    move_object(gplate,this_object());
    ghelmet=clone_object("/players/tinman/area/armors/ghelmet");
    move_object(ghelmet,this_object());
    gauntlet=clone_object("/players/tinman/area/armors/gauntlet");
    move_object(gauntlet,this_object());
    pant=clone_object("/players/tinman/area/armors/pant");
    move_object(pant,this_object());
    boot=clone_object("/players/tinman/area/armors/boot");
    move_object(boot,this_object());
    command("powerup");
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
	tell_object(AO, "Zhang Fei stabs you through your stomach with his"+
	" Snake Spear!\n");
	say("Zhang Fei stabs "+AO->query_name()+" through the stomach with his "+
"Snake Spear!\n",AO);
	    AO->hit_player(40+random(25));
	}
	else if (!random(6)) {
	tell_object(AO, "Zhang Fei slashes you across the face spilling blood\n");
	say("Zhang Fei slashes "+AO->query_name()+" across the face spilling blood!\n",AO);
	AO->hit_player(20+random(30));
	}
    }
}


