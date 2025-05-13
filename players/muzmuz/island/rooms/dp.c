inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

   short_desc = "swamps";
    long_desc = "This is the southern edge of the swamps. Farther to the south you can see\n" +
                "the coast. Southwest from you there are some cliffs.\n";

     items = ({"cliffs","The cliffs of the west coast",
               "coast","The west coast"});
    dest_dir =({"players/muzmuz/island/rooms/do","north",
                "players/muzmuz/island/rooms/dq","south",
                "players/muzmuz/island/rooms/cp","west",
                "players/muzmuz/island/rooms/ep","east",
                   });
     set_light (1); 
     }
}
