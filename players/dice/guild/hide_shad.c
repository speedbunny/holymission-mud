
/* hide_shad */

inherit "/players/whisky/obj/std_shadow";


object hide_object()
{
    return this_object();
}

int hide_shad()
{
   return 1;
}

mixed attack()
{
    me->set_vis();
    tell_object(me,"You feel exposed.\n");
    unshadow();
    move_object(me,environment(me));
    ::end_shadow(this_object());
    return me->attack();
}

mixed look_info(mixed flag)
{
     if (flag) return 0;
        return " [hidden]";
}
int query_invis()
{
    return 29;
}
