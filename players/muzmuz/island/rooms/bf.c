inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

       short_desc ="dune";
        long_desc ="Inside the dunes. White sand is all around here. You can see the ocean far\n" +
                   "to the west. To the east you can only see dunes.\n";

        items = ({"sand","Hot white sand"});
            dest_dir = ({"players/muzmuz/island/rooms/be","north",
                         "players/muzmuz/island/rooms/af","west",
                         "players/muzmuz/island/rooms/bg","south",
                         "players/muzmuz/island/rooms/cf","east",
                 });

       set_light (1);

    }
}
