inherit "/obj/treasure";
object mad;
int    time;
id(arg) {
   return( "_insanity_" );
}

reset(arg) {
   if(arg) return;
   time = 0;
   mad = 0;
}

init() {
   add_action( "_nothing", "", 1 );
}

start_madness(arg) {
   mad = find_living( arg );
   if(!mad) {
      write( "oops\n" );
      mad = 0;
      return( 1 );
   }
   mad->move_player( "X#room/church" );
   call_out( "handle_insane", 0 );
   time = 0;
   return( 1 );
}

handle_insane() {
   int    time1, i;
   object *ai;
   if ( !mad ) {
      destruct( this_object() );
      return;
   }
   move_object( this_object(), environment( this_object() ) );
   switch( random( 100 ) ) {
      case 0:
      case 1..5:   shout( capitalize( mad->query_real_name() ) + " shouts: " +
                      "Please help me, they are creeeping over me !!!\n" );
                   break;
      case 6..14:  tell_object( mad, "You can see white mice creeping over you !!!\n" );
                   break;
      case 15..22: tell_object( mad, "A white mice bites you in your nose !!!\n" );
                   break;
      case 23..29: tell_object( mad, "Beetles creeping out of you mouth !!!\n" );
                   break;
      case 30..35: shout( capitalize( mad->query_real_name() ) + " shouts: " +
                     "Please help me, I don't want to die !!!\n" ); 
                   break;
      case 36..43: tell_object( mad, "You giggles insanly.\n" );
                   break;
      case 44..50: tell_object( mad, "You can see your back !\n" );
                   break;
      case 51..58: tell_object( mad, "You smiles at your feet.\n" );
                   break;
      case 59..67: tell_object( mad, "You brubble.\n" );
                   break;
      case 76..82: tell_room( mad, capitalize( mad->query_real_name() ) + 
                      " says: Two beer or not the beer, that is the question.\n" );
                   break;
      case 83..87: tell_object( mad, "Where is the nest of the coocoo ?\n" );
                   break;
      case 88..95: tell_room( environment( mad ), capitalize( mad->query_real_name() ) +
                      " says: Freedom for Ugu-Ugu !!!\n" );
                   break;
      default:     shout( capitalize( mad->query_real_name() ) + " tells you: " +
                      "I'm working on OPERATION MINDCRIME !!!\n" );
   }
   time1 = random( 40 );
   time += time1;
   ai = all_inventory( environment( mad ) );
   if ( ai ) {
      i = 0;
      while ( i < sizeof( ai ) ) {
         tell_object( ai, mad->query_name() + " smiles insanly.\n" );
         i++;
      }
   }
   if ( time > 300 ) {
      tell_object( mad, "You suddenly feel much more better !!!\n" );
      destruct( this_object() );
   }
   else
      call_out( "handle_insane", time1 );
   return( 1 );
}

_nothing(arg) {
   if(!mad) return;
   arg = query_verb();
   if ( arg == "west" || arg == "east" || arg == "south" || arg == "north" ||
        arg == "southwest" || arg == "southeast" || arg == "northwest" ||
        arg == "northeast" || arg == "e" || arg == "w" || arg == "n" || arg == "s" ||
        arg == "up" || arg == "u" || arg == "down" || arg == "d" || arg == "nw" ||
	arg == "ne" || arg == "se" || arg == "sw" ) {
      tell_object( mad, "You go in a direction, but was it the right !?\n" );
      mad->run_away();
      return( 1 );
   }
   if ( arg == "l" || arg == "look" )
      return( 0 );
   tell_object( mad, "You entered the realms of Madness !!!\n" );
   return( 1 );  
}
