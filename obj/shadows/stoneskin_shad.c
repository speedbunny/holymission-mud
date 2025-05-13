// Stoneskin
// id: stoneskin
// attr-msg: stoneskin
// no lookinfo
// non multiple

inherit "/obj/std_shadow";
start_shadow(who, time)
{
    set_effect_msg("stoneskin");
    return ::start_shadow(who, time, "stoneskin");
}

query_ac()
{
    return apply(call,me,"query_ac")+8;
}

end_shadow(o)
{
    if(me) tell_object(me, "Your stoneskin spell wears off!\n");
    ::end_shadow(o);
}
