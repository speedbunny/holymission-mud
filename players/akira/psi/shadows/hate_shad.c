inherit "/obj/std_shadow";
int wc, hate, att;

check_attack(){
   object enemy;
	enemy=this_player()->query_attack();
	if(!enemy){
	    write("You are not under attack!\n");
	    return 1;
	    }
	if(environment(this_player()) != environment(enemy)){
	    write("Your enemy is not here!\n");
	    return 1;
	    }
	else{
	     this_player()->attack();
	     write("Your hatred come out!\n");
	     return 1;
	     }
	}
varargs int start_shadow(object who, int time)
{
	wc=who->query_wc();
	who->set_n_wc(wc+4);
	set_effect_msg("hatred");
	hate=1;
	att=0;
	return ::start_shadow(who, time, "hate_shad", 0);
}

attack(o,h){
	if(this_player()->query_guild()==3){
	    this_player()->attack();
	    att=att+1;
	    if(att/4){
	  	this_player()->attack();
	    	write("Your hatred comes out!\n");
		return 1;
		}
	    return 1;
	    }
	else{
	check_attack();
	this_player()->attack();
	this_player()->attack();
	}
	}
query_ac(){
     	return apply(call,me,"query_ac")-8;
	}

end_shadow(ob){
	if(me) tell_object(me, "You regain your wits and calm down.\n");
	wc=this_player()->query_wc();
	write("First sucess!\n");
	this_player()->set_n_wc(wc-4);
	write("Second sucess!\n");
	::end_shadow(ob);
	}
