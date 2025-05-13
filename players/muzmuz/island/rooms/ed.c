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
   short_desc = "hill";  
   long_desc = "This is the top of a little hill. To the north is a little valley, to the \n" +
                "south and to the west you can see the dunes.\n";

    items = ({"valley","A little valley",
              "dunes","Huge dunes, covered with sand"});
    dest_dir =({"players/muzmuz/island/rooms/ec","north",
                "players/muzmuz/island/rooms/ee","south",
                "players/muzmuz/island/rooms/dd","west",
                "players/muzmuz/island/rooms/fd","east",

                  });
     set_light (1);
     }
}
