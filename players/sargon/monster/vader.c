inherit "/obj/npc";

reset(arg){
    ::reset(arg);
    if(!arg) {
    set_name("darth");
    set_alias("vader");
    set_long("Say hello to Darth Vader.\n"+ 
                  "He is here to keep non-Jedi's out of the\n"+
                  "guild.  He wearing all black with a black face \n"+
                  "mask and a black cape.\n");
    set_level(10);
    set_ac(5);
    set_wc(5);
    set_hp(400);
    set_al(1000);
    set_aggressive(0);
     set_ep(0);
    set_chance();
    set_spell_mess1();
    set_spell_mess2();
    set_dodge();
    set_attacks(1);
}
}
