inherit "room/room";

void reset(int arg) 
{
  if (!arg)
  {
      short_desc = "dunes";
      long_desc = "Inside the dunes. The warm sand covers your feet. The air is hot and dry.\n";

   items = ({"dunes","Huge dunes, covered with sand",
             "sand","Hot white sand"});
   dest_dir =({"players/muzmuz/island/rooms/ee","north",
               "players/muzmuz/island/rooms/eg","south",
               "players/muzmuz/island/rooms/df","west",
               "players/muzmuz/island/rooms/ff","east",
                                  });
    set_light (1);
    }
}
