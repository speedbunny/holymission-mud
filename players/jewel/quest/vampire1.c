inherit "obj/monster";

reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("vampire");
    set_level(35);
    set_al(-500);
    set_ac(18);
    set_aggressive(1);
    set_wc(30);
    set_race("undead");
    set_short("Vampire");
    set_long("A friendly man with long teeth.\n");
    set_chance(20);
    set_spell_mess1("Vampire stares into his victims eyes");
    set_spell_mess2("Vampire drains you");
    set_spell_dam(60);
}
