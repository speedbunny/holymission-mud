inherit "room/room";
object ob;

void reset (int arg) 
{
  if (objectp(ob))
  {
      ob = clone_object ("players/muzmuz/island/monsters/sandworm");
      move_object (ob,this_object());
  }
  if (!arg) 
  {
    short_desc = "dunes";
    long_desc = "You are in the northeastern part of the dunes. It is less hot than in the\n" +
                 "center of them, but it is still too warm to feel well.\n";

      dest_dir = ({"players/muzmuz/island/rooms/gb","north",
                   "players/muzmuz/island/rooms/gd","south",
                   "players/muzmuz/island/rooms/fc","west",
                   "players/muzmuz/island/rooms/hc","east",
                            });

       items = ({"dunes","Huge dunes, covered with sand",
                 "sand","Hot white sand",
                       });
       set_light (1);
       }
}
