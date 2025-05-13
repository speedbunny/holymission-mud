// Shield
// id: shield
// attr-msg: shield
// no look-info
// non multiple

inherit "/obj/std_shadow";
shielded() { return 1; }

start_shadow(who,time)
{
    set_effect_msg("shield");
    return ::start_shadow(who,time,"shield",0);
}

query_ac()
{
    return apply(call,me,"query_ac")+2;
}

end_shadow(o) {
    if(me) tell_object(me, "Your shield fades away happily!\n");
    ::end_shadow(o);
}
