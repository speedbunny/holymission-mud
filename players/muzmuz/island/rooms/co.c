inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

     short_desc = "west coast";
      long_desc = "This is the west coast near the swamps. They are to the east. To the west\n" +
                  "you only see the ocean.\n";

      items = ({"swamps","Huge swamps with mosquitos",
                    "ocean","The blue ocean"});
     dest_dir =({"players/muzmuz/island/rooms/cn","north",
                 "players/muzmuz/island/rooms/cp","south",
                 "players/muzmuz/island/rooms/do","east",
                     });
      set_light (1); 
      }
}
