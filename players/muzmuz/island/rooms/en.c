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
       long_desc = "Inside the swamps. You stand knee deep in the mud. It is very strenuous to \n" +
                   "walk. Besides that the mosquitos are out for your blood.\n";

       dest_dir =({"players/muzmuz/island/rooms/em","north",
                   "players/muzmuz/island/rooms/eo","south",
                   "players/muzmuz/island/rooms/dn","west",
                   "players/muzmuz/island/rooms/fn","east",
                          });

      items =({"swamps","Huge moist swamps",
               "mud","Wet mud, it makes it nearly impossible to walk",
               "mosquitos","They are buzzing around your head",
                         });
      set_light (1);
      }
}
