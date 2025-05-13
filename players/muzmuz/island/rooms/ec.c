inherit "room/room";
object ob ;

void reset(int arg) 
{
  if (!objectp(ob))
  {
    ob = clone_object ("players/muzmuz/island/monsters/sandworm");
          move_object (ob,this_object());
  }
  if(!arg) 
  {
    short_desc = "little valley";
     long_desc = "You are standing in a little valley. North and south from here are little\n" +
                 "hills. You wonder if anyone had been here before.\n";

   items = ({"hills","Little hills all around you"});
     dest_dir =({"players/muzmuz/island/rooms/eb","north",
                 "players/muzmuz/island/rooms/ed","south",
                 "players/muzmuz/island/rooms/dc","west",
                 "players/muzmuz/island/rooms/fc","east",
                     });
    set_light (1);
    }
}
