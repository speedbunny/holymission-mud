inherit "room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  short_desc = "Ace's Castle, 1st floor";
  long_desc = "This is the entrance to the castle.  It is huge!\n" +
	      "At first glance, it looks like there are hundreds of rooms.\n" +
	     "You can sense that evil lurks from this place.\n";
  dest_dir = ({
	       "/players/ace/castle/rooms/castle4-1.c", "north",
	       "/players/ace/castle/rooms/castle2-1.c", "west",
	       "/players/ace/castle/rooms/gate.c", "south",
               "/players/ace/castle/rooms/castle3-1.c", "east"
	      });
}
