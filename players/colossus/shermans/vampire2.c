/* Edited by Colossus 030494 */

#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("vampirelord");
    set_alias("lord");
    set_alt_name("vampire");
    set_level(40);
    set_hp(2500);
    set_al(-500);
    set_ac(22);
    set_aggressive(1);
    set_wc(35);
    set_race("undead");
    set_short("Vampirelord");
    set_long(
      "A pale looking man wearing a dark flowing cloak and black suit\n"+
      "glares at you with malevolent eyes. The pits of Hell are visible\n"+
      "through his red glowing pupils. As he opens his mouth you see\n"+
      "blood dripping from inch-long fangs.\n");
    set_chance(20);
    set_spell_mess1("Vampirelord stares into his victims eyes");
    set_spell_mess2("Vampirelord drains you");
    set_spell_dam(80);
    add_money(5000+random(5001));
}

void init(){
    ::init();
    add_action("west", "west");
}

status west(){
    write("The Vampire lord shoves you forcefully back.\n");
    say("The Vampire lord shoves "+this_player()->query_name()+" back.\n");
    return 1;
}
