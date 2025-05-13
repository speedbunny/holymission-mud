
/* sanct_shad 
   Effect: reduces the damage of standard hits type 0 by 1/2
   Id: sanct
   Extra:  There is only 1 sanct shadow allowed at time
                                                                    */

inherit "/obj/std_shadow";

varargs int start_shadow(object who,int time)
{
    set_effect_msg("sanct");
    set_look_info("(white aura)");
    return ::start_shadow(who,time,"sanct",0);
}

varargs int hit_player(int dam,int kind,mixed elem)
{
    if (kind == 0)
        return apply(call,me,"hit_player",(dam/2),kind,elem);
    return apply(call,me,"hit_player",dam,kind,elem);
}

void end_shadow(object ob)
{
     tell_object(me,
     "The white aura around your body happily fades away !\n");
     ::end_shadow(ob);
}


