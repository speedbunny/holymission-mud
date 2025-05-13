// True Sight
// id: true_sight
// attr-msg: true sight
// no look-info
// non multiple

inherit "/obj/std_shadow";
infravision() { return 10; }
detect_invis() { return 1; }

start_shadow(who, time)
{
    set_effect_msg("true sight");
    return ::start_shadow(who, time, "true_sight");
}

end_shadow(o)
{
    tell_object(me, "Your vision clouds!\n");
    ::end_shadow(o);
}
