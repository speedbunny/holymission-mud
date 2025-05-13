
#include "/players/apollo/defs.h"
/*
#include "/players/apollo/pictures/dragon.c"
#include "/players/apollo/pictures/totem.c"
#include "/players/apollo/pictures/odie.c"
#include "/players/apollo/pictures/dino.c"
#include "/players/apollo/pictures/castle.c"
#include "/players/apollo/pictures/christmas.c"
*/
#include "/players/apollo/pictures/castle.c"

inherit "room/room";

int shield,i;
string who;
object me;

void reset( int arg ) {
   if( !arg ) {
  
      SL(1);

      SD = CNAME + "'s Workroom";
      
      LD = BS(  "	\n" +
	        "                           The Workroom of " + CNAME + ".\n" +
	        "	\n" );

      DD = ({
		"/players/matt/newworld/city/rooms/votebooth", "voting",
		"/room/adv_guild", "adventures",
		"/room/church", "church",
		"/room/post", "post", });

      I = ({
         "air", "It is very thin up here",
         "floor", "The floor is cluttered with papers", });
 
      P = ({
	"no_teleport", });

    }
 }
 
void init() {
  ::init();

  AA("_quit", "quit");
  AA("_clone", "clone");
  AA("set_shield", "shield");
  AA("_expel", "expel");
  AA("no_invis", "invis");
  AA("no_invis", "hide");
  AA("no_cast", "cast");
  AA("no_locate", "locate");
  AA("no_track", "track");
  AA("no_find", "find");

  if ( ( RN != NAME ) && ( RN != MISTI ) && ( RN != ZEUS ) ) { 
    if( !FPME || !present( NAME , TO ) ) {
      if( (FPME) )
        TL( FPME,
	sprintf("	\n" +
		"%s tried to enter your workroom%s while you are away !!\n" +
		"	\n",
		RNAME,TPI?" ( INVISIBLE )":""));
        printf(	"	\n" +
		"Apollo has been alerted to to you attempting to \n" +
		"break into his workroom%s while he is out !!\n" +
		"	\n" +
		"He will be with you momentarily.\n" +
		"	\n",
             	TPI?" ( INVISIBLE )":"");
      if(catch( MO( TP, "/players/"+RN+"/workroom" )))
        MO( TP, "/room/church" );
      printf(	"You wind up on your butt in %s. How funny!\n" +
		"	\n",
             FN( ENV(TP) )=="room/church"?"the church":"your workroom");
      return;
  }
  else if(shield) {
      printf(	"	\n" +
		"You failed to enter Apollo's workroom because of a shield.%s\n",
             TPI?" ( INVISIBLE )":"");
      say(sprintf(	"	\n" +
			"%s tries to enter%s, but is blocked by the shield.\n" +
			"	\n",
                  RNAME,TPI?" ( INVISIBLE )":""));
      if(catch(MO( TP, "/players/"+RN+"/workroom" )))
        MO( TP, "/room/church" );
      printf(	"You wind up on your butt in %s. How funny!\n" +
		"	\n",
             FN( ENV( TP ) )=="room/church"?"the church":"your workroom");
      return;
  }
 
    if( FPME ) {
      write(	"	\n" +
		"	\n" +
		"Welcome to " + CNAME + "'s Workroom.\n" +
		"	\n" +
		"	\n" );
      TL(FPME, sprintf(	"	\n" +
			"%s has entered your workroom%s !!\n" +
			"	\n",
                   	RNAME,TPI?" ( INVISIBLE )":""));
    }

  }

}

