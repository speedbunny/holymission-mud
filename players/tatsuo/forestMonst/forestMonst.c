#define ANZ_MONST  (3)
#define PPATH      "/players/tatsuo/forestMonst/"
rnd_monster( )
{
   switch( random( ANZ_MONST ) ) {
      case 0:  return( PPATH + "deer" );
      case 1:  return( PPATH + "wolf" );
      case 2:  return( PPATH + "brownBear" );
      default: return( PPATH + "wolf" );
   }

}
