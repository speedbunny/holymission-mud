
inherit "/room/room";

void reset(int flag)
{
    if (flag==0)
    {
       set_light(1);
       dest_dir =({
         "players/padrone/tower/poolroom", "up",
       });
       short_desc = "In the Pool";
       long_desc =
	 "You are swimming in the pool. La-di-da!\n" +
	 "This place isn't very useful yet, though.\n";
     }
}
