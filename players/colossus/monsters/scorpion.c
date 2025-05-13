inherit "obj/monster";

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("scorpion");
    set_alias("ninja");
    set_short("Scorpion");
    set_long("Scorpion, a ninja who is here to take revenge and kill Sub-zero.\n");
    set_level(13);
    add_money(100);
    set_hp(800);
    set_wc(12);
    set_gender(1);
    set_race("human");
    set_ac(7);
}
init(){
    ::init();
    set_heart_beat(1);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
	    tell_object(AO, "Scorpion catches you in the throat with a kyoketsu-shogi and\n"+
	      "reels you in before delivering a massive uppercut.\n");
	    say("Scorpion catches "+AO->query_name()+" in the throat with his spear, reels "+this_player()->query_objective()+" in,\n"+
	      "and delivers an uppercut.\n", AO);
	    AO->hit_player(10);
	}
	else if (!random(6)) {
	    tell_object(AO, "Scorpion fades out, suddenly appears behind you, and punches you.\n");
	    say("Scorpion teleports behind "+AO->query_name()+" and punches "+this_player()->query_objective()+".\n", AO);
	    AO->hit_player(8);
	}
    }
}
