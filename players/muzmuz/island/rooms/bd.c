inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  { 

              short_desc = "Northwest coast" ;
               long_desc = "The northwestern part of the Island. The sand is warm here and you know\n" +
                          "that shortly here had been life. But you cannot see anything living here.\n" +
                          "You wonder about the reasons of this loneliness here.\n";

        items = ({"sand","Warm white sand" ,
                  "ocean","The ocean does not seem to contain life"});

               dest_dir = ({"players/muzmuz/island/rooms/ae","southwest",
                            "players/muzmuz/island/rooms/be","south",
                            "players/muzmuz/island/rooms/cc","northeast",
                            "players/muzmuz/island/rooms/cd","east",
                      });

       set_light (1);

     }
}
