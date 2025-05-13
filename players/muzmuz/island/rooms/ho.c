inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "swamps";
       long_desc = "You have reached the eastern end of the swamps. South from here you can climb\n" +
                   "the little hill. To the east is the coast. You feel a slight breeze blowing\n" +
                   "from there.\n";

     dest_dir = ({"players/muzmuz/island/rooms/hn","north",
                  "players/muzmuz/island/rooms/hp","south",
                  "players/muzmuz/island/rooms/go","west",
                  "players/muzmuz/island/rooms/io","east",
                          });
       items =({"swamps","Huge moist swamps",
                "coast","The east coast",
                "hill","A little hill southeast from here",
                      });
        set_light (1);
        }
}
