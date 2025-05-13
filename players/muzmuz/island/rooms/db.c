inherit "room/room";

void reset(int arg) 
{
     if(!arg) 
     {

    short_desc = "west coast";
     long_desc = "You are in the far northern part of the west coast. To the north you can see\n" +
                 "the edge of the west coast. The warm wind blows nicely into your face.\n";

     items = ({"coast","The west coast",
               "ocean","The ocean to the west is very quiet"}); 
     dest_dir = ({"players/muzmuz/island/rooms/da","north",
                  "players/muzmuz/island/rooms/cc","southwest",
                  "players/muzmuz/island/rooms/dc","south",
                  "players/muzmuz/island/rooms/eb","east",

                    });

     set_light (1); 
     }
}

