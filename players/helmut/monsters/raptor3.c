inherit "obj/monster";
#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("velociraptor");
    set_short("A Velociraptor");
    set_alias("raptor");
    set_long("This Velociraptor is leaning over a well devoured corpse.\n"+
      "As he notices you, he snarls and stands tall. He looks\n"+
      "right at you, and you freeze as you notice the slaver\n"+
      "mixed with blood drip from this monster's maw. He takes\n"+
      "a step toward you, and regards you curiously, with a tilt\n"+
      "to his head...\n");
    set_level( 30 + random(10) );
    set_hp(3000);
    set_ac(11);
    set_wc(20);
    set_al(-1000);
    set_number_of_arms(3);
    set_spell_mess2("The Velociraptor slashes its clawed foot across your abdomen.");
    set_spell_mess1("The Velociraptor claws strike with blinding speed.");
    set_chance(45);
    set_spell_dam(55);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
    }
}
