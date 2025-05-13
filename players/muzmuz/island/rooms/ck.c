inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "south bay";
     long_desc = "You are standing south of the bay. To the south there are the swamps.\n" +
                 "You can see a little hill to the east.\n";

      items = ({"hill","A little hill",
                "bay","A nice looking little bay",
                "ocean","The quiet ocean seems to be lifeless",
                "swamps","Huge swamps with mosquitos"});
     dest_dir =({"players/muzmuz/island/rooms/bk","west",
                 "players/muzmuz/island/rooms/dk","east",
                 "players/muzmuz/island/rooms/cl","south",
                       });
      set_light (1); 
     }
}
