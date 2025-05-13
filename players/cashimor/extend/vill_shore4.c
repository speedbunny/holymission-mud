inherit "room/room";

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="Village shore";
    long_desc="The village shore. A jetty leads out to the east. To the south "
            + "there is a small house.\n";
    dest_dir=({"room/vill_shore3","west",
               "room/jetty2","east",
               "players/cashimor/extend/hall","south"});
    items=({"jetty","It's rather long",
            "house","It looks solid and beautiful, and has an entrance hall"});
    smell="You can smell the sea nearby.";  
  }
}
