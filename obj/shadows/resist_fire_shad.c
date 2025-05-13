
/* resist fire shadow 

   Art: resistance against fire 1/2 damage 
   Attr-msg: resist fire
   Special:  only one shadow at time
                                                      */

inherit "/obj/shadows/res_shad";

varargs int start_shadow(object who,int time)
{
        set_effect_msg("resist fire");
        element = 1;
        return ::start_shadow(who,time,"resist_fire",0);
}

