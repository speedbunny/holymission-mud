inherit "room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  short_desc = "Ace's Castle, 1st floor";
  long_desc = "You have entered a narrow passage in the castle.\n" +
	      "There seems to be nothing around...\n";
  dest_dir = ({
	       "/players/ace/castle/rooms/tower3-1.c", "north",
               "/players/ace/castle/rooms/castle17-1.c", "south"
	      });
}
