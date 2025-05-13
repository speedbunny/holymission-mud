
/* tower4.c */

inherit "/room/room";

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
         dest_dir = ({
         "players/padrone/tower/hall", "up",
	 "players/padrone/tower/tower3", "down",
         });
	 short_desc = "Inside Padrone's private tower";
         long_desc =
	 "You are approximately at the third floor of Padrone's private\n" +
	 "tower. A stone staircase winds up and down from here.\n" +
	 "Above you you can see light from some kind of hall.\n";
      }
}
