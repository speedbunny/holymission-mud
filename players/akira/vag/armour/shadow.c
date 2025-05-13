

inherit "/obj/std_shadow";

varargs int start_shadow(object who,int time)
{
    set_effect_msg("tshield");
    set_look_info("(Time Shield)");
    return ::start_shadow(who, time, "tshield", 0);
}

varargs int hit_player(int dam,int kind,mixed elem)
{
    if (kind == 0)
        return apply(call,me, "hit_player", (dam/3), kind, elem);
    return apply(call,me,"hit_player",dam,kind,elem);
}

void end_shadow(object ob)
{
     tell_object(me,
     "The Time Shield Around Your Body Fades Into Nothingness!\n");
     ::end_shadow(ob);
}


