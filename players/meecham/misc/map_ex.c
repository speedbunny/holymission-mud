inherit "room/room";
 
mapping scared;
 
reset(arg)
{
   scared = ([ ]);
   if(arg)
      return;
   short_desc = "Behind the bar";
   long_desc = "You are behind the bar. You can enter the barroom\n" +
               "proper to the east. There is a very large barrel of\n" +
               "beer here. It should be possible to drink from the tap...\n";
   set_light(1);
   dest_dir = ({ "players/kantele/bar", "east" });
}
 
init()
{
   ::init();
   add_action("drink_beer", "drink");
}
 
drink_beer(arg)  // green slime by Phylax Oct 2, 1994
{
   if(arg != "from tap" && arg != "from the tap")
      return 0;
   if(member(scared,this_player()->query_real_name())) {
      write("No way! Do you remember the green slime??\n");
   return 1;
   }
   if(!random(15)) {
      write("Suddenly, you see some green slime on the tap and of course you\n"+
            "swallow it. That is DISGUSTING!\n");
      scared += ([ this_player()->query_real_name() ]);
   } else
   if(call_other(this_player(), "drink_alcohol", 2))
      write("It tasted a bit stale\n");
   return 1;
}
