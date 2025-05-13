inherit "room/room"; 
#include "/players/whisky/genesis/sys/filter_live.h"
#define _to this_object()

void reset (int arg) 
{
  if (filter_live(this_object()) < 3)
  {
   move_object(clone_object("/players/muzmuz/island/monsters/sandworm"),_to);
   move_object(clone_object("/players/muzmuz/island/monsters/sandworm"),_to);
   move_object(clone_object("/players/muzmuz/island/monsters/sandworm"),_to);
  }
  if (!arg) 
  {

     short_desc = "dunes";
      long_desc = "In the dunes. The air is very hot and dry. You should search for a more\n" +
                  "comfortable place. The sandworms guard a hole.\n";

       dest_dir=({"players/muzmuz/island/rooms/fc","north",
                  "players/muzmuz/island/rooms/fe","south",
                  "players/muzmuz/island/rooms/ed","west",
                  "players/muzmuz/island/rooms/gd","east",
                      });
      items =({"dunes","Huge dunes, covered with sand",
               "sand","Hot white sand",
               "hole","A dark hole...you are not sure if you dare to enter it",
                   });
      set_light (1);
      }
}

void init()
{
    add_action("fcn_enter","enter");
    ::init();
}

int fcn_enter(string arg)
{
   object wor;

    if (!arg || arg!="hole")
    {
       notify_fail("Enter what ?\n");
       return 0;
    }
    else if ( (wor= present("sandworm",this_object())) && living(wor) )
    {
       write("No way, the sandworms are guarding the hole !\n");
       say(this_player()->query_name()+
           " foolishly tried to get past the sandworms.\n");
       return 1;
    }
    switch(this_player()->query_size())
    {
       case 1:
       case 2:
         write("You easily slip into the hole.\n");
       break;
       case 3:
         write("You enter the hole.\n");
       break;
       default:
         write("With great effort, you manage to enter the hole.\n");
       break;
    }
    this_player()->move_player(
                   "into the hole#players/muzmuz/island/rooms/dunetr");
    return 1;
}
