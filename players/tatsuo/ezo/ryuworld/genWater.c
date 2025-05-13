inherit "room/room";

string hole;

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   short_desc = "Flee fool !!!";

   long_desc = 
        "You are diving in an underwater-cave. The walls around you are\n" +
        "of lava. Some weeds have grown at the walls and small fishes\n" +
        "swimming around here.\n";

   items = ({ "walls", "They are pitch black and weeds grow at them",
              "wall", "It is pitch black and weeds grow on it",
              "lava", "It is pitch black",
              "weed", "Weed, nothing else",
              "weeds", "Weeds, nothing else",
              "fishes", "Small fishes in different colors",
              "fish", "This is a small green one",
           });
}

init()
{
   ::init();
}

query_water()
{
   return( 1 );
}

move(str) {
    int i;
    string *dirs;

    if (!str) str=query_verb();
    dirs=dest_dir;
    if(hidden_dir) { if(dirs) dirs+=hidden_dir; else dirs=hidden_dir; }

    if ((i = member_array(str, dirs)) != -1) {
      if ( present( "kojin", this_object() ) && i != 1 ) {
         write( "The kojin hinders you to leave " + dirs[i] + ".\n" );
         return( 1 );
      }
      if (dirs[i-1]=="") return 0;
      this_player()->move_player(dirs[i] + "#" + dirs[i-1]);
      return 1;
    }
}
