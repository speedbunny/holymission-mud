inherit "players/cashimor/inherit/ice";
object skates;

reset(arg)
{
 ::reset(arg);
 if (!(present("skates",this_object())))
 {
  skates = clone_object("players/cashimor/objects/skates");
  move_object(skates,this_object());
 }
 if (!arg)
 {
  set_light(1);
  short_desc="Skating rink";
  long_desc= "You are at the edge of a skating rink.\n";
  items=( { "ice","The ice looks good.\n" } );
  dest_dir=( { "players/cashimor/rooms/westrink","north" } );
 } 
}
