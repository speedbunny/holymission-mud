inherit "/players/texas/forest/gen_forest";

void reset(int arg)
{

::reset();
   short_desc = "A small forest";
   long_desc="/players/texas/forest/descriptions_file.c"->query_forest_desc();

   dest_dir = ({

      "/players/texas/forest/rooms/entry", "north",
      "/players/texas/forest/rooms/s2", "south",
      "/players/texas/forest/rooms/s1e1", "east",
      "/players/texas/forest/rooms/s1e3", "west",

   });

   property = ({});

}
