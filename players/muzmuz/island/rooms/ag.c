inherit "room/room" ;

void reset (int arg) 
{
  if (!arg) 
  {

        short_desc = "West coast";
        long_desc ="You are running along the west coast of the island. You wonder why you\n" +
                   "do not even see any seagulls or crabs. It is very peaceful here.....maybe\n" +
                   "too peaceful ? As you think of that you remember the name of this island.\n";
              
               items =({"sand","White sand. It is a little wet",
                        "ocean","The blue ocean seems to contain no life"});

              dest_dir = ({"players/muzmuz/island/rooms/af","north",
                         "players/muzmuz/island/rooms/ah","south",
                         "players/muzmuz/island/rooms/bg","east",
                      });

      set_light (1);

      }
  }
