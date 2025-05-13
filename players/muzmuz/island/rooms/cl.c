inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "swamps";
     long_desc = "You are in the swamps. It is hot and very moisty here. You can see fern \n" +
                 "anywhere, you might lose orientation.\n";

      items = ({"mosquitos","Many mosquitos buzzing around you"});
       dest_dir =({"players/muzmuz/island/rooms/ck","north",
                   "players/muzmuz/island/rooms/bl","west",
                   "players/muzmuz/island/rooms/cm","south",
                   "players/muzmuz/island/rooms/dm","east",
                      });
      set_light (1); 
     }
}
