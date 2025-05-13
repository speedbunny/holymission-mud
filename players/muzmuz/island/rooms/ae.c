inherit "room/room";

void reset(int arg) 
{
   if(!arg) 
   { 
      short_desc = "West coast";
      long_desc = 
      "You are standing at the west coast of the Island of Death. The sea is quite\n" +
      "still and there is a slight wind blowing into your face. This corner of the\n" +
      "island seems to be so peaceful that you think it does not deserve its current\n" +
      "name. The sand is warm and you think of getting out of your shoes.\n";

         items = ({"sand","Hot white sand",
                   "ocean","The blue ocean is quiet",
                   "sea","The quiet ocean bares any life" });

           dest_dir = ({
                        "players/muzmuz/island/rooms/af","south",
                        "players/muzmuz/island/rooms/bd","northeast",
                        "players/muzmuz/island/rooms/be","east",

                     });

       set_light (1) ;

    }
  }
