inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

     short_desc = "south coast";
      long_desc = "You are standing at the south coast. To the north you can see swamps, to\n" +
                  "the south the ocean. There are cliffs in the west.\n";

    items = ({"swamps","Huge swamps with moquitos",
              "cliffs","The cliffs of the west coast",
              "ocean","The blue ocean"});
      dest_dir =({"players/muzmuz/island/rooms/dp","north",
                  "players/muzmuz/island/rooms/cq","west",
                  "players/muzmuz/island/rooms/eq","east",
                      });
    set_light (1); 
    }
}
