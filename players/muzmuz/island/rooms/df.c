inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

     short_desc = "dune";
      long_desc = "You are inside the dunes. You cannot see anything else than huge sand dunes.\n" +
                  "You are afraid of getting lost here because every direction looks like any\n" +
                  "other. But for god`s sake the sun is shining and you can orientate yourself\n" +
                  "a bit. \n";      

      items = ({"dunes","Huge dunes, covered with sand",
                "sand","Hot white sand",
                "sun","It blinds you for a moment"});
       dest_dir = ({"players/muzmuz/island/rooms/de","north",
                    "players/muzmuz/island/rooms/dg","south",
                    "players/muzmuz/island/rooms/cf","west",
                    "players/muzmuz/island/rooms/ef","east",
                        });
      set_light (1); 
      }
}
