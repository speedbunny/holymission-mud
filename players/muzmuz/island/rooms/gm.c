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
      long_desc ="Inside the swamps. The air is so warm and moist that you sweat alot. You \n" +
                 "don`t know what you should do first--either fight the mosquitos or leave this\n" +
                 "place as fast as possible.\n";

      dest_dir =({"players/muzmuz/island/rooms/gl","north",
                  "players/muzmuz/island/rooms/gn","south",
                  "players/muzmuz/island/rooms/fm","west",
                  "players/muzmuz/island/rooms/hm","east",
                           });

        items =({"swamps","Huge moist swamps",
                 "mosquitos","Many mosquitos buzz around your head",
                      });
        set_light (1);
       }
}