int set_shield( string str ) {
  if( ( RN != NAME ) && (RN != ZEUS ) ) {
	say( RN + " attempted to use the shield! You laugh as " + RN +
		" is disintergrated!!\n" );
	write( "You are a fool for trying to use Apollo's shield!\n" );
	write( "Enjoy re-relogging in again!\n" );
	destruct( TP );
	return 1;
  }

    if(!str) {
      if( shield == 1 ) {
	write( "	\n" +
	       " =========================================== \n" +
	       " |					   | \n" +
	       " |    The shield is currently ACTIVATED    | \n" +
	       " |					   | \n" +
	       " =========================================== \n" +
	       "	\n" );

	return 1;
      }

      write( "	\n" +
	     " =========================================== \n" +
	     " |                                         | \n" +
	     " |   The shield is currently DEACTIVATED   | \n" +
	     " |                                         | \n" +
	     " =========================================== \n" +
	     "	\n" );
       return 1;

     }

  if(str == "on") {
    write("You place a spell on the room and a shield rises.\n");
    say(sprintf("%s speaks some magic words and the room seems to be protected.\n",
                RNAME));
    shield = 1;
    return 1;
  }

  if(str == "off") {
    write("You lower your hand and the shield around the room lowers.\n");
    say(sprintf("%s lowers their hand and the shield around the room lowers.\n",
                RNAME));
    shield = 0;
    return 1;
  }
  else
    return 0;
}

no_invis() {
  if ( ( RN != NAME ) && ( RN != MISTI ) && ( RN != ZEUS ) && !TPQI( RN ) ) {
	write( 	"	\n" +
		"You may not turn ( INVISIBLE ) ... \n" +
		"	\n");
	TL( FPME ,	"	\n" +
		RNAME + " tried to turn ( INVISIBLE ) in your workroom!\n" +
		"	\n");
  return 1;
  }
}

no_cast() {
  if ( RN != NAME ) {
	write(	"	\n" +
		"You may not cast spells while in this room!\n" +
		"	\n");
	TL ( FPME ,	"	\n" +
		RNAME + " tried to cast a spell in your workroom!\n" +
		"	\n");
  return 1;
  }
}

no_locate() {
  if ( RN != NAME ) {
	write(	"	\n" +
		"You may not locate anyone while in this room!\n" +
		"	\n");
	TL ( FPME, 	"	\n" +
		RNAME + " tried to locate someone while in your workroom!\n" +
		"	\n");
  return 1;
  }
}

no_track() {
  if( RN != NAME ) {
	write(	"	\n" +
		"You may not track anyone while in this room!\n" +
		"	\n");
	TL ( FPME, 	"	\n" +
		RNAME + " tried to track someone while in your workroom!\n" +
		"	\n");
  return 1;
  }
}

no_find() {
  if( ( RN != NAME ) && ( RN != MISTI ) ) {
	write(	"	\n" +
		"You may not find anyone while in this room!\n" +
		"	\n");
	TL ( FPME,	"	\n" +
		RNAME + " tried to find someone while in your workroom!\n" +
		"	\n");
  return 1;
  }
}

_quit(arg) {
  if ( (RN != NAME ) && (RN !="zeus") ) {
	write( 	"	\n" +	
		"Sorry, but you may not quit from this room!\n" +
		"	\n");
  return 1;
  }
}

_clone(str) {
  if ( ( RN != NAME ) && ( RN != MISTI ) ) {
	write(	"	\n" +
		"Only Apollo is allowed to clone things in this room.\n" +
		"Therefore, if you need any help please ask for assisstance.\n" +
		"	\n");
  return 1;
  }
}

int _expel(string arg) {
  object player;
  object expelroom;

  player = present (arg, TO);
  expelroom = FO( "/room/church" );

  if( ( RN != NAME ) && ( RN != MISTI ) ) return 0;

  if(!arg) {
    write (	"	\n" +
		"Whom do you wish to expel?\n" +
		"	\n");
    return 1;
  }

  if(!player) {
    write (	"	\n" +
		"Sorry, but that player is not here.\n" +
		"	\n");
    return 1;
  }

  else {
    transfer( player , expelroom );
    write (	"	\n" +
		"You expel " + player->QN +" to the church.\n" +
		"	\n");
    TR( TO,	"	\n" + 
	player->QN + " has been expelled to the " +
	"church by " + RNAME + ".\n" +
	"	\n");
    TL(player, 	"	\n" +
		"You are moved to the church by " + RNAME + ".\n" +
		"	\n");
  return 1;
  }

}
