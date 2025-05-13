inherit "obj/monster";

reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("vampirelord");
    set_alias("lord");
    set_alt_name("vampire");
    set_level(40);
    set_al(-500);
    set_ac(22);
    set_aggressive(1);
    set_wc(35);
    set_race("undead");
    set_short("Vampirelord");
    set_long("A friendly old man with long teeth.\n");
    set_chance(20);
    set_spell_mess1("Vampirelord stares into his victims eyes");
    set_spell_mess2("Vampirelord drains you");
    set_spell_dam(80);
    add_money(5000+random(5001));
}
