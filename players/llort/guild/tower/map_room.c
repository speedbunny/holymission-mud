inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc="Mapping room";
    long_desc=
"This is the library of the mage-tower. You can see lots of shelves all over\n"+
"the room. Most of the books, papers and scrolls here seem very unintresting.\n";
    items=({ "shelf","Alot of dusty shelves",
             "shelves","Alot of dusty shelves",
             "books",
     "Old, almost rotten books, but one of the books is definitly strange",
             "papers","Absolutely unintresting old papers",
             "scrolls","The scrolls look like crumbling under your fingers"
          });
    dest_dir=({ "players/llort/guild/tower/hall2","west" });
}

init() {
    ::init();
    add_action("search","search");
    add_action("push","push");
}

search(a) {
    if(!id(a)) return;
    write("After taking a closer look you can't seen more than before.\n");
    return 1;
}

push(a)
{
   if(a == "book")
   {
      write("Suddenly you are teleported somewhere.\n");
      this_player()->move_player("desintegrates",
          "players/llort/guild/tower/library",1,"integrates");
      return 1;
   }
}
