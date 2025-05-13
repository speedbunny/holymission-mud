inherit "/obj/monster";

#include "/players/darastor/include/seaside.h"

/* Closure so spell_message reacts to dragon's opponent */
closure opponent_name;

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("red dragon");
        set_alt_name("dragon");
        set_short("A red dragon");
        set_long("A very large-looking red dragon. Looks as though it could "+
          "prove a very dangerous opponent.\n");
        set_race("dragon");
        set_gender(0);
        set_smell("The dragon's breath smells of brimstone.");
        
        set_level(20);
        
        /* Two claw attacks */
        
        set_wc(15);
        set_ac(8);
        set_number_of_arms(2);
        
        /* Special attack stuff */
        set_chance(50);
        set_spell_mess1("The dragon breathes fire at @@op_name@@");
        set_spell_mess2("The dragon breathes fire at you");
        set_spell_dam(70);
    }
}

string op_name()
{
    /* return capitalized opponent name */
    return capitalize(call_other(attacker_ob,"query_name",0));
}

