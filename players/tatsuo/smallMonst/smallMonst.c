#define ANZ_MONST  (3)
#define PPATH      "/players/tatsuo/smallMonst/"

rnd_monster( )
{
   switch( random( ANZ_MONST ) ) {
      case 0:  return( PPATH + "smallDog" );
      case 1:  return( PPATH + "greenSnake" );
      case 2:  return( PPATH + "smallSpider" );
      default: return( PPATH + "smallSpider" );
   }

}
