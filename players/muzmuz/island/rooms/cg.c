inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {
    short_desc = "dune";
     long_desc = "This is the southern end of the dunes. Farther to the south there is the\n" +
                 "bay. It is quite hot here.\n";

          items =({"bay","A little quiet bay"
                   "ocean","The quiet ocean seems to be lifeless"});
          dest_dir = ({"players/muzmuz/island/rooms/cf","north",
                       "players/muzmuz/island/rooms/bg","west",
                       "players/muzmuz/island/rooms/ch","south",
                       "players/muzmuz/island/rooms/dg","east",

                         });
          set_light (1);
         }
}
