inherit "room/room" ;

void reset(int arg) 
{
  if(!arg) 
  {

               short_desc = "Dune";
                long_desc = "You are inside the dunes. Sand is about anywhere. You are getting tired while\n" +
                            "walking through the dunes. Maybe you should walk more slowly.\n"; 
      items = ({"sand","Lots of hot white sand",
                "dunes","Huge dunes, covered with sand"});

                 dest_dir = ({"players/muzmuz/island/rooms/bd","north",
                              "players/muzmuz/island/rooms/ae","west",
                              "players/muzmuz/island/rooms/bf","south",
                             "players/muzmuz/island/rooms/ce","east",
                           });

      set_light (1);
     }
}
