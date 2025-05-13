
/* snake */

inherit "obj/monster"; 

void reset(int flag) 
{
   ::reset(flag);
   if (flag == 0) 
   {
    set_name("water snake");
    set_alt_name("snake");
    set_level(14); 
    set_has_gills();
    set_hp(300);
    set_al(-10); 
    set_race("fish"); 
    set_short("A big green water snake"); 
    set_long("You see a long green watersnake.\n"+ 
               "It looks harmless, but very strong.\n");
    set_wc(18);
    set_ac(6); 
    set_whimpy();
    set_spell_mess2("The snake winds itself around your body !");
    set_spell_mess1("The snake winds itself in panic !");
    set_chance(60); 
    set_aggressive(1);
    set_spell_dam(random(10)); 
   }
}

