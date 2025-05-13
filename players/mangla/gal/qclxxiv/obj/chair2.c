object sitting;
object chairsoul;
string name, alias;
string a_name;
string the_name;

set_name(s) { 
	name = s; 
	if (!a_name) a_name= "a "+name;
	if (!the_name) the_name= "the "+name;
}
set_alias(s) { alias = s; }
set_a_name(s) { a_name = s; }
set_the_name(s) { the_name = s; }

query_sitting() {
	if (sitting) {
		if (!present(sitting)) {
			if (shadow(sitting,0) 
					&& shadow(sitting,0)->query_chairsoul() )
				destruct(shadow(sitting,0));
			sitting = 0;
		}
	}	
	return sitting;
}

id(arg) { return arg==name || arg==alias || arg==the_name || arg==a_name
				|| arg=="q174chair"; }

query_weight() { return 1000; }

reset(arg) { 
	if (arg) return;
	name = "chair";
	a_name = "a chair";
	the_name = "the chair";
	alias = "chair";
}

short() { 
	object who;
	if ((who=query_sitting())) {
		if (who==this_player())
			return capitalize(a_name)+ ", you are sitting on it";
		else return capitalize(a_name)+", "+sitting->query_name()
									+" sitting on it";
	}
	return capitalize(a_name);
}

long() {
	object who;
	if ((who=query_sitting())) {
		if (who==this_player())
			write(capitalize(a_name)+", you are sitting on it.\n" );
		else write(capitalize(a_name)+", "+sitting->query_name() 
						+" sitting on it.\n" );
	}
	else write(capitalize(a_name)+".\n");
	return 1;
}

init() {
    add_action("sit", "sit");
    add_action("standup", "stand");
}

sit(arg) {
	string s;
	if ( arg && ( (sscanf(arg,"on %s",s) && id(s)) 
			|| (sscanf(arg,"down on %s",s) && id(s)) ) ) {

	}
	else return 0;
	if (query_sitting()) {
		if (sitting==this_player()) {
			write("But you're already sitting on it...\n");
			return 1;
		}
		else write("But "+sitting->query_name()+" is already sitting on it.\n");
		return 0;
	}
	if (present("qchairsoul",this_player())) {
		write("But you're already sitting...\n");
		return 1;
	}
	sitting = this_player();
	say(this_player()->query_name() +" sits down on "+a_name+".\n",
			this_player());
	write("You sit down on a "+a_name+".\n");
	chairsoul = clone_object("/players/qclxxiv/obj/chairsoul");
	/* move_object(chairsoul, this_object() ); */
	chairsoul->possess(sitting);
	chairsoul->set_mychair(a_name);
	return 1;
}

standup(arg) {
	string s;
	if ( arg && ( ( sscanf(arg,"from %s",s) && id(s))
				|| ( sscanf(arg,"up from %s", s) && id(s))
				|| (arg=="up") ) ) {
	}
	else return 0;
	if (query_sitting()) {
		if (sitting==this_player()) {
			say(this_player()->query_name() +" stands up from "
					+a_name+".\n", this_player() );
			write("You stand up from "+the_name+".\n");
			if (shadow(this_player(),0) 
					&& shadow(this_player(),0)->query_chairsoul() )
				destruct(shadow(this_player(),0));
			sitting = 0;
			return 1;
		}
	}
	return 0;
}

