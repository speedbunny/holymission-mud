inherit "room/room";

reset(arg)
{
  if(arg) return;
  set_light(0);
  short_desc = "A dark, murky cave.";
  long_desc = "You have entered a drak cave near the Castle.\n" +
              "The way you came in has been covered by fallen rocks.\n" +
              "There is no choice but to see what lies ahead.\n";
  dest_dir = ({
	       "/players/ace/castle/rooms/cave3.c", "north"
	      });
}
