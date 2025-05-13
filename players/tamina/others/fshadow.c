object mon;

query_fireshield() { return 1; }

start_shadow(whom, how_long) {
    object shad;

    if(!whom) destruct(this_object());
    else {
        mon=whom;
        shad=mon;
	while(shad) {
	    shad=shadow(shad,0);
	    if(shad && shad->query_fireshield()) {
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

short(flag) {
    if(flag) return mon->short(flag);
    return (mon->short(flag)+", emitting a faint golden aura");
}


hit_player(x,kind) {
    int dam;
    dam=mon->hit_player(x,kind);
    if(kind!=5 && kind!=7) {
        this_player()->hit_player(dam*2,5);
    }
    return dam;
}

remove_shadow() {
    tell_object(mon, "Your fireshield wears off!\n");
    unshadow();
}
