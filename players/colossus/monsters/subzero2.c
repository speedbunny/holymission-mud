inherit "obj/monster";

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("subzero");
    set_alias("ninja");
    set_short("Subzero");
    set_long("Subzero, a Lin-Kuei ninja sent to assassinate Scorpion in the tournament.\n");
    set_level(1);
    set_hp(1);
    set_str(1);
    set_dex(1);
    add_money(100);
    set_wc(10);
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
	    tell_object(AO, "Subzero freezes you with an iceball and uppercuts you.\n");
	    say("Subzero freezes "+AO->query_name()+" with an iceball and uppercuts "+this_player()->query_possessive()+".\n", AO);
	    AO->hit_player(10);
	}
	else if (!random(6)) {
	    tell_object(AO, "Subzero slides between your legs and trips you.\n");
	    say("Subzero slides between "+AO->query_name()+"'s legs and trips "+this_player()->query_possessive()+".\n", AO);
	    AO->hit_player(8);
	}
    }
}
