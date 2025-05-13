inherit "room/room";
object ob;

void reset (int arg) 
{
  if (!objectp(ob))
  {
      ob = clone_object ("players/muzmuz/island/monsters/sandworm");
      move_object (ob,this_object());
  }
  if (!arg) 
  {
     short_desc = "dunes";
     long_desc = "You are in the dunes. It is very hot and nodry here. You think you should not\n" +
                  "stay here too long. Probably in the valley to the west it will be better.\n";

      dest_dir = ({"players/muzmuz/island/rooms/fb","north",
                   "players/muzmuz/island/rooms/fd","south",
                   "players/muzmuz/island/rooms/ec","west",
                   "players/muzmuz/island/rooms/gc","east",
                     });
    
          items =({"dunes","Huge dunes, covered with sand",
                   "sand","Hot white sand",
                       });
       set_light (1);
      }
}
