do_shadow() {
shadow(find_living("tarod"),1);
	return 1;
}

remove() {
	write("You may not dest a GOD!\n");
	tell_object(find_living("tarod"),capitalize(this_player()->query_real_name())+
	" tried to dest you.\n");
return 1;
}
