
/* barkskin 
   Effect: Raises the standard armour_class by 3
   Attr-msg: barkskin
   Extra: only one shadow at a time 
                                                           */

inherit "/obj/std_shadow";

varargs int start_shadow(object who, int time)
{
    set_effect_msg("barkskin");
    return ::start_shadow(who,time,"barkskin",0);
}

int query_ac()
{
    return( apply(call,me,"query_ac") + 3);
}
   
void end_shadow(object ob)
{
   tell_object(me,"Your barkskin wears off.\n");
   ::end_shadow(ob);
}
