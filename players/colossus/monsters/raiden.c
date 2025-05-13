inherit "obj/monster";
object essence;

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("raiden");
    set_alias("god");
    set_short("Raiden");
    set_long("Raiden the thunder god. He was invited to take part in the\n"+
      "tournament by Shang Tzong himself so he took the form of a\n"+
      "mortal to compete.\n");
    set_level(16);
    set_hp(1000);
    add_money(250);
    set_gender(1);
    set_race("human");
    set_wc(16);
    set_ac(10);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
	    tell_object(AO, "Raiden flies at you and slams you into the wall!\n");
	    say("Raiden flies at "+AO->query_name()+" and slams "+this_player()->query_objective()+" into the wall!\n", AO);
	    AO->hit_player(13);
	}
	else if (!random(6)) {
	    tell_object(AO, "Raiden shocks you with a lightning bolt!\n");
	    say("Raiden fires a lightning bolt at "+AO->query_name()+", shocking "+this_player()->query_objective()+" badly!\n", AO);
	    AO->hit_player(10);
	}
    }
}
