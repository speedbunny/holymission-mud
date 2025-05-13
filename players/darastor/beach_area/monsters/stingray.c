inherit "/obj/monster";
/* Needs a spine, similar to the stonefish fang */

#include "/players/darastor/include/seaside.h"

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("stingray");
        set_alias("sting ray");
        set_alt_name("ray");

        set_short("A sting ray");
        set_long("A broad, flat fish with a long whip-like tail. It has "+
          "a hardened spine across the top of its tail, which looks like "+
          "it could do you a nasty injury. This ray is about 4 feet across "+
          "its \"wings\" and its teeth look very sharp.\n");
        set_race("fish");
        set_has_gills();
        set_gender(0);
        set_size(2);
        set_smell("The stingray smells pretty fishy.");
        set_size(3);
        
        set_level(12);
        set_wc(13);
        set_ac(11);
    }
}

varargs int attack( object weapon, int nhands )
{
    if (attacker_ob && environment()==environment(attacker_ob)
      && random(100) < 8)
    {
        tell_object(attacker_ob,"Suddenly the stingray stabs you with its "+
          "venomous spine.\n");
        attacker_ob->command("scream");
        attacker_ob->add_poison(8+attacker_ob->query_con()/2);
    }
    return ::attack(weapon,nhands);
}
