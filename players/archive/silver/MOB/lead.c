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

#define SWEEP_TIME 10
#define MY_FILE "players/silver/MOB/lead"
#define MEM 5         // number of members of the mob without leader

// ok I know this way is very stupid but it is very SAFE as well
object* mob;          // array of members
int captured;         // number of captured players
int my_mob_id;        // remember own id
int inited;

// some special functions

// remember own id for a case more mobs will be in action
// this function should ne called by function which clones the leader
 void _set_mob_id( int arg ) { my_mob_id=arg; return; }

// get id of your mob
 int _get_mob_id() { return my_mob_id; }
 
// add the member to the group
 void  _add_member( object new_member )
  {
   mob+=({ new_member });
   return;
  }

// remove the member from the group
 void  _remove_member( object old_member )
  {
   mob-=({ old_member });
   return;
  }


// send all mob mebers to leader if any
 void _summon_mob()
  {
   int i;
   // move all alive members of the mob to leader
   // _follow_leader handles messages for mout and min in the room
   for( i=0; i<sizeof(mob); i++ ) // for all known members do ...
    {
     if( mob[i]==0 ) _remove_member( mob[i] );
      else  mob[i]->_follow_leader();
    }
    
   SAY( "memsize " + sizeof( mob ) + "\n");
    
   return;
  }

// dismiss the group
 void _dismiss()
  {
   int i,j;

   j=sizeof(mob);
   for( i=0; i<j; i++ ) // for all known members do ...
    {
     if( mob[0]!=0 )  mob[0]->_dismissed();
     _remove_member( mob[0] );
    } 
     
     SAY( "memsize " + sizeof( mob ) + "\n");
   return;
  }

// fix the list of members
 void _fix_list()
  {
   int i;
   for( i=0; i<sizeof(mob); i++ )
    if( mob[i]==0 ) _remove_member( mob[i] );

   SAY( "memsize " + sizeof( mob ) + "\n");
     
   return;
  }

// init the mob
 void _init_mob()
  {
   int i;
   object newbie;  // just to be coded more understandable
   
   if( inited ) return; // init just once 
   inited=1;
   
   mob=allocate(MEM);

// clone mob members
   for( i=0; i<MEM; i++)
    {
     newbie=CM( MONSTER + "mob_member" );
     newbie->_set_leader( TO );
     newbie->_set_id( i );
     TRF( newbie, ENV( TO ) );
     _add_member( newbie );
    }

   _fix_list();
    
   SAY( "memsize " + sizeof( mob ) + "\n");

   return;
  }            


// what to do if it dies ?
 void  monster_died()
  {
   int i;
   // WILL BE CODED LATER
   // shout or whatever
   _dismiss();   // dismiss the group
   return;
  }

// add_actions
 int _whisper_me( string arg )
  {
   int i;
   string who, rest;

   SAY( "memsize " + sizeof( mob ) + "\n");

   if( ! arg ) return 0;                       // nothing to whisper
   if( TPLVL<30 ) return 0; // just wizards can command

   sscanf( arg, "%s %s", who, rest );          // ok analyze the command
   if( who!="leader" ) return 0;               // it was not for you

   // handle the message
   say(CAP((string)TPRN)+" whispered something to leader of the mob.\n" );
   write("You whispered to leader: " + rest + ".\n" );

   // now listen carefully
   switch( rest )
    {

     case "report":
           _fix_list();
           say( "Leader briefly reports to "+TPRN+".\n" );
           write( "Here is my report my commander: \n"+
           " Group memebers alive: "+ sizeof(mob) +"\n"
              );
           return 1;

     case "init":
           SAY( "Leader says: As you wish my commander, "+
                "I'll init my group!\n" );
           _init_mob();
           return 1;

     case "summon":
           SAY( "Leader says: As you wish my commander, "+
                "I'll summon my group!\n" );
           _summon_mob();
           return 1;

     case "dismiss":
           SAY( "Leader says: As you wish my commander, I'll dismiss "+
                "my group!\n" );
           _dismiss();
           SAY( "Leader waves.\n" );
           // notify creator about mob dismissing LATER
           DEST ( TO );
           return 1;        
   case "refresh":
           SAY( "Leader says: As you wish my commander, I'll call "+
                "fresh solders.\n" );
           _dismiss();     // well it is most easy way how to refresh
           _init_mob();
           return 1;

     default:
     write(
      "Leader looks confused and says: sorry but I know only       \n"+
      "these commands ...                                          \n"+
      "                    report  ... to report current status    \n"+
      "                    summon  ... to summon all members       \n"+
      "                    init    ... to init all members         \n"+
      "                    dismiss ... to dismiss the mob          \n"+
      "                    release ... to release captured players \n"+
      " ... that's all I know mighty commander.                    \n "
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
   add_money(random(200));

  }


// and proper init finaly
 void init()
  {
   ::init();
   AA("_whisper_me","whisper");
  }
// END OF FILE              
