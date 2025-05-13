inherit "room/room";

void reset(int arg)
{
   if(!arg)
   {

        short_desc = "Hall";
         long_desc = "This is the hall on the second floor. Stairs lead downwards. You can hear \n" +
                     "some noises coming from the east. There is a picture on the wall.\n";

           items =({"stairs","They lead downwards",
                    "picture","It shows an old lady",
                             });
   dest_dir=({
	"/players/muzmuz/quest/library.c","south",
	"/players/muzmuz/quest/childroom.c","east",
	"/players/muzmuz/quest/bedroom.c","west",
	"/players/muzmuz/quest/hall.c","down",
   });
                       "players/muzmuz/quest/library","south",
                       "players/muzmuz/quest/bedroom","west",
                       "players/muzmuz/quest/hall","downstairs",
                                });
        hidden_dir =({"/players/muzmuz/quest/hall","down",
                               });


           set_light (1);

}
}

