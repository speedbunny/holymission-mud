#define PPATH "/players/patience/smilequest/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

int isClosed, isLocked, keyIsHere;

reset( arg )
{

    if(!isClosed) tell_room(this_object(), "With a loud KLONK! the door swings shut.\n");
    isClosed = 1; isLocked = 1; keyIsHere = 1;

    if ( arg )
	return;

    set_light(1);
    short_desc = "In the entrance";
    long_desc = "This is the entrance to the castle of sadness.\n" +
    "Since the wife of the king has died - eons ago - noone\n" +
    "has ever laughed or even smiled in this castle.\n" +
    "The walls and the floor are made of massive stone and to your left\n" +
    "you can see a picture. There is also @@door_state@@ portal to your south.\n";

    items = ({ "stones","Some heavy grey stone blocks",
      "ground","The floor is made of stone",
      "floor","The floor is made of stone",
      "portal","It is a massive golden portal, with a golden keyhole and a golden frame",
      "keyhole","It is made of white gold",
      "frame","It is made of white gold and it's very massive",
      "walls","They are made of massive stone, but you can see a small hole",
      "wall","It is made of massive stone, but you can see a small hole",
      "hole","It is a small hole, and it is completely dark inside. You fear this hole",
      "picture","It is a picture of the dead queen. It is securely locked to the wall",
      "queen","She is a very beautiful lady with a charming smile",
    });

    dest_dir = ({ PPATH + "guardroom", "north",
    });
}


init( )
{
    ::init( );
    add_action("south","south" );
    add_action("search","search");
    add_action("enter","enter");
    add_action("push","move" );
    add_action("push","push" );
    add_action("destroy","break" );
    add_action("destroy","destroy" );
    add_action("destroy","smash" );

    add_action("unlock","unlock");
    add_action("close","close");
    add_action("lock","lock");
    add_action("open","open");
    add_action("knock","knock");
    add_action("picklock","picklock");
}

destroy( str )
{
    if ( !str )
	return;

    if ( str == "portal" || str == "golden portal" ) {
	write( "You are much too weak to destroy the golden portal!!!\n" );
	say( TPN + " tries to destroy the portal, but fails pitiable!!!\n" );
	return( 1 );
    }

    return( 0 );      
}


search( arg )
{
    object key;

    if ( !arg )
	return;

    if ( arg == "hole" ) {
	if ( present( "selfdisc", this_player() ) ) {
	    if ( keyIsHere ) {
		write( "You find a key!!!\n" );
		say( this_player()->query_name()+" found a key.\n" );
		key = clone_object(PPATH + "goldkey");
		if (transfer(key,this_player())) {
		    write( "But you can't carry that much.\n" );
		    destruct( key );
		    return( 1 );
		}
		keyIsHere = 0;
	    }
	}
	else {
	    write( "You don't have the self-discipline to touch into the hole.\n" +
	      "But maybe someone can advise you?!\n" );
	    say(this_player()->query_name()+" tries to search in the hole, but doesn't dare.\n");
	}
	return( 1 );
    }

    write("You search and search, but find nothing.\n");
    say(this_player()->query_name()+" searches around.\n");
    return 1;
}

push( arg )
{
    if ( !arg )
	return;

    if ( arg == "picture" ) {
	write( "You can't move the picture, it is securetly locked to the wall.\n" );
	say( this_player()->query_name() + " tries to move the picture, but fails.\n" );
	return( 1 );
    }

    return( 0 );
}


enter( arg )
{
    if ( !arg )
	return;

    if (arg!="hole" && arg!="the hole") {
	write("The hole is much too narrow to enter.\n");
	say(this_player()->query_name()+" bangs his head against the wall!\n");    
    }

    write("What do you want to enter?\n");

    return 1;
}    

door_state( )
{
    if (isClosed)
	return( "a closed" );
    else
	return( "an open" );
}

/* ----- door - functions -------------------------------------------------- */

picklock(str) {
    if ((str=="portal" || str=="golden portal") && present("picklock",TP)) {
	write("You can't open this golden portal by stupidly using a picklock ...\n");
	say(TPN+" the thief tries to use "+TPPOS+" picklock on the portal.\n" +
	  capitalize(TPOBJ)+" fails completely ...\n");
	return 1;
    }
}

