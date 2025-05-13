// Armor Shadow
// give the living 'who', a armor for 3 ac for 'time' seconds
// id: armor
// attr-msg: armor
// no look-info
// non multiple

inherit "/obj/std_shadow";

start_shadow(who, time)
{
    set_effect_msg("armor");
    return ::start_shadow(who, time, "armor",0);
}

query_ac()
{
    return apply(call,me,"query_ac")+3;
}

end_shadow(ob) {
    if(me) tell_object(me, "You feel less protected!\n");
    ::end_shadow(ob);
}
