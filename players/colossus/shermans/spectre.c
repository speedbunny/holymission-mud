/* Edited by Colossus 030494 */

#pragma strict_types

inherit "obj/monster";
void reset(int arg){
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
set_long(
"The spectre resembles a ghost in many ways except that\n"+
"it is more powerful and has a craving for warm flesh.\n"+
"The red eyes hang in midair and as it opens its mouth\n"+
"teeth are revealed. Just from looking at those dreadful\n"+
"eyes, you see the fiery pits of hellish lust.\n");
    set_chance(10);
    set_spell_mess1("Spectre touches his victim with his cold fingers");
    set_spell_mess2("Spectre drains you");
    set_spell_dam(30);
}
