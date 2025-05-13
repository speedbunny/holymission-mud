inherit "room/room";

void reset(int arg) 
{
     if(!arg) 
     {

    short_desc = "northwestern corner";
     long_desc = "This is the northwestern corner of the island. You can see the ocean to the\n" +
                 "north and the west. There is a gentle breeze blowing through your hair.\n";

       items = ({"ocean","The blue ocean",
                 "sand","Wet sand, it seems it has not been touched for ages"});
     dest_dir = ({"players/muzmuz/island/rooms/db","south",
                  "players/muzmuz/island/rooms/ea","east",

                    });

      set_light (1) ; 
      }
}
