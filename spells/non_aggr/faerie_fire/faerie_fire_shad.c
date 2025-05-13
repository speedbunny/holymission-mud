// Faerie Fire Shadow
// reduces 'who's ac by 3 for 'time' seconds
// id: faerie_fire
// attr-msg: faerie fire
// look-info: pink aura
// no multiple shadows

inherit "/obj/std_shadow";

start_shadow(who, time)
{
    set_effect_msg("faerie fire");
    set_look_info("(pink aura)");
    return ::start_shadow(who, time, "faerie_fire",0);
}

query_ac()
{
    int ac;

    ac = apply(call,me,"query_ac") - 5;
    if (ac>30) ac=25; else if (ac<0) ac=0;
    return ac;
}

end_shadow(o) {
    if(me) tell_object(me, "Your pink aura fades away!\n");
    ::end_shadow(o);
}
