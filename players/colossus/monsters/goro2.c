inherit "obj/monster";

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("goro");
    set_alias("monster");
    set_short("Goro");
    set_long(
      "This is Goro. He is a mountain of immovable muscle with hideous features\n"+
      "and a vaguely humanoid face. Six arms protrude from his sides, three on\n"+
      "each side. You feel your gut wrench as you face such a formidable opponent.\n"+
      "He grins maliciously at you and immediately lunges as you.\n");
    set_gender(1);
    set_race("monster");
    set_level(100);
    set_hp(2);
    add_money(3000);
    set_wc(1);
    set_ac(13);
    set_str(1);
    set_dex(1);
    set_aggressive(1);
    set_al(-2000);
}
init(){
    ::init();
    set_heart_beat(1);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(99)) {
	    tell_object(AO, "Goro grabs you and pounds your chest before throwing you to\n"+
	      "the side.\n");
	    say("Goro grabs "+AO->query_name()+" and pounds "+this_player()->query_possessive()+"\n"+
	      "with his huge fists before finally dropping "+this_player()->query_possessive()+".\n", AO);
	    AO->hit_player(25);
	}
	else if (!random(99)) {
	    tell_object(AO, "Goro unleashes a bolt of green energy that pulverizes you.\n");
	    say("Goro unleashes a bolt of green energy at "+AO->query_name()+" which\n"+
	      "pulverizes "+this_player()->query_possessive()+".\n", AO);
	    AO->hit_player(15);
	}
    }
}
