// Invisibility
// makes 'who' invis(level 29) for 'time' seconds
// id: invis
// attr-msg: invisibility
// look-info: [inv]
// non multiple

inherit "/obj/std_shadow";

start_shadow(who, time) {
    if(who && apply(#'call_other,who,"query_invis")) destruct(this_object());
    else
    {
        set_effect_msg("invisibility");
//        set_look_info("[inv]"); 
        who->set_invis();
        return ::start_shadow(who, time, "invis",0);
    };
}

varargs int attack(object o,int h)
{
    int rtc;
    me->set_vis();
    rtc = me->attack(o,h);
    end_shadow(this_object());
    return rtc;
}

end_shadow(o) {
    if(me) tell_object(me, "You feel exposed!\n");
    ::end_shadow(o);
}

int turn_visible()
{
    if(me) tell_object(me, "You turn visible again!\n");
    ::end_shadow(this_object());
    return 1;
}
