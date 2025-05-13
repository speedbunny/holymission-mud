inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

     short_desc = "west coast";
      long_desc = "This is the west coast. To the west there is nothing than water, to\n" +
                  "the east are the swamps.\n";

       items = ({"water","The blue ocean",
                 "ocean","The ocean is quiet , without any wave",
                  "swamps","Huge swamps with mosquitos"});
      dest_dir =({"players/muzmuz/island/rooms/cm","north",
                  "players/muzmuz/island/rooms/bm","northwest",
                  "players/muzmuz/island/rooms/dn","east",
                  "players/muzmuz/island/rooms/co","south",
                     });
      set_light (1); 
      }
}
