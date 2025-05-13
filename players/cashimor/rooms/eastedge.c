inherit "players/cashimor/inherit/ice";


reset(arg)
{
 ::reset(arg);
 if (!arg)
 {
  set_light(1);
  short_desc="Skating rink";
  long_desc="You are at the northeast part of a skating rink.\n";
  items=( { "ice","The ice looks well used here.\n" } );
  dest_dir=( { "players/cashimor/rooms/northedge","west",
                 "players/cashimor/rooms/eastrink","south" } );
 } 
}
