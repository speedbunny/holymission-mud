inherit "room/room";

void reset(int arg) 
{
    if(!arg)  
    {

     short_desc = "dunes";
      long_desc = "In the dunes. The air is so hot and dry that it makes you feel unwanted here.\n" +
                  "Probably you should really leave this place.\n";

      dest_dir = ({"players/muzmuz/island/rooms/fe","north",
                   "players/muzmuz/island/rooms/fg","south",
                   "players/muzmuz/island/rooms/gf","east",
                   "players/muzmuz/island/rooms/ef","west",
                        });
        items = ({"dunes","Huge dunes, covvered with sand",
                  "sand","Hot white sand",
                        });
        set_light (1);
       }
}
