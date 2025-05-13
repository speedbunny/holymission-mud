inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

      short_desc = "swamps";
      long_desc = "This is the east edge of the swamps. The ocean is not very far away and\n" +
                   "you feel that the temperature is not that high. It is still very moist.\n";

        dest_dir =({"players/muzmuz/island/rooms/hm","north",
                    "players/muzmuz/island/rooms/ho","south",
                    "players/muzmuz/island/rooms/gn","west",
                    "players/muzmuz/island/rooms/in","east",
                                 });
        items =({"swamps","Huge moist swamps",
                  });
        set_light (1);
       }
}
