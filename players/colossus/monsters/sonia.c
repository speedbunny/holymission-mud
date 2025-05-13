inherit "obj/monster";

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("sonya");
    set_alias("agent");
    set_short("Sonya");
    set_long("Sonya, a government agent who was sent to apprehend Kano. She was\n"+
      "captured by Shang Tzong and made to compete in the tournament.\n");
    set_level(16);
    set_hp(1000);
    add_money(250);
    set_gender(2);
    set_race("human");
    set_wc(17);
    set_ac(9);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
	    tell_object(AO, "Sonya hits you with a beam of energy.\n");
	    say("Sonya hits "+AO->query_name()+" with a beam of energy.\n", AO);
	    AO->hit_player(10);
	}
	else if (!random(6)) {
	    tell_object(AO, "Sonya does a handstand, grabs your sides with her legs and\n"+
	      "slams you to the ground!.\n");
	    say("Sonya does a handstand, grabs "+AO->query_name()+"'s sides and slams\n"+
	      ""+this_player()->query_objective()+" to the ground!\n", AO);
	    AO->hit_player(15);
	}
    }
}
