/* ************************************************************************
                       B O Z A K   D R A C O N I A N
   ************************************************************************
                                                 c1993 renegade@iastate.edu
*/

inherit "obj/monster";

reset (arg) 
{
    ::reset(arg);
    if (arg) return;
    set_name("draconian");
    set_alt_name("bozak");
    set_level(17+random(5));
    set_hp(600+random(900));
    add_money(100+random(1000));
    set_alias("dracon");
    set_al(-1000);
    set_ac(9);
    set_aggressive(1);
    set_wc(15);
    set_gender(0+random(2));
    set_race("draconian");
    set_short("Bozak Draconian");
    set_long("A deadly bozak draconian.\n"+
	      "It is about 6 and 1/2 feet tall and has large wings\n"+
	      "that folded up behind it's back.\n");
    set_chance(30);
    set_spell_mess1("You cry out in pain as he claws you.\n");
    set_spell_mess2("It casts a magic missile at you!\n");
    set_spell_dam(28);
}

