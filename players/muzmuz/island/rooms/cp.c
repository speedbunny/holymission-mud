inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

      short_desc = "west coast";
       long_desc = "You are standing on cliffs and you see the ocean to the west. To the east\n" +
                   "you see the swamps.\n";
      items = ({"ocean","The blue ocean",
                "swamps","Huge swamps with mosquitos"});
      dest_dir =({"players/muzmuz/island/rooms/co","north",
                  "players/muzmuz/island/rooms/cq","south",
                  "players/muzmuz/island/rooms/dp","east",
                       });
      set_light (1); 
      }
}
