object mon;
int newstr;

strengthed() { return 1; }

start_shadow(whom, how_long) {
    object shad;

    if(!whom) destruct(this_object());
    else {
        mon=whom;
        shad=mon;
	while(shad) {
	    shad=shadow(shad,0);
	    if(shad && shad->strengthed()) {
		tell_object(mon,"Nothing seems to happen.\n");
		destruct(this_object());
                return 1;
	    }
	}
        newstr = (50-whom->query_r_stats(0))/4 +
                 this_player()->query_level()/5 + 1;
        shadow(whom,1); 
        tell_object(mon,"Your really feel stronger now.\n");
	if(how_long>=0) call_out("remove_shadow",how_long);
    }
}

query_str()
{
   if(environment(mon)->stat_room()) return mon->query_str();
   return mon->query_str()+newstr;
}

query_stats(x)
{  
   if(environment(mon)->stat_room()) return mon->query_stats(x);
   if(x == 0) return mon->query_stats(x)+newstr;
   else return mon->query_stats(x);
}

remove_shadow() {
    tell_object(mon, "You feel weaker now!\n");
    unshadow();
}
