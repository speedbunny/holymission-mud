


inherit "/obj/shadows/res_shad";

varargs int start_shadow(object who,int time)
{
	set_effect_msg("resist energy");
	  	 element = 5;
        return ::start_shadow(who,time,"resist_energy",0);
}

