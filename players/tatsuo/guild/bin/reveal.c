#include "/players/tatsuo/guild/ndef.h"

main()
{
if (!TP->query_invis() ) {
      write( "You are already visible.\n" );
      return( 1 );
   }

	TP->set_vis();
      write("You reveal yourself.\n");
      if(present("camouflager")) {
      destruct("camouflager");
      }
	return 1;
}
