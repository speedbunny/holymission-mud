inherit "players/cashimor/inherit/ice";

object kristi;

reset(arg)
{
 ::reset(arg);
 if (!kristi)
 {
  kristi = clone_object("players/cashimor/monsters/kristi");
  move_object(kristi,this_object());
 }
 if (!arg)
 {
  set_light(1);
  short_desc="Skating rink";
  long_desc="You are at the southeast part of a skating rink.\n";
  items=( { "ice","The ice looks well used here.\n" } );
  dest_dir=( { "players/cashimor/rooms/westrink","west",
               "players/cashimor/rooms/eastedge","north" } );
 } 
}
