inherit "obj/alco_drink";
object giver;

reset(arg) {
  ::reset(arg);
	if (arg) return;
  name="double";
  alias="beer";
  alt_name = "bottle";
  short_desc="A bottle of double beer";
  long_desc="A bottle of double beer. Type: beergive <someplayer>.\n";
  drinker_mess = "Wow is that double good.\n";
  drinking_mess = " gulps down a double beer.\n";
  strength=1;
}

init() {
	::init();
	add_action("beergive","beergive");
}

beergive(arg) {
	object obj;
	if (arg ) {
		if (giver) {
			write("This beer has been given to you.\n");
			write("Go to Qclxxiv's Luxury Shop if you wanna give beer away.\n");
			return 1;
		}
		obj = find_player(arg);
		if (obj && environment(obj)) {
			set_giver(this_player());
			if (transfer(this_object(),obj)==0) {
				write("You give the double to "+arg+".\n");
				tell_object(obj,this_player()->query_name()
						+" sends you a double beer.\n");
			}
			else {
				write("You fail to give the double to "+arg
						+", perhaps it is too heavy now.\n");
			}
		}	
		else write("Can't find "+arg+".\n");
		return 1;
	}
	return 0;
}

drop() {
	if (!full) {
		tell_object(environment(), 
"The bottle breaks into dust-like pieces, blown away into all directions.\n");
		destruct(this_object());
		return 1;
	}
	return 0;
}

set_giver(obj) {
	giver = obj;
  short_desc="A bottle of double beer from "+obj->query_name();
  long_desc="A bottle of double beer from "+obj->query_name()+".\n";
}

drink(arg) {
	if (id(arg)) {
		if (giver && living(giver) && environment(giver)) {
			write("You say cheers to "+giver->query_name()+".\n" );
			tell_object(giver,this_player()->query_name()
					+" says cheers to you.\n");
		}
		return ::drink(arg);
	}
	else return 0;
}
