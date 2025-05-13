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
     long_desc = "You are in the dunes. It is warm here, but the hill to the north spends a\n" +
                 "shadow and so it is not that hot.\n";
    
    items = ({"dunes","Huge dunes, covered with sand",
              "sand","Hot white sand"});
     dest_dir =({"players/muzmuz/island/rooms/ed","north",
                 "players/muzmuz/island/rooms/ef","south",
                 "players/muzmuz/island/rooms/de","west",
                 "players/muzmuz/island/rooms/fe","east",
                  });

      set_light (1);
     }
}
