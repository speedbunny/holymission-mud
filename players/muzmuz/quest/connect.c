inherit "room/room";

void reset(int arg)
{
  if(!arg)
  { 

      short_desc = "Path";
       long_desc = "You are standing in front of a rather nice house.\n" +
                   "It is in good shape and it seems to be inhabited.\n" +
                   "The door is open and you may enter it.\n";

        items = ({"door","It is open",
                  "house","It looks nice. You wonder how it is inside",
                      });

        dest_dir =({"players/muzmuz/quest/hall","enter",
                    "players/mangla/rooms/newbie/new15","west",
                         });


        set_light (1);

}
}
         
 
