/* ************************************************************************
                         B A A Z   D R A C O N I A N
   ************************************************************************
                                                 c1993 renegade@iastate.edu
*/

inherit "obj/monster";

reset (arg) 
{
    ::reset(arg);
    if (arg) return;
    set_name("draconian");
    set_alt_name("baaz");
    set_level(15+random(5));
    set_hp(400+random(500));
    add_money(500+random(500));
    set_alias("dracon");
    set_al(-1000);
    set_ac(8);
    set_aggressive(1);
    set_wc(12);
    set_gender(0+random(2));
    set_race("draconian");
    set_short("Baaz Draconian");
    set_long("A baaz draconian.\n"+
	      "It is about 5 and 1/2 feet tall it looks as if it\n"+
	      "has tried to conceal it's wings under its robe but\n"+
	      "wasn't very successful in doing so.\n");
    set_chance(30);
    set_spell_mess1("You cry out in pain as he claws you.\n");
    set_spell_mess2("He whips his tail around and hits you.\n");
    set_spell_dam(25);
}
