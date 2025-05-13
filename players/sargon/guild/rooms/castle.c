
inherit "room/room";

#include "/players/sargon/guild/rooms/castle.pic"

reset(arg) {
  if(!arg) {
    set_light(1);

    short_desc="Entrance to the Fighter's Guild";
    
    long_desc= BS( "You are standing at the entrance of the great " +
		   "Fighters guild! \n" );

    dest_dir=({"/room/eastroad5","east",
               "/players/sargon/guild/rooms/room","enter"});

    smell="It smells as if there were great battles fought nearby";
  }
}
