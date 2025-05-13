

// last edit 30.12.94 Whisky uni-linz-ac-at
inherit "room/room";

#define WIZ "/players/warlord/"

void reset(int arg) 
{
    ::reset(arg);

    if (!present("medium demon",this_object()))
        move_object(clone_object(WIZ+"monsters/demon2"),this_object());

    if (arg==0)
    {
      set_light(1);
      short_desc = "tower";
      long_desc = 
      "You are on the second floor, you feel an evil presence nearby..\n"+
      "You feel very scared right now..there is a medium size demon in your\n"+
      "path...\n";
      dest_dir = 
      ({
        "players/warlord/drac/tower1","down",
        "players/warlord/drac/tower3","up",
      });
    }
}

status move(string arg)
{
     if (!arg) 
          arg = query_verb();
     if (arg=="up" && present("medium demon",this_object()))
     {
        tell_room(this_object(),
        "Demon says: Thou Shalt Not Pass Without Vanquishing ME!!!\n");
	     return 1; 
     }
     return ::move(arg);
}

