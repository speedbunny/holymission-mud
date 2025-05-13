inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  { 

    short_desc = "west coast";
     long_desc = "This is the edge of the bay. You can see the ocean to the west and the bay\n"+
                 "to the north. You feel a gentle breeze blowing into your face. \n";

          items = ({"ocean","A blue ocean without any life",
                    "bay","A beautiful quiet bay"});

     dest_dir = ({"players/muzmuz/island/rooms/bk","east",
                  "players/muzmuz/island/rooms/al","south",

                     });
     set_light (1); 
    }
}
