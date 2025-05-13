#include "std_defs.h"
inherit "room/room";
#define PRIV "/players/kiri/private/monsters/"

string shield;

void reset( int tick ) {
   ::reset( tick );
   if( tick ) return;
      
   short_desc = "Kiri's Realm",
   long_desc =
      "Through some twist of fate, you have been swooped up in a strange " +
      "mist and deposited here. Swirling, multicolored mists surround " +
      "you, obscuring your vision. The air is cool and dump, with " +
      "something mystical or psychic withhin the mist, which even those " +
      "are neither can sense.\n";
   set_light( 1 );
   dest_dir = ({ "players/haplo/workroom", "haplo",
                 "room/church", "church", });
   property = ({ "no_teleport", "no_sneak", "no_steal", });
}
      
void init() {
   ::init();
   add_action( "_workroom", "wr" );  
   if( shield == "on" && this_player() -> query_real_name() != "kiri" ) {
      write( "Kiri is very busy now, sorry *wave*\n" );
      move_object( this_player(), "/room/church" ); 
   }
   this_player() -> set_smell(
      "You notice the faint aroma of a godlike being...\n" );
}
      
int _workroom( string arg_string ) {
   string *arg;
   if( !( TP -> query_immortal() ) )
      return( 0 );
   if( !arg_string ) {
      notify_fail( "The mists start to move but nothing happens...\n" );
      return( 0 );
   }
   arg = explode( arg_string, " " );
   if( arg[0] == "money" ) {
      if( sizeof( arg ) < 2 ) {
         TP -> add_money( 1000000 );
         write( "The mists slips into your pockets and turns into " +
            "hard gold coins...\n" );
         return( 1 );
      }
      TP -> add_money( to_int( arg[1] ) * 1000000 );
      write( "You get mountains of gold from the mists.\n" );
      return( 1 );
   }
   if( arg[0] == "enter" ) {
      if( sizeof( arg ) < 2 ) {
         notify_fail( "where do you want to enter?\n" );
         return( 0 );
      }
      move_object( TP, find_living( arg[1] ) );
   }

   if( TP -> QRN != "kiri" )
      return( 0 );
   if( arg[0] == "shield" ) {
      if( sizeof( arg ) < 2 ) {
         write( "Shieldstatus: " + shield + "\n" );
         return( 1 );
      }
      shield = arg[1];
      write( "Shield turned to: " + shield + "\n" );
      return( 1 );
   }
   if( arg[0] == "trans" ) {
      if( sizeof( arg ) < 2 ) {
         notify_fail( "trans whom?" );
         return( 0 );
      }
      move_object( find_living( arg[1] ), "/players/kiri/workroom" );
   }
   return( 1 );
}

int _smile() {
   move_object( clone_object( PRIV + "man" ), "/players/kiri/workroom" );
   return( 0 );
}
