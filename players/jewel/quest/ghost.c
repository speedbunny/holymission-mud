inherit "obj/monster";

reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("ghost");
    set_level(18);
    set_hp(700);
    set_al(-300);
    set_ac(12);
    set_aggressive(1);
    set_wc(18);
    set_race("undead");
    set_short("Ghost");
    set_long("A form of a long dead human.\n");
    set_chance(15);
    set_spell_mess1("Ghost touches his victim");
    set_spell_mess2("Ghost drains you");
    set_spell_dam(25);
}
