inherit "obj/npc";

reset(arg)
{
    ::reset();
    if (arg)
	return;
    set_name("vampire lord");
    set_level(50);
    set_al(-500);
    set_ac(30);
    set_aggressive(1);
    set_wc(40);
    set_race("undead");
    set_short("Vampire Lord");
    set_long("A friendly old man with long teeth.\n");
    set_chance(20);
    set_spell_mess1("Vampire Lord stares intp his victims eyes");
    set_spell_mess2("Vampire Lord drains you");
    set_spell_dam(100);
    set_attacks(2);
    set_attacks_change(100);
}
