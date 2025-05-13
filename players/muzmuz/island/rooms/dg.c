inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

   short_desc = "dune";
    long_desc = "This is the southern end of the dunes. It is not as hot as inside the dunes,\n" +
                "but it is still hot here.\n";

     items = ({"dunes","Huge dunes, covered with sand",
               "sand","Hot white sand"});
    dest_dir = ({"players/muzmuz/island/rooms/df","north",
                 "players/muzmuz/island/rooms/cg","west",
                 "players/muzmuz/island/rooms/eg","east",
                   });
    set_light(1); 
   }
}
