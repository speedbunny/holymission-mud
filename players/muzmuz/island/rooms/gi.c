inherit "room/room"; 
object ob;

void reset (int arg) 
{
/*
  if (!objectp(ob))
  {
     ob = clone_object ("/players/muzmuz/island/monsters/spider");
     move_object (ob,this_object());
  }
*/
  if (!arg) 
  {

           short_desc = "path";
            long_desc = "Along the path. You are walking in the shadow of the hills. You can go \n" +
                        "east and west. The hills are too steep to climb up.\n";
          
          dest_dir = ({"players/muzmuz/island/rooms/fi","west",
                       "players/muzmuz/island/rooms/hi","east",
                             });

          items = ({"path","A stony path",
                    "hills","Little hills, but too steep to climb up",
                       });
         set_light (1);
         }
}
