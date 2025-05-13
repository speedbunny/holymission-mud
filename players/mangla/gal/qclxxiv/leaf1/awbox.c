int weight;
int player_in;
int mynum;
object myroom;

set_num(n) { mynum = n; }
get_num() { return mynum; }

id(str) { return str == "large box" || str == "box"; }
short() { return "A large box"; }
long()  { write("A large box. It looks rather heavy. It has been secured with\n"
+"a kind of lock you never saw before, but you guess you can't open it.\n"); }
query_value() { return 0; }

query_weight() { 
	if (player_in) return 10000;
	if (this_player() && living(this_player()) ) {
		if (environment(this_object())==this_player()) return weight; 
		weight = this_player()->query_level()
			+ (this_player()->query_str()/2)+10-this_player()->query_weight();	
		weight-=2;
		if (weight<7) weight=7;
	}
	return weight;
}

get() { 
	if (player_in) return 0;
	if (this_player() && this_player()->query_npc()) return 0;
	weight = this_player()->query_level()
		+ (this_player()->query_str()/2)+10-this_player()->query_weight();	
		weight-=2;
	if (weight<7) weight=7;
	return 1; 
}

init()  { 
	add_action("open", "open" );
	add_action("unlock", "unlock" );
	add_action("enter", "enter" ); 
	/* add_action("how", "how"); */
}

how(str) { write("Current weight: "+weight+".\n"); return 1; }

open(str) {
	if (id(str)) {
		write("After trying it for sure, you now know you can't open it.\n");
		write(
"However, for some reason you get the feeling that if you wish hard enough\n"
+"you might be able to enter it.\n");
		return 1;
	}
}

unlock(str) {
	if (id(str) || str=="box with key") {
		write("After trying it for sure, you now know you can't unlock it.\n");
		write(
"However, for some reason you get the feeling that in some odd way you might\n"
+"magically be able to enter it.\n");
		return 1;
	}
}

clone_myroom() {
	myroom = clone_object("/players/qclxxiv/leaf1/boxroom");	
	myroom->set_mybox(this_object());
}

enter(str) {
	if (id(str)) {
		if (player_in) {
			if (environment(player_in)!=myroom)
				player_in = 0;
		}
		if (player_in  && !this_player()->query_npc() ) {
			write(
"You can't seem to enter the box. Probably there is someone in already.\n");
			return 1;
		}
		write("You magically enter the box.\n");
		say( this_player()->query_name()+" magically enters the box.\n");
		if (!myroom) clone_myroom();
    	this_player()->move_player( "into box", myroom );
		if (!this_player()->query_npc()) player_in = this_player();
		return 1;
	}
}

exit_player(tp) {
	write("You magically leave the box.\n");
	tell_room( environment(),
		this_player()->query_name()+" magically comes out of the box.\n");
	player_in = 0;
}

save_exit_player(tp) {
	player_in = 0;
}
