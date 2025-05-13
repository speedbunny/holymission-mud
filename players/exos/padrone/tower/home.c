

inherit "/room/room";

void reset(int flag)
{
     if (flag == 0)
     {
      set_light(1);
      dest_dir =
      ({
        "players/padrone/workroom", "out",
      });
      short_desc =  
      "Padrone's private home";
      long_desc = 
      "You are in Padrone's private home. What are you doing there?\n";
      }
}
