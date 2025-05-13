inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

     short_desc = "hill";
      long_desc = "You are standing on a small hill. You see coasts to the north and to the west.\n" +
                  "South from here is a little valley, behind that is another hill.\n";
      items = ({"coast","The west coast and the north coast",
                "ocean","The blue ocean seems like a portrait",
                "valley","A little valley among hills",
                "hill","Little hills covered with sand"});
     dest_dir = ({"players/muzmuz/island/rooms/ea","north",
                  "players/muzmuz/island/rooms/ec","south",
                  "players/muzmuz/island/rooms/db","west",
                  "players/muzmuz/island/rooms/fb","east",
                     });
     set_light (1);
     }
}
