inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

      short_desc = "dunes";
       long_desc = "This is the southeastern edge of the dunes. It is not really hot, but still\n" +
                   "uncomfortably warm. South from you there is the path leading through the\n" +
                   "island. East from here there is a little hill.\n";

         dest_dir = ({"players/muzmuz/island/rooms/if","north",
                      "players/muzmuz/island/rooms/ih","south",
                      "players/muzmuz/island/rooms/hg","west",
                      "players/muzmuz/island/rooms/jg","east",
                               });

          items = ({"dunes","Huge dunes, covered with sand",
                    "sand","Warm white sand",
                    "hill","A little hill",
                    "path","A stony path",
                           });
           set_light (1);
           }
}
