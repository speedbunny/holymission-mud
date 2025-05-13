inherit "/obj/monster";

#include "/players/darastor/include/seaside.h"

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("moray eel");
        set_alias("eel");
        set_alt_name("moray");

        set_short("A moray eel");
        set_long("A large, brownish-coloured eel about five feet in length. "+
          "Its skin is smooth and scaleless, and it has a wide mouth with "+
          "very sharp teeth.\n");
        set_race("fish");
        set_gender(0);
        set_size(3);
        set_has_gills();
        set_smell("The eel smells pretty fishy.");

        set_level(14);
        set_wc(13);
        set_ac(14);
        
        /* Special attack stuff */
        set_chance(20);
        set_spell_mess1("The moray eel whips @@op_name@@ with its tail.");
        set_spell_mess2("The moray eel whips you with its tail.");
        set_spell_dam(20);
    }
}

string op_name()
{
    /* return capitalized opponent name */
    return capitalize(call_other(attacker_ob,"query_name",0));
}


