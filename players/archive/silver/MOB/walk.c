//
//  The leader of the orc mob
//  Coded by Silver : Sat 05-06-1995 2:26:52 pm
//

inherit "obj/monster.c";
#include "/players/silver/MOB/defs.h"

// dir table for mob
#include "/players/silver/MOB/mob_dir_table.h"

#pragma strict_types
#pragma save_types

#define SWEEP_TIME   10  // time to move for sweep
#define GO_HOME_TIME 10 // time to move for home
#define MEM 15          // number of members of the mob with leader
#define WIZ_LVL 30
#define MY_FILE "players/silver/MOB/walk"

// ok I know this way is very stupid but it is very SAFE as well
int stop_action;        // stop moving when ordered
int go_home;            // ordered to go home

// some special functions

// are we ordered to go home by wizard ?
 int _go_home_order() { return go_home; }

// accept the order to go home
 void _set_go_home() { go_home=1; return; }

// set stop actions
void _set_stop(int arg) { stop_action=arg; return; }

// get stop_action value
int _stop_action() { return stop_action; }

// what to do when you come back to your home room with captured player
// WILL BE CODED LATER
 void _we_are_at_home()
  {
   // when with group also group dismiss
   SAY("Leader says: OK now we are at home! Good bye!\n");
   DEST( TO );
   return;
  }

// some random picking of exit with check for area
// WILL BE CODED LATER AFTER I'LL DECIDE WHAT ALGORITHM TO USE Silver
 string _get_next_room_when_sweeping()
  {
   // stay here since I don't know ...
   return file_name( ENV( TO ) );
  }

// go back with captured player
 void _go_home()
  {
   string here;
   string next_r; // name of the room

   if( _stop_action() ) { CO( "_go_home", (int)GO_HOME_TIME ); return; }

   here=file_name( ENV( TO ) );
   next_r=_get_next_room_on_the_way_home( here );
   
   // if the journey is finished
   if( next_r=="we_are_home") { _we_are_at_home(); return; }

   // otherwise go to next room
   SAY( "Leader of the mob leaves.\n" ); // direction will be given LATER 
   TRF( TO, next_r );
   SAY( "Leader of the mob arrives.\n" );
   
  // call_out next movement
   CO( "_go_home", (int)GO_HOME_TIME );
   
   return;
  }

// radom movement looking for a player to capture
 void _random_sweep()
  {
    // check for stop action command
    if( _stop_action() ) { CO( "_random_sweep", (int)SWEEP_TIME ); return; }

    // time to head home
    if( _go_home_order() ) { _go_home(); return; }

    // call next step 
    CO( "_random_sweep", (int)SWEEP_TIME );

   return;
  }

// add_actions
 int _whisper_me( string arg )
  {
   int i;
   string who, rest;

   if( ! arg ) return 0;                       // nothing to whisper
   if( TPLVL<=(int)WIZ_LVL ) return 0;         // just wizards may command

   sscanf( arg, "%s %s", who, rest );          // ok analyze the command
   if( who!="leader" ) return 0;               // it was not for you

   // handle the message
   say(CAP((string)TPRN)+" whispered something to leader of the mob.\n" );
   write("You whispered to leader: " + rest + ".\n" );

   // now listen carefully
   switch( rest )
    {
     case "stop":
           _set_stop( 1 );
           SAY( "Leader says: As you wish our commander, we'll stop all "+
           "actions immediately!\n" );
           return 1;

     case "go on":
           _set_stop( 0 );
           SAY( "Leader says: As you wish our commander, we'll continue \n"+
           "in your secret orders with pleasure!\n" );
           return 1;

     case "go home":
           SAY( "Leader says: As you wish our commander,\n "+
                "we are heading home immediately.\n" );
           _set_go_home();
           return 1;

     case "dismiss":
           SAY( "Leader says: As you wish my commander, I'll dismiss "+
                "my group!\n" );
           SAY( "Leader waves.\n" );       
           // send dismiss to all members of the group LATER
           DEST ( TO );
           return 1;

     default:
     write(
      "Leader looks confused and says: sorry but I know only    \n"+
      "these commands ...  stop    ... to stop all actions      \n"+
      "                    go on   ... to get moving again      \n"+
      "                    go home ... to go home immediately   \n"+
      "                    dismiss ... to dismiss the mob       \n"+
      " ... that's all I know mighty commander.                 \n"
          );
     say(
      "Orc shrugs sadly and starts to mumble something about killing.\n"
        );

     return 1;
    }
  }

// regular reset
 void reset(int arg)
  {
   ::reset(arg);
   if( arg ) return;    // do the following just on creation

   SG( 0 );                          // gender
   SAGG( 0 );                        // aggresive
   SN( "Leader of the mob" );        // name
   SA( "mob_leader" );               // alias
   SAN( "leader" );                  // alternate name
   SLVL( 1 );
   SR( "orc" );
   SW( 50 );

   // short && long names
   SS( "Leader of the mob." );
   SL( "This is the leader of the orcs mob.\n" );

   // chats
   LCH(1,({ "The orc says: Kill that one first.\nOrc points at you.\n",
             "The orc grins: I'm the leader!\n"
         }));

   // add some items
   add_money(random(3000));
  
   // do the following just on clone not on load
   // ( call_out loaded ? *shiver* )
   // on load it is just name on clone it is name#


   tell_room("/players/silver/MOB/rooms/tr10","HERE !!!");


   if( file_name( TO )!=(string)MY_FILE )
    {
     tell_room("/players/silver/MOB/rooms/tr10","Create finished.\n");
     // start the way to look for a player captured
     call_out("_random_sweep", (int)SWEEP_TIME );
    }
  }


// and proper init finaly
 void init()
  {
   ::init();
   AA("_whisper_me","whisper");
  }
// END OF FILE        
