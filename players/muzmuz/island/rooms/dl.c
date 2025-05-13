inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "swamps";
     long_desc = "This is the edge of the swamps. To the north is a little hill.\n" +
                 "The swamps are to the south and to the east.\n";
      items = ({"hill","A little hill",
                "swamps","Huge swamps with mosquitos"});
     dest_dir =({"players/muzmuz/island/rooms/dk","north",
                 "players/muzmuz/island/rooms/dm","south",
                 "players/muzmuz/island/rooms/cl","west",
                 "players/muzmuz/island/rooms/el","east",
              });
      set_light (1); 
      }
}
