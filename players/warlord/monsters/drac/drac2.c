/* ************************************************************************
                       S I V A K   D R A C O N I A N
   ************************************************************************
                                                 c1993 renegade@iastate.edu
*/

inherit "obj/monster";

reset (arg) 
{
    ::reset(arg);
    if (arg) return;
    set_name("draconian");
    set_alt_name("sivak");
    set_level(24+random(5));
    set_hp(700+random(1000));
    add_money(100+random(1500));
    set_alias("dracon");
    set_al(-1000);
    set_ac(10);
    set_aggressive(1);
    set_wc(17);
    set_gender(0+random(2));
    set_race("draconian");
    set_short("Draconian");
    set_long("A deadly sivak draconian.\n"+
	      "It stands nearly 9 feet tall and has a long armored\n"+
	      "tail that looks very powerful.  It stares at you\n"+
	      "hungrily and relishes the idea of munching on your\n"+
              "corpse when it kills you.\n");
    set_chance(30);
    set_spell_mess1("You cry out in pain as he claws you.\n");
    set_spell_mess2("He whips his tail around an smashes you with it!\n");
    set_spell_dam(30);
}

