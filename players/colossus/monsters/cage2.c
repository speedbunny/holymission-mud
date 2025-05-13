inherit "obj/monster";

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("johnny cage");
    set_alias("cage");
    set_alt_name("johnny");
    set_short("Johnny Cage");
    set_long("Johnny Cage, the world kickboxing champion who has mad many\n"+
      "famous martial arts movies and who is now competing in the\n"+
      "tournament.\n");
    set_gender(1);
    set_race("human");
    set_level(80);
    set_hp(1);
    set_str(1);
    set_dex(1);
    add_money(250);
    set_wc(14);
    set_ac(9);
}
init(){
    ::init();
    set_heart_beat(1);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
	    tell_object(AO, "Cage hits you with a powerful shadow kick.\n");
	    say("Johnny Cage hits "+AO->query_name()+" with a powerful shadow kick.\n", AO);
	    AO->hit_player(14);
	}
	else if (!random(6)) {
	    tell_object(AO, "Johnny Cage hits you with a green beam of energy.\n");
	    say("Johnny Cage hits "+AO->query_name()+" with a green beam of energy.\n", AO);
	    AO->hit_player(10);
	}
    }
}
