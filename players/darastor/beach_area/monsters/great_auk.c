inherit "/obj/monster";

#include "/players/darastor/include/seaside.h"

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("great auk");
        set_alt_name("auk");
        set_short("A great auk");
        set_long("A large, flightless bird. Its upper parts are black, "+
          "its stomach is white and the sides of its head, nose and "+
          "throat are brown.\n");
        set_race("bird");
        set_gender(0);
        set_neuter();
        set_smell("Rather fishy.");
        
        set_level(4);
    }
}

