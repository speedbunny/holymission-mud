inherit "/obj/monster";

#include "/players/darastor/include/seaside.h"

void reset(int arg)
{ 
    :: reset(arg);
    if(!arg)
    {
        set_name("lieutenant");
        set_alias("smuggler lieutenant");
        set_short("Smuggler lieutenant");
        set_long("This is the smuggler chief's second in command. He looks "+
          "very tough, and a dangerous opponent.\n");
        set_race("human");
        set_gender(1); 
        set_smell("Smells of strong wine. Maybe he spends a lot of time "+
          "drinking");
        set_random_pick(1);
        
        set_level(12);
        set_whimpy(15);
        set_al(-75);
        add_money(50 + random(25));
    }
}  

