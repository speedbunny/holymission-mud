#include "/players/patience/guild/ndef.h"

main( arg )
{
   string fn;
   int vcost;
    
   if(!arg) return printf("Vanish where?\n"),1;
   if(!present("bomb",TP)) return printf("You need a smoke bomb to vanish!\n"),1;
      if ( !TP->query_immortal() && (TP->query_sp() < (TP->query_maxsp()*6) / 10) 
        && !(TP->query_ghost()) ) {
      write( "You have too less spellpoints to vanish.\n" );
      return( 1 );
   }
   else if ( TP->query_ghost() && arg!="guild" && arg!="jingu")
 
    {
      write( "Sorry, but as ghost you are already vanished!\n" );
      return( 1 );
   }
   else if (environment(TP)->query_property("no_teleport")) {
      write( "You try to vanish but a strong force is holding you back !!!\n");
      return( 1 );
   }

   vcost = -1 * ((TP->query_maxsp() * 6) / 10);
   switch(arg)    /* whisky it's faster */
   {
     if (TP->query_sp() < vcost && !TP->query_immortal() && arg!="guild" && arg!="jingu")
     {
       write("You are too low on power.\n");
      return 1;
     }
     case "church": 
         write("You throw down a smoke bomb and vanish!\n");
         say(TPN+" throws down a smoke bomb and vanishes!\n");
         destruct(present("bomb",TP));
         TP->move_player( "X", "/room/church" );
         if ( !(TP->query_immortal()) )
            TP->restore_spell_points(vcost);
      return( 1 );
      
     case "guild": 
         write("You throw down a smoke bomb and vanish!\n");
         say(TPN+" throws down a smoke bomb and vanishes!\n");
         destruct(present("bomb",TP));
         TP->move_player( "X", "/players/dice/guild/room" );
         if ( !(TP->query_immortal()) )
            TP->restore_spell_points(vcost);
      return( 1 );
     case "tree":
         write("You throw down a smoke bomb and vanish!\n");
         say(TPN+" throws down a smoke bomb and vanishes!\n");
         destruct(present("bomb",TP));
        TP->move_player( "X","/players/patience/ezo/inAlmond1");
        if ( !(TP->query_immortal()) )
           TP->restore_spell_points(vcost);
        return 1;
      case "jingu": 
          write("You throw down a smoke bomb and vanish!\n");
         say(TPN+" throws down a smoke bomb and vanishes!\n");
         destruct(present("bomb",TP));
         TP->move_player( "X", "/players/patience/ezo/coast/jingu" );
         if ( !(TP->query_immortal()) )
             TP->restore_spell_points(vcost);
      return( 1 );
      case "temple": 
         write("You throw down a smoke bomb and vanish!\n");
         say(TPN+" throws down a smoke bomb and vanishes!\n");
         destruct(present("bomb",TP));
         TP->move_player( "X", "/players/patience/ezo/forest/forestTemple" );
         if ( !(TP->query_immortal()) )
             TP->restore_spell_points(vcost);
       return( 1 );
       default:
       return( 0 );
     }
   return( 1 );
}



