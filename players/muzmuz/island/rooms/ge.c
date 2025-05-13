inherit "room/room";
object ob;

void reset (int arg) 
{
  if (!objectp(ob))
  {
      ob = clone_object ("players/muzmuz/island/monsters/sandworm");
      move_object (ob,this_object());
  }
  if (!arg) 
  {
      short_desc = "dunes";
       long_desc = "In the eastern part of the dunes. The air is quite hot, so don`t stay here too\n" +
                   "too long, it might be dangerous for you.\n";

        dest_dir = ({"players/muzmuz/island/rooms/gd","north",
                     "players/muzmuz/island/rooms/gf","south",
                     "players/muzmuz/island/rooms/fe","west",
                     "players/muzmuz/island/rooms/he","east",
                         });

         items = ({"dunes","Huge dunes, covered with sand",
                   "sand","Hot white sand",
                        });

        set_light (1);
        }
}
