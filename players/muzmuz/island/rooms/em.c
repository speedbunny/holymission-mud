inherit "room/room";
object ob ;

void reset (int arg) 
{
   if (!objectp(ob))
   {
       ob = clone_object ("/players/muzmuz/island/monsters/mudmonster");
            move_object (ob,this_object());
   }
  if (!arg) 
  {
      short_desc = "swamps";
       long_desc = "You are deep inside the swamps. It is hot and moist here. Mosquitos start to\n" +
                   "become annoying. \n";

       dest_dir =({"players/muzmuz/island/rooms/el","north",
                   "players/muzmuz/island/rooms/en","south",
                   "players/muzmuz/island/rooms/dm","west",
                   "players/muzmuz/island/rooms/fm","east",
                           });

         items =({"swamps","Huge moist swamps",
                  "mosquitos","They are buzzing around everywhere",
                         });
        set_light (1);
      }
}
