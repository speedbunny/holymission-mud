inherit "room/room";

void reset(int arg)
{
  if(!arg)
  {

    short_desc = "Hall";
     long_desc = 
     "You are in the forehall of the house. You can see stairs which lead \n" +
     "upwards. To the west there is the bathroom, to the east the livingroom.\n" +
     "The hall continues to the north, and you can also see a door leading out.\n";

         items =({"stairs","They lead upwards",
                  "door","It is open",
                           });

       dest_dir = ({"players/muzmuz/quest/connect","out",
                    "players/muzmuz/quest/livingroom","east",
                    "players/muzmuz/quest/bathroom","west",
                    "players/muzmuz/quest/hall2","north",
                    "players/muzmuz/quest/uphall","upstairs",
                                  });
     hidden_dir =({"/players/muzmuz/quest/uphall","up",
                         });

         set_light (1);
}
}

