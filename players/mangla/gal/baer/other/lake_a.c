inherit "/domains/mountains/generics/room";
#include "/domains/mountains/zones/lowland_lake/rooms/room.h"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_short("Shallow Lake [n,ne]");
   set_long("You are now at the southern shore of the lake. "+
            "Native fisherman wander the lake, looking to spear fish, "+
            "rhythmically sending ripples across the lakes surface. "+
            "The pulsating water laps at your knees. The sun shines down "+
            "through the lake, highlighting the small fish that dart "+
            "across the sandy bottom.\n");

   add_exit( "north", 0, RPATH+"lake_d", "n", VISIBLE );
   add_exit( "northeast", 0, RPATH+"lake_e", "ne", VISIBLE );

   set_type( OUTDOOR );

   replace_program( "domains/mountains/generics/room" );
}
