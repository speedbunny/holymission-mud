inherit "room/room";
object ob;

void reset(int arg) 
{
  if (!objectp(ob))
  {
      ob = clone_object ("players/muzmuz/island/monsters/sandworm");
      move_object (ob,this_object());
  }
  if(!arg) 
  {

     short_desc = "dunes";
      long_desc = "You are in the dunes. This is the hottest place you have ever been to. The\n" +
                  "sand seems to be glowing and your feet ache.\n";

     dest_dir =({"players/muzmuz/island/rooms/fd","north",
                 "players/muzmuz/island/rooms/ff","south",
                 "players/muzmuz/island/rooms/ee","west",
                 "players/muzmuz/island/rooms/ge","east",
                     });

       items = ({"dunes","Huge dunes, covered with sand",
                 "sand","Hot white sand",
                      });
      set_light (1);
      }
}
