inherit "/obj/monster";

#include "/players/darastor/include/seaside.h"

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("albatross");
        set_short("An albatross");
        set_long("A large sea-bird with a white body, and huge black "+
          "wings.\n");
        set_race("bird");
        set_gender(0);
        set_smell("Funnily enough for a sea bird, it smells of fish.");
        
        set_level(5);
        set_whimpy(10);
        set_al(0);
    }
}

