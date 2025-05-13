/*
// A wand of holding. This can be used 
// until the charges run out.
// Darastor: began coding 18/10/97
*/

inherit "/obj/treasure";

#include "/players/darastor/include/seaside.h"

#define HOLD_NPC    random(400/(victim->query_level()+1))
#define HOLD_PLAYER random(200/victim->query_level())
#define OTHERS_MSG  CNAME + " holds " + capitalize(victim->query_name()) \
                    + ".\n"

int charges;

void hold_end(object victim)
{
    tell_object(victim,"The hold on you is released.\n");
}

status _hold(string str)
{
    object victim;
    int tim;
    
    notify_fail("Hold what?\n");
    
    if(!str)
        victim = TP -> query_attack();
    else
        victim = present(str,environment(TP));

    if(!victim)
        return 0;
        
    if((!living(victim)) || (victim->query_immortal()))
    {
        tell_object(TP, "You just can't hold " +
          capitalize(victim -> query_name()) + ".\n");
        return 1;
    }
    
    if(TP->test_dark())
        return 1;
        
    if(victim->query_npc())
        tim=HOLD_NPC;
    else
        tim=HOLD_PLAYER;
        
    tim=2*(1 + random(tim));
    if(tim>0)
        victim->hold(TO,tim);
        
    if(TP->query_immortal())
        write("Time (Wizinfo): "+tim+"\n");
        
    tell_object(TP,"You hold " + capitalize(victim->query_name())+".\n");
    say(OTHERS_MSG,TP,victim,OTHERS_MSG);
    tell_object(victim,CNAME + " holds you.\n");
    
    if(--charges < 1)
    {
        tell_object(TP,"Your wand of holding disintegrates.\n");
        destruct(TO);
    }
    return 1;
}

void reset(int arg)
{
    ::reset(arg);

    if(!arg)
    {
        /* bell-shaped curve for random charges */
        charges = 1 + random(5) + random(5) + random (5);
    }
}

void init()
{
    ::init();
    add_action("_hold","hold");
}
