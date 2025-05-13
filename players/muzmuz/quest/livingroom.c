inherit "room/room";

void reset(int arg)
{
   if(!arg)
   {

      short_desc = "Livingroom";
       long_desc = "This is the livingroom. It looks well furnished and it was warm here.\n" +
                   "There are some chairs and a table and you would like to stay for awhile.\n" +
                   "The hall is to the west, the kitchen to the east.\n";

         items =({"chair","Soft chairs which seem to be too valuable to sit down",
                  "chairs","Soft chairs which seem to be too valuable to sit down",                  "table","A wooden table with a few scratches on it",
                               });

         dest_dir =({"players/muzmuz/quest/hall","west",
                     "players/muzmuz/quest/kitchen","east",
                              });

          set_light (1);
}
}

