inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

   short_desc = "swamps";
    long_desc = "You are in the swamps. There are some cliffs to the west. The mosquitos here\n" +
                "are really annoying. You sweat a lot because it is hot and clammy.\n";

    items = ({"cliffs","The cliffs of the west coast",
              "mosquitos","They seem to be anywhere"});
     dest_dir =({"players/muzmuz/island/rooms/dn","north",
                 "players/muzmuz/island/rooms/dp","south",
                 "players/muzmuz/island/rooms/co","west",
                 "players/muzmuz/island/rooms/eo","east",
                     });
     set_light (1); 
     }
}
