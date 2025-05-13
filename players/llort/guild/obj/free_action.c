object mon;

immunity_paralyze() { return 1; }

query_free_action() { return 1; }

start_shadow(whom, how_long) {
    object shad;

    if(!whom) destruct(this_object());
    else {
        mon=whom;
        shad=mon;
	while(shad) {
	    shad=shadow(shad,0);
	    if(shad && shad->query_free_action()) {
		destruct(this_object());
                return 1;
	    }
	}
        shadow(whom,1); 
    }
}
