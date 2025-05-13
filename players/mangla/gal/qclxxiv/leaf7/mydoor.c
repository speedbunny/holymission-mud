
enter(arg) {
	if (arg=="mushroom") {
		if (!closed) {
    		this_player()->move_player( "into mushroom#players/qclxxiv/leaf7/inmush1");
		}
		else write("But the door is closed.\n");
		return 1;
	}
	return 0;
}

open(arg) {
	if (arg=="door") {
		if (!closed) write("The door is already open.\n");
		else if (locked) write("But the door is locked.\n");
		else {
			notify("peeep.\n");
			closed=0;
		}
		return 1;
	}
	return 0;
}

unlock(arg) {
	if (arg=="door") {
		if (!locked) write("The door is already unlocked.\n");
		else {
			notify("klack.\n");
			locked =0;
		}
		return 1;
	}
	return 0;
}

lock(arg) {
	if (arg=="door") {
		if (locked) write("The door is already locked.\n");
		else if (!closed) write("But the door is open.\n");
		else {
			notify("klick.\n");
			locked =1;
		}
		return 1;
	}
	return 0;
}

close(arg) {
	if (arg=="door") {
		if (closed) write("The door is already closed.\n");
		else {
			notify("peeep.\n");
			closed =1;
		}
		return 1;
	}
	return 0;
}


