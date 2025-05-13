inherit "room/room";

reset(arg)
{
  if(arg) return;
  set_light(0);
  short_desc = "A seemingly dead end.";
  long_desc = "You are at a dead end in front of a huge mass of trees.\n" +
              "The trees look like they might be hiding something, but there are\n" +
              "no obvious exits except back.\n";
              "To the north you can see the castle towering in front of you.\n";
  dest_dir = ({
	       "/players/ace/castle/rooms/open9.c", "south"
	      });
}
