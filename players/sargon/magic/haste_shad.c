
#define REG_TIME  120

inherit "/obj/std_shadow";

int hasted_till;
int do_haste;

start_shadow(whom, tim)
{
    set_effect_msg("haste");
    hasted_till=time();
    do_haste=1;
    return ::start_shadow(whom, tim, "haste");
}

chk_all_shadows()
{
    if(do_haste && time() > hasted_till)
    {
        do_haste=0;
        _id="haste_reg";
        effect=0;
        tell_object(me,"You feel slowing down again. You are REALLY tired.\n");
    }
    ::chk_all_shadows();
}

attack(o,h)
{
    int rtc;
    if(!do_haste) return apply(call,me,"attack");
    if(apply(call,me,"shad_id","haste_reg") &&
       random(150) < 75-apply(call,me,"query_level"))
    {
        tell_object(me,"You stumble and hit yourself HARD.\n");
        me->hit_player(random(apply(call,me,"query_str"))+10,8);
        return 1;
    }
    if(rtc=apply(call,me,"attack",o,h))
        rtc=apply(call,me,"attack",o,h); 
    return rtc;
}
