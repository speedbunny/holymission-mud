inherit "/obj/std_shadow";

varargs int start_shadow(object who,int time)
{
	set_effect_msg("levitated");
        return ::start_shadow(who,time,"levitate_shad",0);
}

get(){
	write("You can't, it's levitated far above you!\n");
	return 0;
	}


end_shadow(object ob){
	tell_room(environment(this_object()), "The "+CAP(this_object()->query_name())+" slowly drifts back down to the ground.\n");
	::end_shadow(ob);
	}
