
/* orc baby */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     { 
        set_name("small orc");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("An orc baby.\n");
        set_gender(1+random(2));
        set_level(1);
        set_whimpy(2);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-10);
      }
}

