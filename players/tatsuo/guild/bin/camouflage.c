
#include "/players/tatsuo/guild/ndef.h"

int camou_block;
int camou_left;
object shad;

main( arg )
{
   if ( arg )
      return;
      
   if ( TP->query_ghost() ) {
      write( "You cannot camouflage yourself as a ghost.\n" );
      return( 1 );  

   }
  if (TP->query_invis() ) {
      write( "You are already camouflaged.\n" );
      return( 1 );
   }

 if(TPL <= 9 ) return printf("You haven't learn this ability yet!!\n"),1;
   if (TP->query_sp() < CAMOU_COST){
      write("You lack the strength to become one with your environment.\n");
      return ;
   }
 
/*
   if ( present("camtime",TP)) {
      write( "You have to wait a while, until you can try to camouflage yourself again.\n" );
      return( 1 );
   }
*/
   
  if (random(105) < SILENCESKILL)
     {
      shad = clone_object("/players/tatsuo/guild/camouflager");
      move_object(shad,TP);      
      camou_block = 1;
      TP->set_invis(0);
      write( "You think, you are one with your environment now.\n" );
      move_object(clone_object("/players/tatsuo/guild/camtime"),TP);
 
       }
   
else {
      write( "You think, you are one with your environment now.\n" );
      move_object(clone_object("/players/tatsuo/guild/camtime"),TP);
                   }
   
   return( 1 );
}

