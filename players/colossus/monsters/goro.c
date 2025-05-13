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
    set_level(60);
    set_hp(1500);
    set_ep(0);
    add_money(0);
    set_wc(19);
    set_ac(13);
    set_aggressive(1);
    set_ep(700000);
    set_al(-2000);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(3)) {
	    tell_object(AO, "Goro grabs you and pounds your chest before throwing you to\n"+
	      "the side.\n");
	    say("Goro grabs "+AO->query_name()+" and pounds "+this_player()->query_objective()+"\n"+
	      "with his huge fists before finally dropping "+this_player()->query_objective()+".\n", AO);
	    AO->hit_player(25);
	}
	else if (!random(6)) {
	    tell_object(AO, "Goro unleashes a bolt of green energy that pulverizes you.\n");
	    say("Goro unleashes a bolt of green energy at "+AO->query_name()+" which\n"+
	      "pulverizes "+this_player()->query_objective()+".\n", AO);
	    AO->hit_player(15);
	}
    }
}
