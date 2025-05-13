
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
       long_desc = "In the northeastern part of the dunes. The coast is near and you feel \n" +
                   "it is not that hot. If you want to go deeper into the dunes, be aware that\n" +
                   "it is very hot there !\n";

         dest_dir = ({"players/muzmuz/island/rooms/gc","north",
                      "players/muzmuz/island/rooms/ge","south",
                      "players/muzmuz/island/rooms/fd","west",
                      "players/muzmuz/island/rooms/hd","east",
                             });

          items = ({"dunes","Huge dunes, covered with sand",
                    "sand","Hot white sand",
                       });
        set_light (1);
        }
}
