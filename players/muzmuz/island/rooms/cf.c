inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {
      short_desc = "dune";
       long_desc = "You are among huge dunes, you cannot see a major direction to get out\n" +
                   "of here. The sand is very hot here.\n";

      items =({"dunes","Huge dunes, covered with sand",
               "sand","Hot white sand"});
         dest_dir = ({"players/muzmuz/island/rooms/ce","north",
                      "players/muzmuz/island/rooms/bf","west",
                      "players/muzmuz/island/rooms/df","east",
                      "players/muzmuz/island/rooms/cg","south",

                    });

       set_light (1);
      }
}
