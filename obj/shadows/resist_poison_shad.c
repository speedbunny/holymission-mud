
/* resist poison shadow 

   Art: resistance against poison 1/2 damage 
   Attr-msg: resist poison 
   Special:  only one shadow at time
                                                      */

inherit "/obj/shadows/res_shad";

varargs int start_shadow(object who,int time)
{
        set_effect_msg("resist poison");
        element = 9;
        return ::start_shadow(who,time,"resist_poison",0);
}

