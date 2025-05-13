object mon;

fireshielded() { return 1; }

start_shadow(whom, how_long) {
    object shad;

    if(!whom) destruct(this_object());
    else {
        mon=whom;
        shad=mon;
	while(shad) {
	    shad=shadow(shad,0);
	    if(mon->fireshielded()) {
		tell_object(mon,"You already have a fireshield.\n");
		destruct(this_object());
                return 1;
	    }
	}
        shadow(whom,1); 
        tell_object(mon,"A strange golden aura envelopes your body.\n");
	if(how_long>=0) call_out("remove_shadow",how_long);
    }
}

look_info(flag) {
    if(flag) return 0;
    return ("(emitting a faint golden aura)");
}

short(flag)
{
    string tmp;

    tmp = mon->short(flag);
    if (!tmp) return 0;
    if(flag) return tmp;
    return tmp+look_info();
}

hit_player(x,kind) {
    int dam;
    dam=mon->hit_player(x,kind);
    if(this_player()!=mon && kind!=5 && kind!=7) {
        this_player()->hit_player(dam*2,5);
        if(this_player()) tell_object(this_player(),"You burn yourself badly on the golden aura of your opponent.\n");
    }
    return dam;
}

remove_shadow() {
    tell_object(mon, "Your fireshield wears off!\n");
    unshadow();
}
