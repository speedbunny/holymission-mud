inherit "obj/npc";
reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("dracolich");
    set_level(50);
    set_al(-500);
    set_ac(30);
    set_aggressive(1);
    set_wc(50);
    set_race("undead");
    set_short("Dracolich");
    set_long("A animated skeleton of a dead dragon.\n");
    set_chance(33);
    set_spell_mess1("The Dracolich shoots a lightning bolt agains his\n"+
      "opponent");
    set_spell_mess2("The Dracolich breaths lightning at YOU!!!");
    set_spell_dam(200);
    set_attacks(2);
    set_attacks_change(100);
    set_size(5);
}
