/* ************************************************************************
                      A U R A K   D R A C O N I A N
   ************************************************************************
                                                 c1993 renegade@iastate.edu
*/

inherit "obj/monster";

reset (arg) 
{
    ::reset(arg);
    if (arg) return;
    set_name("draconian");
    set_alt_name("aurak");
    set_level(27+random(5));
    set_hp(800+random(1000));
    add_money(100+random(2000));
    set_alias("dracon");
    set_al(-1000);
    set_ac(12);
    set_aggressive(1);
    set_wc(20);
    set_gender(0+random(2));
    set_race("draconian");
    set_short("Aurak Draconian");
    set_long("A deadly aurak draconian.\n"+
	      "He is about 7 feet tall, is generally golden in\n"+
	      "color, has large sinewy muscles and a short tail.\n");
    set_chance(30);
    set_spell_mess1("He casts a magic missile at you!\n");
    set_spell_mess2("You cry out in pain as he claws you!\n");
    set_spell_dam(35);
}
