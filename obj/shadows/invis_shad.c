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
        this_player()->set_invis();
        set_effect_msg("invisibility");
        set_look_info("[inv]"); 
        return ::start_shadow(who, time, "invis",0);
    };
}

attack()
{
    end_shadow(this_object());
    return me->attack();
}

end_shadow(o) {
    if(me) tell_object(me, "You feel exposed!\n");
    this_player()->set_invis(0);
    destruct(this_object());
}
