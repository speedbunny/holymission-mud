
/* bless 

   Effect: better damage
   Attr: bless
   Special: only one at a time
                                                    */

inherit "/obj/std_shadow";

varargs int start_shadow(object who,int time)
{
       set_effect_msg("bless");
       return ::start_shadow(who,time,"bless");
}
   
void end_shadow(object ob)
{
   tell_object(me,"You feel less holy.\n");
   ::end_shadow(ob);
}

int enhanced_dam()
{
    return (apply(call,me,"enhanced_dam") + 10);
}


