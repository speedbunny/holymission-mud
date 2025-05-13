// Infravision
// give 'who' infravision for 'time' seconds
// id: infravision
// attr-msg: infravision
// no look-info
// non-multiple

inherit "/obj/std_shadow";

infravision() { return 1; }

start_shadow(who, time)
{
    set_effect_msg("infravision");
    return ::start_shadow(who, time, "infravision");
}

end_shadow(o)
{
    tell_object(me, "Your vision dims!\n");
    ::end_shadow(o);
}
