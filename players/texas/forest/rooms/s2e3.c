inherit "/players/texas/forest/gen_forest";

void reset(int arg)
{

::reset();
   short_desc = "A small forest";
   long_desc="/players/texas/forest/descriptions_file.c"->query_forest_desc();

   dest_dir = ({

      "/players/texas/forest/rooms/s1e3", "north",
      "/players/texas/forest/rooms/n2e2", "south",
      "/players/texas/forest/rooms/s2", "east",
      "/players/texas/forest/rooms/s2e2", "west",

   });

   property = ({});

}
