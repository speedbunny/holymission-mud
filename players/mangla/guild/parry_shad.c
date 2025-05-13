inherit "/obj/std_shadow";
#include "/players/mangla/defs.h"

varargs int start_shadow(object ob,int time) {

    tell_object(ob,"You start your parrying.\n");
    return ::start_shadow(ob,time,"parry",0);
}

void end_shadow(object ob) {

  int remain;

  if(ob)
    tell_object(me,"You lower your parry.\n");
    remain = shadow_time("parry");
    me->ADDSP(remain/20);
    ::end_shadow(ob);
}

int parry_shad() {
    return 1;
}

object parry_object() 
{
       return this_object();
}

varargs int hit_player(int dam,int kind,mixed *elem) 
{
    int rand,chance;

    if(kind==7 || kind == 5) 
       return apply(call,me,"hit_player",dam,kind,elem);
    

    rand = random(100) + 1;
    chance = 42 + (25 * me->DEX)/40;
    if(rand < chance) {
        tell_object(TP,me->NAME+" parries the blow!\n",TP);
        tell_object(me,"You manage to parry the incoming blow!\n");
        say(me->NAME+" parries the blow!\n",me,TP);
        return apply(call,me,"hit_player",0,kind,elem);
    }
    if(rand < chance+15) {
        tell_object(this_player(),apply(call,me,"query_name")+
                    " manages to deflect the blow somewhat.\n");
        tell_object(me,"You manage to deflect the blow somewhat.\n");
        say(me->NAME+" manages to partially deflect the blow!\n",me,TP);
        return apply(call,me,"hit_player",dam/2,kind,elem);
    }
    return apply(call,me,"hit_player",dam,kind,elem);
}
