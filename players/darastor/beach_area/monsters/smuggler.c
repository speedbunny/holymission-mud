inherit "/obj/monster";

#include "/players/darastor/include/seaside.h"

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("smuggler");
        set_short("A rough-looking smuggler");
        set_long("This smuggler looks as though he has been in the business "+
          "a while and bears the scars of several fights.\n");
        set_race("human");
        set_gender(1);
        set_smell("Kind of fishy. Probably hangs round the sea a lot.");
        set_random_pick(1);
        
        set_level(8);
        set_whimpy(10);
        set_al(-50);
        add_money(25+random(25));
    }
}