south( ) {
    if (isClosed) {
	write("You bang your head against the closed portal.\n");
	say(TPN+" runs into the portal. Not very effective, though.\n");
    }
    else {
	this_player()->move_player( "south#players/patience/smilequest/foreroom" );
    }
    return 1;
}

knock(str) {
    string msg;

    if (str=="portal" || str == "golden portal" || str=="at portal"
      || str=="at golden portal" ) {
	msg=" at the portal. Knock "; 
	switch(random(14)) {
	case 0: msg+="bong ";
	case 1: msg+="bong ";
	case 2: msg+="BLONG ";
	case 3: msg+="bing ";
	case 4: msg+="knork ";
	case 5: msg+="knerk ";
	case 6: msg+="KNARR ";
	case 7: msg+="boing ";
	case 8: msg+="BONG ";
	case 9: msg+="bing ";
	case 10: msg+="knerk ";
	case 11: msg+="KNORK ";
	case 12: msg+"Knarrrrrrkkkkrrrr ";
	}
	msg+="...\n";
	write("You knock"+msg);
	say(TPN+" knocks"+msg);
	return 1;
    }
}

close(str) {
    if ( !str )
	return;
    if ( str == "portal" || str == "golden portal" ) {
	if (isClosed) {
	    write("The portal is aready closed!\n");
	}
	else {
	    write("You close the portal.\n");
	    say(TPN+" closes the portal.\n");
	    isClosed = 1;
	}

	return( 1 );
    }
}

open (str) {
    if ( !str )
	return;

    if ( str == "portal" || str == "golden portal" ) {
	if ( isLocked ) {
	    write("You can't open the portal, it is locked.\n");
	    say(TPN+" tries to open the portal but fails.\n");
	}
	else if ( isClosed ) {
	    write( "You opened the portal.\n" );
	    say(TPN+" opened the portal.\n" );
	    isClosed = 0;
	}
	else {
	    write( "But it's already open!\n" );
	}

	return 1;
    }

    return( 0 );
}

unlock(str) {
    string str1;

    if (!str)
	return;

    if ( str == "portal with golden key" || str == "golden portal with golden key" ) {
	if ( present( "gkey", TP ) ) {
	    if ( isLocked ) {
		write("You unlock the portal.\n");
		say(TPN+" unlocks the portal.\n");
		isLocked = 0;
	    }
	    else
		write("But the portal is already unlocked.\n" );
	}
	else
	    write( "But you don't have the proper key for that portal!\n" );

	return( 1 );
    }
    else if ( str == "portal" || str == "golden portal" ) {
	write( "With what do you want to unlock the portal?\n" );
	return( 1 );
    }
    else if ( str == "portal with key" || str == "golden portal with key" ) {
	write( "Which key do you mean?\n" );
	return( 1 );
    }
    else if ( sscanf( str, "portal %s", str1 ) ) {
	write( "You can't unlock the portal with that item.\n" );
	return( 1 );
    }

    return( 0 );
}

lock(str)
{
    string str1;

    if ( !str )
	return;

    if ( str == "portal with golden key" || str == "golden portal with golden key" ) {
	if ( present( "gkey", TP ) ) {
	    if ( isClosed ) {
		if ( !isLocked ) {
		    write("You lock the portal.\n");
		    say(TPN+" locks the portal.\n");
		    isLocked = 1;
		}
		else
		    write( "But the portal is already locked.\n" );
	    }
	    else
		write( "You can't lock an open portal.\n" );
	}
	else
	    write( "But you don't have the proper key for this portal.\n" );

	return( 1 );
    }
    else if ( str == "portal" || str == "golden portal" ) {
	write( "With what do you want to lock the portal?\n" );
	return( 1 );
    }
    else if ( str == "portal with key" || str == "golden portal with key" ) {
	write( "Which key do you mean?\n" );
	return( 1 );
    }
    else if ( sscanf( str, "portal %s", str1 ) ) {
	write( "You can't lock the portal with that item.\n" );
	return( 1 );
    }

    return( 0 );
}

IsClosed( )
{
    return( isClosed );
}
