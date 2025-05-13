inherit "room/room";
#include "/players/whisky/genesis/sys/filter_live.h"
#define _to this_object()

void reset (int arg) 
{
  if (filter_live(this_object()) < 2)
  {
   move_object(clone_object ("players/muzmuz/island/monsters/mudmonster"),_to);
   move_object(clone_object ("players/muzmuz/island/monsters/mudmonster"),_to);
   move_object(clone_object ("players/muzmuz/island/monsters/mudmonster"),_to);
  }
  if (!arg) 
  {
        short_desc = "swamps";
        long_desc = "You are in the middle of the swamps. The air seems to be steaming. You haven`t\n" +
                     "ever seen so many mosquitos at once as they are here.\n" +
                     "The mudmonsters guard a hole. \n";

          dest_dir = ({"players/muzmuz/island/rooms/fm","north",
                       "players/muzmuz/island/rooms/fo","south",
                       "players/muzmuz/island/rooms/en","west",
                       "players/muzmuz/island/rooms/gn","east",
                               });
        items =({"swamps","Huge moist swamps",
                   "mosquitos","Lots of mosquitos buzzing around you",
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
  object mud;

   if (!arg || arg!="hole")
   {
      notify_fail("Enter what ?\n");
      return 0;
   }
   else if ( (mud=present("mudmonster",this_object())) && living(mud))
   {
      write("No way, the mudmonsters are guarding the entrance !\n");
      say(this_player()->query_name()+
          " foolishly tried to get past the mudmonsters.\n",this_player());
      return 1;
   }
   write("You enter the hole.\n");
   this_player()->move_player(
                 "into the hole#players/muzmuz/island/rooms/swamptr");
   return 1;
}

