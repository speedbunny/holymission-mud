
/* resist elect shadow 

   Art: resistance against electricity 1/2 damage 
   Attr-msg: resist electric 
   Special:  only one shadow at time
                                                      */

inherit "/obj/shadows/res_shad";

varargs int start_shadow(object who,int time)
{
        set_effect_msg("resist electric");
        element = 2;
        return ::start_shadow(who,time,"resist_electric",0);
}

