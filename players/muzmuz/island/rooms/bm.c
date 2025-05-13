inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

     short_desc = "coast";
      long_desc = "This is the west coast. It leads to the northwest and southeast.\n" +
                  "Farther to the east there are swamps.\n";

      items = ({"swamps","Huge swamps with mosquitos",
                "ocean","The ocean does not seem to contain any life"});
      dest_dir =({"players/muzmuz/island/rooms/bl","north",
                  "players/muzmuz/island/rooms/al","northwest",
                  "players/muzmuz/island/rooms/cm","east",
                  "players/muzmuz/island/rooms/cn","southeast",
                    });
      set_light (1); 
     }
}
