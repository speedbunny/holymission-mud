inherit "/obj/monster";

#include "/players/darastor/include/seaside.h"

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("cormorant");
        set_short("A cormorant");
        set_long("A bird with an entirely black plumage, a long hooked "+
          "bill, a long thin neck and a long tail.\n");
        set_race("bird");
        set_gender(0);
        set_smell("Rather fishy.");
        
        set_level(3);
        set_whimpy(10);
        set_al(-50);
    }
}

