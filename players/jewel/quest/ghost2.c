inherit "obj/monster";

reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("ghost");
    set_level(18);
    set_hp(700);
    set_al(-300);
    set_ac(12);
    set_aggressive(0);
    set_wc(18);
    set_race("undead");
    set_short("Ghost");
    set_long("A form of a long dead human.\n");
    set_chance(10);
    set_spell_mess1("Ghost touches his victim");
    set_spell_mess2("Ghost drains you");
    set_spell_dam(25);
    load_chat(20,({
        "The Vampire King has killed us\n",
        "We hate vampires\n",
        "Dont't go further they are killers\n",
        "They will suck your blood\n",
        "We are the lost souls\n"
                 }));
    load_a_chat(20,({
        "We hate you, bloody vampire\n",
        "This is our revange\n",
        "Now we kill you\n"
                 }));
}
