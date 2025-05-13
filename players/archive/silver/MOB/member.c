//
//   Orc for the mob
//   Coded by Silver : Sat 05-06-1995 2:26:52 pm
//

inherit "obj/monster.c";     
#include "/players/silver/MOB/defs.h"

#pragma strict_types
#pragma save_types

int my_id;                        // remember own id
object your_leader;               // remember your leader

// some specialities

// get your leader
 object _get_leader() { return your_leader; }

// get no_leader
 int _leader_died() { return ( _get_leader()==0 ? 1 : 0 ); }

// remember own id
 void _set_id( int arg ) { my_id=arg; return; }
 
// set your leader
 void _set_leader( object arg ) { your_leader=arg; return; }
 
// follow your leader when he wants
 void _follow_leader() 
  {
   if ( _leader_died() ) return; // sorry but no leader for me
   SAY( "An orc runs away to follow his leader\n" );
   TRF( TO, ENV( _get_leader() ) );     // go to leader
   SAY( "An orc entered the room following his leader.\n" );
   return;
  }

// _dismiss()
// now that function handles the end of the group just by dest of the group 
// here your ideas are welcomed more then anywhere else ...
// what should happen to group memebers when the leader dies ?

// this function is as well used for dismiss command
 void _dismiss()
  {
   SAY("An orc looks around and suddenly starts to run away.\n" );  
   if( !_leader_died() ) _get_leader()->_mob_died( my_id );
   DEST( TO ); 
   return;
  }

// what to do when the leader get killed?
 void _dead_leader_reported()
  {
   // THIS PART SHOUD BE DISCUSSED AS WELL 
   _dismiss();
   return;
  }
  

// proper reset
 void reset(int arg)
  {
   ::reset(arg);
   if( arg ) return; // do following just on create

   SG( 0 );            // gender
   SAGG( 0 );          // aggressive
   SN( "orc" );        // name
   SA( "mob" );        // alias
   SAN( "orc" );       // alternate name
   SLVL( 10 );         // level
   SR( "orc" );        // race
   SW( 0 );            // whimpy

   // short && long names
   SS( "Huge orc looking for an intruder." );
   SL( "This is an orc one form the group which sweeps the country.\n" );

   // chats
   LCH(1,({ "Orc screams: Why to go that far ?\n",
            "Orc says: I'd eat it here and now!\n",
            "Orc looks at you!"
          }));

   // add some items
   AM(random(200));   // add money
  }

// what to do if it dies ?
 void  monster_died()
  {
   // shout or whatever
   return;
  }
 
// END OF FILE
