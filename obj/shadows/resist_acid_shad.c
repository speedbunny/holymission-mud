
/* resist acid shadow 

   Art: resistance against acid 1/2 damage 
   Attr-msg: resist acid 
   Special:  only one shadow at time
                                                      */

inherit "/obj/shadows/res_shad";

varargs int start_shadow(object who,int time)
{
        set_effect_msg("resist acid");
        element = 4;
        return ::start_shadow(who,time,"resist_acid",0);
}

