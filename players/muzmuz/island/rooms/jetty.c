inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

     short_desc = "jetty";
      long_desc = "You are standing on the jetty. At this place boats from the ezo island\n" +
                  "anchore. Wind from the ocean blows into your face.\n";

      dest_dir = ({"players/muzmuz/island/rooms/kh","west",
                                });

        items = ({"ocean","The blue ocean",
                  "island","The Island of Death",
                        });
       set_light (1);
       }
}
