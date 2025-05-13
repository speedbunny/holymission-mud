inherit "room/room";

void reset (int arg) 
{
   if (!arg) 
   {
      short_desc = "dunes";
      long_desc = "This is the northeastern end of the dunes. It gets hot here and you think\n" +
                   "you better go to the coast in northern or eastern direction. The dunes to the\n" +
                   "south and to the west are hot and uncomfortable.\n";

        dest_dir = ({"players/muzmuz/island/rooms/ga","north",
                     "players/muzmuz/island/rooms/gc","south",
                     "players/muzmuz/island/rooms/fb","west",
                     "players/muzmuz/island/rooms/hb","east",
                            });

         items = ({"dunes","Huge dunes, covered with sand",
                    "sand","Hot white sand",
                                 });
        set_light (1);
        }
}
