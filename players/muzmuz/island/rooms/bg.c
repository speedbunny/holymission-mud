inherit "room/room";

void reset(int arg) 
{
 if(!arg) 
 {

      short_desc ="dune";
       long_desc ="In the dunes. You hear the sea rolling in the west, but you cannot see\n" +
                  "it yet. To the east you see huge dunes.\n";

     items = ({"dune","A huge dune",
               "sand","Hot white sand" });
        dest_dir = ({"players/muzmuz/island/rooms/bf","north",
                    "players/muzmuz/island/rooms/ag","west",
                    "players/muzmuz/island/rooms/bh","south",
                    "players/muzmuz/island/rooms/cg","east",
                   });
    set_light (1);
   }
}
