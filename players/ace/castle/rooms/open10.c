inherit "room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  short_desc = "An opening near Ace's Castle";
  long_desc = "You're at an opening in front of Ace's Castle.\n" +
              "To the north you see nothing but darkness.\n";
  dest_dir = ({
	       "/players/ace/castle/rooms/dark1.c", "north",
	       "/players/ace/castle/rooms/open8.c", "east"
	      });
}
