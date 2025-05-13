/* Chomp's monster - 31/3/95 */

inherit "/obj/monster";

reset(arg)
{
     ::reset(arg);
     if (arg) return;
        set_name("kangaroo");
        set_alias("roo");
        set_race("animal");
        set_short("A big kangaroo");
        set_long("A big kangaroo with strong legs and tail. It doesn't\n"+
                 "look harmful, but think twice before attacking it.\n"); 
        set_hp(6000);
        set_al(200);
        set_level(30);
        set_size(5);
        set_spell_mess1("The Roo is kicking its attacker");   
        set_spell_mess2("BOINK !! The Roo kicks you with its strong legs");   
        set_chance(30);
        set_spell_dam(100);
        set_wc(20);
        set_ac(5);
}
