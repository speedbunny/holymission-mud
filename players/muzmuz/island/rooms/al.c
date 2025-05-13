inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  { 

     short_desc = "west coast";
      long_desc = "You are standing at the west coast of the island. The wind is warm but\n"+
                  "refreshing. To the east you can see boggy land.\n";

        items =({"land","A boggy land",
                 "ocean","The ocean seems to contain life"});
     dest_dir = ({"players/muzmuz/island/rooms/ak","north",
                  "players/muzmuz/island/rooms/bl","east",
                  "players/muzmuz/island/rooms/bm","southeast",

                       });
     set_light (1); 
    }
}
