
inherit "/room/room";


void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
       set_light(1);
       short_desc ="Entrance to the hideout";
       long_desc =
       "You are in a small dusty room. To the south you can\n"+
       "enter the place where thieves use to leave stuff for\n"+
       "the newbies. The infamous thief, Kitai Analor, watches\n"+
       "the entrance, but you thought he was dead!\n";
    
       dest_dir = 
       ({
          "/players/wolfi/room/in_river","north",
       });
    }
}


void init()
{

  object hotz;

  hotz = present("kitai",this_object());

  if (this_player()->query_guild()!=1 && !hotz)
  {
     tell_room(this_object(),
               "Kitai Analor steps out of the light! Now that's hiding!\n");
     move_object(clone_object("/players/blade/guild/monster/hotz"),
                 this_object());
  }
  ::init();
}
  


