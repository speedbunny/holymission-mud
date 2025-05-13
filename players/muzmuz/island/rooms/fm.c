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

      short_desc ="swamps";
      long_desc ="You are quite in the middle of the swamps. The air is so hot amd moist that\n" +
                  "you can hardly breath. The mosquitos here don`t make it any better.\n";

         dest_dir =({"players/muzmuz/island/rooms/fl","north",
                     "players/muzmuz/island/rooms/fn","south",
                     "players/muzmuz/island/rooms/em","west",
                     "players/muzmuz/island/rooms/gm","east",
                         });

       items =({"swamps","Huge moist swamps",
                "mosquitos","Many mosquitos, buzzing around everywhere",
                       });
        set_light (1);
        }
}
