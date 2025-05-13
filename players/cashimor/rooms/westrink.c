inherit "players/cashimor/inherit/ice";

reset(arg)
{
 ::reset(arg);
 if (!arg)
 {
  set_light(1);
  short_desc="Skating rink";
  long_desc= 
    "You are at the southwest part of a skating rink.\n"
  + "The skating goes very well, but you feel a little lonely.\n";
  items=( { "ice","The ice looks very good.\n" } );
  dest_dir=( { "players/cashimor/rooms/northedge","north",
               "players/cashimor/rooms/eastrink","east",
               "players/cashimor/rooms/edge","south" } );
 } 
}
