inherit "obj/monster";

#define AO attacker_ob

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_name("monster");
    set_alias("test monster");
    set_short("Test monster");
    set_long("A generic monster coded for Esox by Colossus of Holy Mission.\n");
    set_level(20);
}
init(){
    ::init();
    set_heart_beat(1);
    /* heart_beat is set to call for the crushing attack */
}
/* Starting the heart_beat function */
heart_beat(){
    ::heart_beat();
    write("Heart beat activated.\n");
    /* To check if the attacker of the monster is present */
    if(AO && present(AO, environment()) ){
	/* To set the percentage or chance for the crushing attack */
	if(!random(6)) {
	    /* Tells the object of the crush that the monster is crushing you */
	    tell_object(AO, "Monster crushes you.\n");
	    /* Tells the rest that the monster is crushing you, the attacker */
	    say("Test monster crushes "+AO->query_name()+".\n", AO);
	    /* The damage you take when the monster constricts */
	    AO->hit_player(5);
	    /* The attacker (you) are held by the monster for 15 seconds before release */
	    AO->hold(this_player(), 15);
	}
    }
}
/* This is called when hold finishes its time */
hold_end(obj){
    /* Tells you that the monster releases you */
    tell_object(obj, "The monster releases you.\n");
    return 1;
}
