inherit "/room/room";

int no_rand;                  // no random teleport to this room

int query_shadowplane()
{
   return( 1 );
}

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   items = ({ "shadow", "Dark gray and black, nothing really exciting",
              "shadows", "Dark gray and black, nothing really exciting",
           });
}

int no_random( )             { return( no_rand ); }
void set_no_random( )        { no_rand = 1; }
