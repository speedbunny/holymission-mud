inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

          short_desc = "dune";
           long_desc = "You are in the northern part of the dunes. You can hear the sea to the\n" +
                       "northwest and you can also smell it a bit.\n";

      items = ({"dunes","Huge dunes, covered with sand",
                "sand","Hot white sand"});
            dest_dir = ({"players/muzmuz/island/rooms/cc","north",
                         "players/muzmuz/island/rooms/bd","west",
                         "players/muzmuz/island/rooms/ce","south",
                         "players/muzmuz/island/rooms/dd","east",
                          });
       set_light (1);
       }
}
