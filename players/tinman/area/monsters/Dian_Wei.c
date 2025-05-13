inherit "obj/monster";
object wmace,gplate,ghelmet,gauntlet,pant,boot,shield;

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Dian Wei");
	set_alias("dian");
	set_short("Dian Wei, the Red General");
	set_alt_name("wei");
    set_long("A huge man with brisky beard. He has rippling muscle and can"+
" smash you flat. He is one of Cao Cao's best red general\n");
	set_level(65);
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
	tell_object(AO, "Dian Wei swings his Weight of War and knock you down"+
	" flat!!\n");
	say("Dian Wei swings his Weight of War and knocks "+AO->query_name()+" down!\n",AO);
	AO->hit_player(20+random(30));
	}
	else if (!random(6)) {
	tell_object(AO, "Dian Wei bashes you on your head cracking your skull!\n");
	say("Dian Wei bahes "+AO->query_name()+" on his head cracking his head!\n",AO);
	AO->hit_player(30+random(30));
	}
    }
}


