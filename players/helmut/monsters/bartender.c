inherit "obj/monster";
#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("The Bartender");
    set_short("The Bartender");
    set_alias("bartender");
    set_long(
      "Well, this Velociraptor seems to be quite old, but still looks\n"+
      "very dangerous.  You suppress a giggle as you look at his clothing,\n"+
      "since you think he might take offense. He moves busily behind the\n"+
      "bar, serving various customers.  He winks at you...\n");
    set_level(100 + random(100) );
    set_hp(25000);
    set_ac(20);
    set_wc(20);
    set_al(1000);
    set_number_of_arms(4);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
    }
}
