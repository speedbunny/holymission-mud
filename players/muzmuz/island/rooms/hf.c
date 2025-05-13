inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {
     short_desc = "dunes";
     long_desc = "This is the southeastern part of the dunes. The sand and the air are hot and\n" +
                  "dry. You guess when the last rain has fallen here.\n";

       dest_dir = ({"players/muzmuz/island/rooms/he","north",
                    "players/muzmuz/island/rooms/hg","south",
                    "players/muzmuz/island/rooms/gf","west",
                    "players/muzmuz/island/rooms/if","east",
                                });

         items = ({"dunes","Huge dunes, covered with sand",
                   "sand","Hot white sand",
                            });
         set_light (1);
         }
}
