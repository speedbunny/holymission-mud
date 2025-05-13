inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

      short_desc = "north bay";
       long_desc = "You are standing at the northern side of the bay. The bay looks really nice\n" +
                   "and inviting from here. To the north there are the dunes.\n";

       items =({"dunes","Huge dunes, covered with sand",
                "ocean","The ocean is quiet and you are sure there is no life in it",
                "bay","A nice quiet bay"});
      dest_dir = ({"players/muzmuz/island/rooms/cg","north",
                   "players/muzmuz/island/rooms/bh","west",
                   "players/muzmuz/island/rooms/dh","east",

                      });

      set_light (1);
      }
}
