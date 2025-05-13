inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

       short_desc = "Northwest coast";
        long_desc = "You are at the northwestern coast of the Island. There are some stones\n" +
                    "around, but those are the only things besides the sand and the sea here.\n";

       items =({"sea","A blue ocean without life",
                "stones","Black stones as big as a fist",
                "sand","Warm white sand"});
          dest_dir = ({"players/muzmuz/island/rooms/bd","southwest",
                       "players/muzmuz/island/rooms/cd","south",
                       "players/muzmuz/island/rooms/dc","east",
                       "players/muzmuz/island/rooms/db","northeast",

                      });

         set_light (1);
      }
  }
