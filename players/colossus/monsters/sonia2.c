inherit "obj/monster";

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("sonia");
    set_alias("agent");
    set_short("Sonia");
    set_long("Sonia, a government agent who was sent to apprehend Kano. She was\n"+
      "captured by Shang Tzong and made to compete in the tournament.\n");
    set_level(80);
    set_hp(1);
    set_str(1);
    set_dex(1);
    add_money(250);
    set_gender(2);
    set_race("human");
    set_wc(15);
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
	    tell_object(AO, "Sonia hits you with a beam of energy.\n");
	    say("Sonia hits "+AO->query_name()+" with a beam of energy.\n", AO);
	    AO->hit_player(10);
	}
	else if (!random(6)) {
	    tell_object(AO, "Sonia does a handstand, grabs your sides with her legs and\n"+
	      "slams you to the ground!.\n");
	    say("Sonia does a handstand, grabs "+AO->query_name()+"'s sides and slams\n"+
	      ""+this_player()->query_possessive()+" to the ground!\n", AO);
	    AO->hit_player(15);
	}
    }
}
