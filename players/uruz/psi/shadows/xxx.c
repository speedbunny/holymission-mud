inherit "/obj/std_shadow";
int wc;

int hate;
varargs int start_shadow(object who,int time)
{
	wc= who->query_wc();
	who->set_n_wc(wc+4);
	set_effect_msg("hatred");
	hate=1;
        return ::start_shadow(who,time,"hate_shad",0);
}

attack(o, h){
   int rtc;
	if(!hate){ return apply(call,me,"attack",o,h);}
	if(rtc=apply(call,me,"attack",o,h))
	   rtc=apply(call,me,"attack",o,h);
	return rtc;
	}
query_ac(){
     	return apply(call,me,"query_ac")-8;
	}

end_shadow(ob){
	if(me) tell_object(me, "You regain your wits and calm down.\n");
	ob->set_n_wc(wc);
	::end_shadow(ob);
	}
