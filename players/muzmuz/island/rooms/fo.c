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
       long_desc = "The southern part of the swamps. A hot wind blows into your face. You sweat\n" +
                   "like never before. There are some mosquitos buzzing around.\n";

        dest_dir =({"players/muzmuz/island/rooms/fn","north",
                    "players/muzmuz/island/rooms/fp","south",
                    "players/muzmuz/island/rooms/eo","west",
                    "players/muzmuz/island/rooms/go","east",
                                  });
         items = ({"swamps","Huge moist swamps",
                   "mosquitos","They buzz around your head trying to stinger you",
                           });
         set_light (1);
         }
}
