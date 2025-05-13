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
        long_desc = "You are in the southern part of the swamps. It is quite uncomfortable here\n" +
                    "and you better don`t stay here too long.\n";

       dest_dir =({"players/muzmuz/island/rooms/en","north",
                   "players/muzmuz/island/rooms/ep","south",
                   "players/muzmuz/island/rooms/do","west",
                   "players/muzmuz/island/rooms/fo","east",
                          });
           items =({"swamps","Huge moist swamps",
                    "mud","Warm wet mud",
                               });
       set_light (1);
       }
}
