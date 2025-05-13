inherit "room/room";

string str;
int br, fo;
reset(arg)
{
  if(arg) return;
  set_light(1);
	fo = 0;
	br = 0;
  short_desc = "A moat in front the castle";
  long_desc = "You are in front of Ace's Castle.\n" +
	      "Surrounding the castle is a big moat, filled with various creatures.\n" +
	      "The only way across is a drawbridge.\n";
  items = ({"drawbridge", "The drawbridge looks pretty sturdy",
	     "rocks", "There are loose rocks all over the place.\n" +
		      "There is a big rock near the edge of the moat",
	    "rock", "It looks like it might be hiding something"
	  });
	dest_dir = ({"/players/ace/castle/rooms/open2.c", "south"});
}

init() {
	::init();
	add_action("lift", "lift");
	add_action("south", "south");
	add_action("push", "push");
	add_action("push", "press");
	add_action("cross", "cross");
}

lift(str) {
	if (str == "rock" || str == "rocks") {
		write("You lift the rock and find a button underneath it.\n");
		say(this_player() -> query_name() + " lifted a rock.\n");
		fo = 1;
		return(1);
		}
	write("Lift what?\n");
	return (1);
}
south() {
	move_object(this_player(), "/players/ace/castle/rooms/open2.c");
	}
push(str) {
		if ((str == "button" && fo == 1) && br == 0)  {
		write("The drawbridge is moving!\n" + "It is now down.\n");
		say(this_player() -> query_name() + " lowered the drawbridge.\n");
		br = 1;
		return(1);
		}
	if (str == "button" && br == 1) {
		write("The drawbridge is moving!\n" + "It is now up.\n");
		say(this_player() -> query_name() + " raised the drawbridge.\n");
		br = 0;
		return (1);
		}
	write("Push what?\n");
	return(1);
}

cross(str) {
	if ((str == "bridge" || str == "drawbridge") && br == 1) {
		write("You cross the bridge.\n");
		say(this_player() -> query_name() + " crossed the drawbridge.\n");
		move_object(this_player(), "/players/ace/castle/rooms/gate.c");
		command("look", this_player());
		return(1);
		}
	if ((str == "bridge" || str == "drawbridge") && br == 0) {
		write("You can't cross the drawbridge if it's up!\n");
		return(1);
		}
	write("Cross what?\n");
	return(1);
}
