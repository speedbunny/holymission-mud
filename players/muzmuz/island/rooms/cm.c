inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

   short_desc = "edge swamps";
    long_desc = "You are standing between the swamps and the west coast.\n" +
                "The swamps do not look very inviting, but maybe there are some things\n" +
                "worth looking for.\n";

       items = ({"coast","The wast coast",
                 "swamps","Huge swamps with mosquitos"});
    dest_dir = ({"players/muzmuz/island/rooms/cl","north",
                 "players/muzmuz/island/rooms/bm","west",
                 "players/muzmuz/island/rooms/cn","south",
                 "players/muzmuz/island/rooms/dm","east",
                  });
    set_light (1); 
    }
}
