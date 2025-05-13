object jj;

reset(arg) {
	if (!find_living("ishenvendor")
		|| !environment(find_living("ishenvendor")) ) {
		jj = clone_object("players/qclxxiv/ishenvendor");
		move_object(jj,"room/vill_road2");
	}
	return;
}
