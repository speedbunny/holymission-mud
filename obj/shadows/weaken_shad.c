

/* weakness 
  effect: lowers the strength of the living temporary 
  id: weakness 
  attr-msg: strength
  no look-info
  non multiple
                                                             */

inherit "/obj/std_shadow";

int newstr;

varargs int start_shadow(object who,int time,int num) 
{
   int chk, perc;

    if(!num)
    {
        chk = apply(#'call_other,who,"query_r_stats",0);
        perc = (apply(#'call_other,this_player(),"query_level")/4+1)*4;
        newstr = (chk * perc) / 100;
    }
    else newstr = num;
    set_effect_msg("weakness");
    return ::start_shadow(who, time, "weakness",0);
}

query_str()
{
   if(apply(call,environment(me),"stat_room"))
       return apply(call,me,"query_str");
   return apply(call,me,"query_str")-newstr;
}

query_stats(x)
{  
   if(environment(me)->stat_room()) return apply(call,me,"query_stats",x);
   if(x == 0) return apply(call,me,"query_stats",x)-newstr;
   else return apply(call,me,"query_stats",x);
}

end_shadow(o)
{
    tell_object(me, "You feel weaker now!\n"); 
    ::end_shadow(o);
}
