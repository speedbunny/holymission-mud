id(str) { return str == "spade"; }
short() { return "An adventurer's spade"; }
long()  { write("An adventurer's spade. No real adventurer would set off for\n"
+"adventure without it.\n"); }
query_weight() { return 1; }
query_value() { return 15; }
get() { return 1; }

init()  { 
	add_action("dig", "dig" );
}

dig(str) {
	string mssg;
	if (environment(this_object())!=this_player()) return 0;
	mssg = environment(this_player())->dig(this_player());
	if (mssg) {
		write("Ok.\n");
		say( this_player()->query_name()+" starts to dig.\n", this_player());
		write(mssg);
	}
	else {
		tell_room( environment(this_player()), 
				this_player()->query_name()+" tries to dig but fails.\n");
		write("You cannot dig here, at least not with this spade.\n");	
	}
	return 1;
}

