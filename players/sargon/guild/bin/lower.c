lower(object *bloarm) {
    if(!bloarm) {
	notify_fail("You are not blocking.\n");
	return 0;
	}

	destruct(bloarm);
	write("You lower your block.\n");
	return 1;
}
