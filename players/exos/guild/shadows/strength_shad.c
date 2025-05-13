// Strength
// gives 'who' 'num' point of strength for 'time' seconds or if 'num' is zero
// the additional amount of damage is calculated using the level of the caster
// and the str of the target
// id: strength
// attr-msg: strength
// no look-info
// non multiple

inherit "/obj/std_shadow";
int newstr;

start_shadow(who, time, num) {
    if(!num)
    {
        newstr = (50-apply(#'call_other,who,"query_r_stats",0))/4 +
                 apply(#'call_other,this_player(),"query_level")/5 + 1;
    }
    else newstr = num;
    set_effect_msg("strength");
    return ::start_shadow(who, time, "strength",0);
}

query_str()
{
   if(apply(call,environment(me),"stat_room"))
       return apply(call,me,"query_str");
   return apply(call,me,"query_str")+newstr;
}

query_stats(x)
{  
   if(environment(me)->stat_room()) return me->query_stats(x);
   if(x == 0) return me->query_stats(x)+newstr;
   else return me->query_stats(x);
}

end_shadow(o)
{
    tell_object(me, "You feel weaker now!\n"); 
    ::end_shadow(o);
}
