// Detect Invisibility Shadow
// give 'who' a detect invis for 'time' seconds
// id: detect_invis
// attr-msg: detect invisibility
// no look-info
// it can be cast multiple

inherit "/obj/std_shadow";

detect_invis() { return 1; }

start_shadow(who, time)
{
    set_effect_msg("detect invisibility");
    return ::start_shadow(who,time,"detect_invis",1);
}

end_shadow(ob)
{
    tell_object(me, "The yellow blure in your vision fades!\n");
    ::end_shadow(ob);
}
