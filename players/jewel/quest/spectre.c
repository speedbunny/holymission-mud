inherit "obj/monster";
reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("spectre");
    set_level(20);
    set_hp(700);
    set_al(-300);
    set_ac(12);
    set_aggressive(1);
    set_wc(20);
    set_race("undead");
    set_short("Spectre");
    set_long("A shadowy figure dancing in the air.\n");
    set_chance(10);
    set_spell_mess1("Spectre touches his victim with his cold fingers");
    set_spell_mess2("Spectre drains you");
    set_spell_dam(30);
}
