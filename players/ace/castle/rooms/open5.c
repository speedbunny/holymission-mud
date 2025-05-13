inherit "room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  short_desc = "An opening near Ace's Castle";
  long_desc = "You're at an opening in front of Ace's Castle.\n" +
              "To the north you can see the castle towering in front of you.\n";
  dest_dir = ({
	       "/players/ace/castle/rooms/open6.c", "west",
	       "/players/ace/castle/rooms/end2.c", "south",
               "/players/ace/castle/rooms/open2.c", "east"
	      });
}
