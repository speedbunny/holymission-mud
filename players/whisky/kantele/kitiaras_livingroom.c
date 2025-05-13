
inherit "/room/room";
#include "defs.h"


void reset(int flag)
{
    if (!present("kitiara",this_object())) 
      CM("kitiara");
    if (flag == 0)
    {
       dest_dir =
       ({
         PATH+"kitiaras_innerhall","north",
         PATH+"kitiaras_smallroom","east",
         PATH+"kitiaras_strangeroom","west",
        });

         short_desc = "In a livingroom";
         long_desc = BS(
           "In Kitiaras livingroom, this is a comfortable room where it " +
           "should be possible to relax. the room is dimly lighted from a " +
           "hole in the ceiling.");
         items = 
         ({
           "bottom","The bottom is made of fouly wood",
           "ceiling","The ceiling is made of red bricks",
           "walls","The walls are made of red bricks",
           "hole","You see some light coming from",
          });
      }
}


