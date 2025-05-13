object mon;

immun() { return 1; }

start(whom, how_long) {
    object shad;

    if(!whom) destruct(this_object());
    else {
        mon=whom;
        shad=mon;
	while(shad) {
	    shad=shadow(shad,0);
	    if(mon->immun()) {
		destruct(this_object());
                return 1;
	    }
	}
        shadow(whom,1); 
	if(how_long>=0) call_out("remove_shadow",how_long);
    }
}

remove_shadow() {
    if(mon) tell_object(mon, "You feel mortal again!\n");
    unshadow();
}
hit_player(a) {
    tell_object(mon,a+" : ");
    return a;
} 


effects()
{
    string *eff;

    eff=mon->effects();
    if(!eff) eff=({ });
    eff+=({ "immun" });
    return eff;
}
