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
       long_desc = "In the southeastern part of the huge swamps. There is a little hill near you.\n" +
                   "It is not that hot and you take a deep breath. \n";

     dest_dir =({"players/muzmuz/island/rooms/gn","north",
                 "players/muzmuz/island/rooms/gp","south",
                 "players/muzmuz/island/rooms/fo","west",
                 "players/muzmuz/island/rooms/ho","east",
                        });
      items = ({"swamps","Huge moist swamps",
                "hill","A little hill, southeast from here",
                  });
      set_light (1);
      }
}
