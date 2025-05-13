// Code originally by Sherman of Holy Mission //
// re-coded and enhanced by Jewel of Holy Mission May 1996 //

inherit "obj/monster";
reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("ghoul");
    set_level(4+random(5));
    set_hp(200);
    set_al(-150);
    set_ac(3);
    set_aggressive(1);
    set_wc(12);
    set_race("undead");
    set_short("Ghoul");
    set_long("A monster eating human flesh.\n");
    hands= ({ this_object() });
    add_money(50+random(50));
}

weapon_class()
{ 
    return 12;
}

hit(ob)
{
   if(random(100)<20)
   {
       tell_object(ob,"You feel stunned from the ghoul's icy touch.\n");
       ob->hold(this_object(),random(10));
   }
}

