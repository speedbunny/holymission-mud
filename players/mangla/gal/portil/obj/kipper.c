id(str) {return(str=="kipper");}
short() {return "A kipper";}
long() {write("It is a very strange looking kipper.\nIt seems to be going off.\nMaybe you could show it to everyone.\n");
	return;}
get() {return 1;}
drop() {
	write("You try to drop the kipper but it seems to be stuck to your hand.\n");	
	return 1;}

reset(int arg) {
	if(!arg) return;
			return;
	write("The kipper wriggles a bit.\n");
	say(this_player()->query_name()+"`s kipper wriggles a bit and "+this_player()->query_pronoun()+" nearly drops it.\n");
	return;
	}

init() {
	add_action("show","show");
	add_action("smell","smell");
                call_out("kipperout",2);
	}

show(string str) {
	if(!str || str=="kipper") {
		write("You show your kipper to the people in the room.\n");
		say(this_player()->query_name()+" shows "+this_player()->query_possessive()+" kipper to you.\nYueck. It is starting to smell slightly.\n");
		return 1;
}
return 0;
}


smell(string str) {
	if(str=="kipper") {write("The kipper smells a little rotten.\n");
				return 1;
			}
return 0;
}

kipperout() {
		write("You take the kipper out of your mouth.\n");
		say(this_player()->query_name()+" takes "+this_player()->query_possessive()+" kipper out of "+this_player()->query_possessive()+" mouth.\n");
	return;
}

query_auto_load() {return "players/portil/obj/kipper:";}
