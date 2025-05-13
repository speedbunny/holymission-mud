/* Edited by Colossus 030494 */

#pragma strict_types

inherit "obj/monster";

void reset(int arg)
{
    ::reset();
    if (arg)
	return;
    set_name("vampire lord");
    set_alias("vampire");
    set_alt_name("lord");
    set_level(50);
    set_hp(3500);
    set_al(-500);
    set_ac(30);
    set_aggressive(1);
    set_wc(40);
    set_race("undead");
    set_short("Vampire Lord");
    set_long(
      "A pale looking man wearing a dark flowing cloak and black suit\n"+
      "glares at you with malevolent eyes. The pits of Hell are visible\n"+
      "through his red glowing pupils. As he opens his mouth you see\n"+
      "blood dripping from inch-long fangs.\n");     
    set_chance(20);
    set_spell_mess1("Vampire Lord stares intp his victims eyes");
    set_spell_mess2("Vampire Lord drains you");
    set_spell_dam(100);
}
