inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "swamps";
     long_desc = "You are in the swamps. The air is very warm and very moisty and you sweat\n" +
                 "a lot. Mosquitos are buzzing around anywhere.\n";

      items =({"mosquitos","They seem to be anywhere"});
     dest_dir =({"players/muzmuz/island/rooms/dl","north",
                 "players/muzmuz/island/rooms/dn","south",
                 "players/muzmuz/island/rooms/cm","west",
                 "players/muzmuz/island/rooms/em","east",
                      });
     set_light (1); 
     }
}
