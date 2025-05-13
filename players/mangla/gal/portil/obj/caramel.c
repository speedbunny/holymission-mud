inherit "obj/food";

reset(arg) {
    if(arg) return;
    set_name("caramel");
    set_short("A delicious chunk of Cadbury's Caramel");
    set_long("The soft caramel oozes from the smooth chocolate.\n");
    set_value(0);
    set_weight(1);
    set_eater_mess("The chocolate melts slowly on your toungue revealing"
      " the soft caramel inside. \n");
    set_strength(0);
}

init() {
	::init();
	add_action("give","give");
	say("The Cadbury`s bunny gives "+this_player()->query_short_name()+" a Cadbury`s Caramel.\n");
	write("The Cadbury`s bunny gives you a Cadbury`s Caramel.\n");
}

drop() {
	if(query_verb()=="give") return 1;
	write("Instead of dropping it you decide to eat it all up yourself.\n");
	say(this_player()->query_short_name()+" pigs out on a loverly Cadbury's Caramel.\n");
	destruct(this_object());
	return 1;
}

get() { return 1; }

give(string str) {
	object whoto;
	string name;
	if(!sscanf(str,"caramel to %s",name)) return 0;
	if(!name) return 0;
	name=lower_case(name);
	if(!present(name,environment(this_player()))) {
		notify_fail("Give the caramel to whom ?\n");
		return 0;
	}
	whoto=find_player(name);
	if(present("caramel",whoto)) {
		write("They already have one. You wouldn`t want them to be sick would you?\n");
	return 1;
	}
	tell_room(environment(this_player()),
		"The Cadbury`s bunny arrives.\nThe Cadbury`s bunny says: Take it easy, have a Cadbury`s Caramel.\n");
	transfer(clone_object("/players/portil/obj/caramel"),whoto);
	tell_room(environment(this_player()),
		"The Cadbury`s bunny wiggles its bottom.\nThe Cadbury`s bunny skips off.\n");
	return 1;
	}
