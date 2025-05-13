inherit "obj/monster";
#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("velociraptor");
    set_short("A Velociraptor");
    set_alias("raptor");
    set_long("This dinosaur is some 1.8 metres tall, and 2.8 metres long,\n"+
      "with rows of razor sharp teeth, and wicked, curved claws.\n"+
      "It turns to face you, and studies you intently as slaver\n"+
      "drips from its frightening maw.\n");
    set_level( 30 + random(10) );
    set_hp(5500);
    set_ac(11);
    set_wc(20);
    set_al(-1000);
    set_aggressive(1);
    set_number_of_arms(3);
    set_spell_mess2("The Velociraptor slashes its clawed foot across your abdomen.");
    set_spell_mess1("The Velociraptor's claws strike with blinding speed and power.");
    set_chance(45);
    set_spell_dam(55);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
    }
}
