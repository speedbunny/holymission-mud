inherit "room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  short_desc = "Ace's Castle, 1st floor";
  long_desc = "You have entered a ead-end in the castle.\n" +
	      "If front of you looks like one of the towers of the castle.\n";
  dest_dir = ({
               "/players/ace/castle/rooms/castle1-1.c", "east"
	      });
}
