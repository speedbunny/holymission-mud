inherit "players/cashimor/inherit/ice";

reset(arg)
{
 ::reset(arg);
 if (!arg)
 {
  set_light(1);
  short_desc="Skating rink";
  long_desc= 
    "You are at the northwest part of a skating rink.\n"
  + "There is a hole in the ice...\n";
  items=( { "ice","The ice doesn't look very good.\n",
            "hole","A hole that makes it very difficult to skate here.\n" } );
  dest_dir=( { "players/cashimor/rooms/eastedge","east",
               "players/cashimor/rooms/westrink","south" } );
 } 
}
