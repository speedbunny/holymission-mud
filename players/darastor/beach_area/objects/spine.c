inherit "/obj/treasure";

#include "/players/darastor/include/seaside.h"
#include "/players/darastor/include/linewrap.h"

status sting_victim(object victim)
{
    string say_msg;
    if(living(victim)&&(environment(victim)==environment(TP)))
    {
        say_msg = CNAME + " sticks the spine into " +
          capitalize(victim->query_name()) + " and breaks the end off, " +
          "injecting " + victim->query_pronoun() + " with a "+
          "nasty poison. " + capitalize(victim->query_name()) + " cries out "+
          "in pain.\n";
        say(lw(say_msg),victim,TP,lw(say_msg));
        TELL_OBJECT(victim, CNAME + " sticks a stingray spine into you and " +
          "breaks the end off, injecting you with a poison. Ouch, that "+
          "hurts!\n");
        TELL_OBJECT(TP,"You stick the spine into " +
          capitalize(victim->query_name()) + " and break the end off to " +
          "inject the poison. "+ capitalize(victim->query_pronoun()) +
          " cries out in pain.\n");
        TP -> attack_object(victim);
        if(TP->query_attack() && (TP->query_attack()==victim))
        {
            victim -> add_poison(25 + random(10));
            if(living(victim))
                victim -> hit_player(30,7);
            TP -> set_vis();
            destruct(TO);
        }
        return 1;
    }
    return 0;
}

status _sting(string str)
{
    object victim;
    string *properties;

    if(!str)
        victim = TP->query_attack();
    else
        victim = present(str,environment(TP));

    properties = environment(TP) -> query_property();
    if(sizeof(properties)&&(member_array("no_fight",properties) != -1))
    {
        tell_object(TP,"This place is under divine protection.\n");
        return 1;
    }
    else
    {
        call_out("sting_victim",2,victim);
        return 1;
    }
}

void reset(int arg)
{
    ::reset(arg);

    if(!arg)
    {
        set_name("spine");
        set_alias("stingray spine");
        set_short("A stingray spine");
        set_value(75);
        set_weight(1);
        set_long("This is the venomous spine of a stingray. It can be used "+
          "to poison an enemy, but only once. Just type \"sting <opponent>\ "+
          "or \"stinger\" if you are already fighting. Remember, it can "+
          "only be used once.\n");
    }
}

void init()
{
    ::init();
    if(environment()->query_player())
        add_action("_sting","sting");
}
