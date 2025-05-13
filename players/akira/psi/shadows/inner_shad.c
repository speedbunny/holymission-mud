inherit "/obj/std_shadow";

varargs int start_shadow(object who,int time)
{
	set_effect_msg("inner strength");
        return ::start_shadow(who,time,"inner_strength_shad",0);
}

query_maxhp(){
	return 980;
	}
query_con(){
	return (apply(call,me,"query_con")+10);
	}

query_stats(x){
	if(x==2){ return me->query_stats(x)+10;}
	else{
	    return me->query_stats(x);
	    }
	}

end_shadow(object ob){
	tell_object(me, "You lose your inner strength!\n");
	::end_shadow(ob);
	}
