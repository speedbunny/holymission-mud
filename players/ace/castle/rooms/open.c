inherit "room/room";

reset(arg)
{
  if (arg) return;
  set_light(1);
   short_desc = "Castle Opening";
   long_desc = "You stand in front of a huge castle.\n" +
	       "The castle has 5 towers, 4 on the corners and one at the far end.\n" +
               "There are many trees surrounding you, but the path\n" +
               "To the north is open.\n";

dest_dir = ({
             "/players/ace/castle/rooms/open2.c", "north"
           });
}
   
