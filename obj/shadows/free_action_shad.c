// Free Action
// id: free_action
// attr-msg: free action
// no look-info
// non multiple

inherit "/obj/std_shadow";

immunity_paralyze() { return 1; }

start_shadow(who, time)
{
    set_effect_msg("free action");
    return ::start_shadow(who, time, "free_action");
}
