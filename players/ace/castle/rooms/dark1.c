inherit "room/room";

status found;
string str;

reset(arg)
{
  if(arg) return;
  found = 0;
  set_light(0);
  short_desc = "A seemingly dead end.";
  long_desc = "You are at a dead end in front of a huge mass of trees.\n" +
              "The trees look like they might be hiding something, but there are\n" +
              "no obvious exits.\n";
              "To the north you can see the castle towering in front of you.\n";
  dest_dir = ({
    "players/ace/castle/rooms/open10","south"
	     });
  items = ({"trees", "There seems to be an opening in the trees.\n" +
                     "You might be able to push them apart enough to enter."
          });
}
init() {
	add_action("push", "push");
	add_action("enter", "enter");
	add_action("south", "south");
}
  push(str) {
	if (str == "trees" || str == "branches") {
		write("You found an entrance to a cave!\n");
 		say(this_player()->query_name() + " found a cave!\n");
		found = 1;
		return(1);
		}
	write("Push what?\n");
	return (1);
	}
  south(str) {
	move_object(this_player(), "/players/ace/castle/rooms/open10.c");
	command("look", this_player());
	return(1);
	}
  enter(str) {
	if ((str == "cave" || str == "trees") && found == 1) {
	write("You entered the cave.\n");
	say(this_player() -> query_name() + " entered the cave.\n");
	move_object(this_player(), "/players/ace/castle/rooms/cave1.c");
	command("look", this_player());
	return(1);
	}
	write("Enter what?\n");
	return(1);
  }
