inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

      short_desc = "swamps";
       long_desc = "You are walking along the southern edge of the swamps. The ground here is \n" +
                   "more solid and it is easier to go here than inside them.\n";

          dest_dir =({"players/muzmuz/island/rooms/fo","north",
                      "players/muzmuz/island/rooms/fq","south",
                      "players/muzmuz/island/rooms/ep","west",
                      "players/muzmuz/island/rooms/gp","east",
                            });
          items =({"swamps","Huge moist swamps"
                   "ground","The ground is solid enough to walk on it",
                         });
          set_light (1);
          }
}
