#define ANZ_MONST  (8)
#define PPATH      "/players/tatsuo/coastMonst/"
rnd_monster( )
{
   switch( random( ANZ_MONST ) ) {
      case 0:    return( PPATH + "crab" );
      case 1:    return( PPATH + "crayfish" );
      case 2:    return( PPATH + "gull" );
      case 3..7: return( PPATH + "blow_fish" );
      default: return( PPATH + "crab" );
   }

}
