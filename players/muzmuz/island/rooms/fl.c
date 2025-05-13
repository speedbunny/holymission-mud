inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "swamps";
        long_desc = "The northern edge of the swamps. They lead further to the south, but they\n" +
                    "don`t look very inviting, so you better stay away from them.\n";

         dest_dir =({"players/muzmuz/island/rooms/el","west",
                     "players/muzmuz/island/rooms/gl","east",
                     "players/muzmuz/island/rooms/fm","south",
                                 });

          items =({"hills","Steep hills to the north",
                   "swamps","Huge swamps to the south",
                         });
         set_light (1);
        }
}
