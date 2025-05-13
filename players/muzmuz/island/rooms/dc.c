inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "dune";
     long_desc = "You are standing at the northern end of the dunes. You can see the ocean far\n" +
                 "to the west. To the east there is a little valley. If you want to go to the\n" +
                 "dunes, take care , they are rather hot and dry !\n";

     items = ({"ocean","The blue ocean",
               "dunes","Huge dunes, covered with sand",
               "sand","hot white sand"});
      dest_dir = ({"players/muzmuz/island/rooms/db","north",
                   "players/muzmuz/island/rooms/dd","south",
                   "players/muzmuz/island/rooms/cc","west",
                   "players/muzmuz/island/rooms/ec","east",

                      });

      set_light (1); 
      }
}
