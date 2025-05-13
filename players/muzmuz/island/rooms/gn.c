inherit "room/room";
object ob ;

void reset (int arg) 
{
  if (!objectp(ob))
  {
      ob = clone_object ("players/muzmuz/island/monsters/mudmonster");
      move_object (ob,this_object());
  }
  if (!arg) 
  {
      short_desc = "swamps";
       long_desc = "The swamps seem to be never ending. All you can see is wet mud and many\n" +
                   "mosquitos. The air is quit warm and moist.\n";

         dest_dir =({"players/muzmuz/island/rooms/gm","north",
                     "players/muzmuz/island/rooms/go","south",
                     "players/muzmuz/island/rooms/fn","west",
                     "players/muzmuz/island/rooms/hn","east",
                            });
         items = ({"swamps","Huge moist swamps",
                   "mud","Warm wet mud",
                   "mosquitos","Many mosquitos buzzing around you",
                          });
         set_light (1);
         }
}
