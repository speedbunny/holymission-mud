#include "/players/kawai/defs.h"

inherit "room/room";

int shield,i;
string who;

void reset( int arg ) {
   if( !arg ) {
  
      SL(1);

      SD = CNAME + "'s Workroom";
      
      LD = 
         "         \n" +
         "			The Workroom of " + CNAME + ".\n" +
	 "	   \n" +
	 " 	   \n" +
	 "	   \n" +
	 "	   \n" +
	 "	   \n" +
         "         \n" +
         "         \n" +
         "         \n" +
         "         \n" +
         "         \n" +     
         "         \n" +
         "         \n";

      DD = ({
		"/players/misticalla/workroom", "misti",
		"/players/tatsuo/workroom", "tatsuo",
		"/players/haplo/workroom", "haplo",
		"/players/silas/workroom", "silas",
		"/players/portil/guild/room", "fighters",
		"/players/matt/newworld/city/rooms/votebooth", "voting",
		"/players/gareth/workroom", "gareth",
		"/room/adv_guild", "adventures",
		"/room/church", "church",
		"/room/post", "post", });

      I = ({
         "air", "It is very thin up here",
         "floor", "The floor is cluttered with papers", });
 
      P = ({
         "no_invisible",
         "no_snoop", });

    }
 }
 
void init() {
  object me;
  ::init();
  
  AA("set_shield", "shield");

  if ( (RN != NAME) && (RN !="misticalla") ) {
     if ( FL( NAME ) && !present( NAME, TO) ) {

	if ( TPI ) {
	  TL( FL( NAME ), "	\n" +
		RNAME + " tried to enter your workroom while " +
		"you are you away !! ( INVISIBLE ) \n" +
		"	\n" );
	  write(	"	\n" +
		"You cannot enter ( INVISIBLE ) when Apollo is not at home !! \n" +
		"	\n" +
		"You have been moved to the church !! \n" +
		"	\n" );
	  MO( TP, "/room/church" );
	  return;
	} 

	if ( (RN !="apollo") && (RN !="misticalla") ) {
	  TL( FL( NAME ), " 	\n" +
		RNAME + " tried to enter your workroom while " +
		"you are away !! \n" +
		"	\n" );
	  write(	"	\n" +
		"You canot enter when Apollo is not at home !! \n" +
		"	\n" +
		"You have been moved to the church !! \n" +
		"	\n" );
	  MO( TP, "/room/church");
	  return;
	}

      	if ( TPI && shield && (RN !="misticalla") ) {
	  write(	"	\n" +
		"You failed to enter Apollo's workroom. ( INVISIBLE ) \n" +
		"You wind up on your butt in the church. How funny! \n" +
		"	\n" );
	  say(	"	\n" +
		RNAME + " tries to enter ( INVISIBLE ) , but is blocked \n" +
		"by the shield and moved to the church. \n" +
		"	\n" );
	  MO( TP, "/room/church");
	  return;
      	}

      	if ( shield && ( RN !="misticalla") ) {
	  write(	"	\n" +
		"You failed to enter Apollo's workroom. \n" +
		"You wind up on your butt in the church. How funny! \n" +
		"	\n" );
	  say(	"	\n" +
		RNAME + " tries to enter, but is blocked by the " +
		"shield and moved to the church. \n" +
		"	\n" );
	  MO( TP, "/room/church" );
	  return;
      	}
 
        else {
          write(	"	\n" +
		"	\n" +
		"Welcome!! \n" +
		"	\n" );
	  if ( TPI ) {
	    TL( FL( NAME ), "	\n" +
		RNAME + " has entered you workroom !! ( INVISIBLE ) \n" +
		"	\n" );
          }

	  else {
	    TL( FL( NAME ), "	\n" +
		RNAME + " has entered your workroom !! \n" +
		"	\n" );
	  }

      	}

    }
  }

}

int set_shield(string str) {
  if((RN !="apollo") && (RN !="misticalla"))
    return 0;
  if(!str) {
    write (	"	\n" +
		" ========================== \n" +
		" | Shield is currently " + shield + ". | \n" +
		" |			  | \n" +
		" |	0 = disabled      | \n" +
		" |	1 = armed         | \n" +
		" ========================== \n" +
		"	\n" );
    return 1;
  }

  if( str == "on" ) {
    write("You place a spell on the room and a shield rises.\n");
    say( RNAME + " speaks some magic words and the room seems to be protected.\n");
    shield=1;
    return 1;
  }

  if(str == "off") {
    write("You lower your hand and the shield around thr room lowers.\n");
    say( RNAME + " lowers their hand and the shield around the room lowers.\n");
    shield=0;
    return 1;
  }
}

/*

AA("expel", "expel");

int expel(string arg) {
  object player;
  if((RN != "apollo"))
    return 0;
  if(!arg) {
    write ("Expel whom?\n");
    return 1;
  }
  player = present (arg, TO);
  if(!player) {
    write ("That player is not here.\n");
    return 1;
  }
  write ("You expel " + player->query_name() +".\n");
  player->MP ("to the church#/room/church");
  tell_room ( RN + " has been expelled to the church by " + RNAME + ".\n");
  return 1;

}
*/
