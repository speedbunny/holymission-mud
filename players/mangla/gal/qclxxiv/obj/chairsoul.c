object myobj;
string mychair;

query_chairsoul() { return 1; }
set_mychair(s) { mychair = s; }

possess(object pl) {
/*	if (pl) tell_object(pl, "Going to possess you.\n"); */
	myobj = shadow(pl, 1);
/*	if (myobj) tell_object(myobj, "Possession succeeded.\n"); */
}


/*
query_name(arg) {
	return 0;
}
*/

short(arg) {
	return 0;
}

/*
long(arg) {
	write(myobj->query_name()+" sitting on "+mychair+".\n");
	return ::long();
}
*/
