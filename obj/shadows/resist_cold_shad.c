
/* resist cold shadow 

   Art: resistance against cold 1/2 damage 
   Attr-msg: resist cold 
   Special:  only one shadow at time
                                                      */

inherit "/obj/shadows/res_shad";

varargs int start_shadow(object who,int time)
{
        set_effect_msg("resist cold");
        element = 3;
        return ::start_shadow(who,time,"resist_cold",0);
}

