inherit "obj/monster";

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("kano");
    set_alias("outlaw");
    set_short("Kano");
    set_long("Kano, a dangerous outlaw who is wanted by the\n"+
      "government for his many heinous crimes.\n");
    set_level(80);
    set_hp(1);
    set_str(1);
    set_dex(1);
    set_gender(1);
    set_race("human");
    add_money(100);
    set_wc(11);
    set_ac(7);
    set_al(-999999);
}
init(){
    ::init();
    set_heart_beat(1);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
	    tell_object(AO, "Kano rolls into a tight ball and slams into you.\n");
	    say("Kano rolls into a tight ball and slams into "+AO->query_name()+".\n", AO);
	    AO->hit_player(10);
	}
	else if (!random(6)) {
	    tell_object(AO, "Kano creates an energy scythe that slams into you.\n");
	    say("Kano throws an energy scythe at "+AO->query_name()+", opening a big wound in "+this_player()->query_possessive()+".\n", AO);
	    AO->hit_player(10);
	}
    }
}
