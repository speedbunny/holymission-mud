object jj;

reset(arg) {
 	if (!jj) { 
		jj = clone_object("players/qclxxiv/jackjunk2");
		move_object(jj,"room/clearing");
    }
	else if (!environment(jj))
		move_object(jj,"room/clearing");
	return;
}
