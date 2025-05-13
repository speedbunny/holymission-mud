inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

     short_desc = "boggy land";
      long_desc = "This is the edge of the boggy land. The swamps are to the east and the bay\n" +
                  "is north. To the west and to the south there is the coast.\n";

        items = ({"swamps","Big swamps with mosquitos",
                   "bay","A little quiet bay",
                   "coast","Coasts to the west and south"});
      dest_dir = ({"players/muzmuz/island/rooms/bk","north",
                   "players/muzmuz/island/rooms/bm","south",
                   "players/muzmuz/island/rooms/al","west",
                   "players/muzmuz/island/rooms/cl","east",
                       });
      set_light (1); 
    }
}
