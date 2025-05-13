inherit "obj/monster";
object wmace,gplate,ghelmet,gauntlet,pant,boot,shield;

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name("Xu Zhu");
	set_alias("xu");
	set_short("Xu Zhu, the Red General");
	set_alt_name("zhu");
    set_long("A large man with big muscles able to bring you in half. He is"+
" one of Cao Cao's best generals. He is almost as good as Zhang Fei\n");
	set_level(67);
    set_gender(1);
	set_race("human");
	add_money(4000+random(5000));
	set_n_wc(20);
	set_n_ac(30);
    set_number_of_arms(2);
    wmace=clone_object("/players/tinman/area/weapons/wmace");
    move_object(wmace,this_object());
    gplate=clone_object("/players/tinman/area/armors/gplate");
    move_object(gplate,this_object());
    ghelmet=clone_object("/players/tinman/area/armors/ghelmet");
    move_object(ghelmet,this_object());
    gauntlet=clone_object("/players/tinman/area/armors/gauntlet");
    move_object(gauntlet,this_object());
    pant=clone_object("/players/tinman/area/armors/pant");
    move_object(pant,this_object());
    shield=clone_object("/players/tinman/area/armors/gshield");
    move_object(shield,this_object());
    boot=clone_object("/players/tinman/area/armors/boot");
    move_object(boot,this_object());
    command("powerup");
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
	   tell_object(AO, "Xu Zhu bashes you with the Great Weight of War!\n");
	say("Xu Zhu bashes "+AO->query_name()+" with his Great Weight of War!\n", AO);
	AO->hit_player(50);
	}
	else if (!random(6)) {
	tell_object(AO, "XU Zhu smashes you across your head with this Weight of War!\n");
	say("Xu Zhu smashes "+AO->query_name()+" over the head with his Weight of War!\n",AO);
	AO->hit_player(55);
	}
    }
}


