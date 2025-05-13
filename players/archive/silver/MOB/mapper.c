//
//  The mapper for the leader of the mob
//  Coded by Silver : Mon 05-15-1995 3:06:36 pm  
//

inherit "obj/monster.c";  // will be changed to object so none can kill it
#include "/players/silver/MOB/defs.h"

#pragma strict_types
#pragma save_types

#define WIZ_LVL 30     // level from which the mapper can be commanded
#define DEBUGOFF          // on/off debug messages

// limiting conditions
string goal_room;      // name of room which should be reached
int max_rooms;         // max amount of the room which may be mapped

// arrays
string *room_name;     // names of rooms you are in 
int *next_room;        // index of the next room on the way home

// 'indexes' for the arrays
int in_process;        // index of the room being processed
int done;              // counter of the rooms mapped 1 - ...

// >>>>>>>>>>>>>>>> debugging support <<<<<<<<<<<<<<<<<<<<<<<<
// genreate debugging messages
void _DEBUG( string mess ) 
{
#ifdef DEBUG 
    SAY("WizInfo : "+mess+"\n"); // set this format of mess and tell_room
#endif DEBUG
    return;
}

// >>>>>>>>>>>>>>> mapping routines <<<<<<<<<<<<<<<<<<<<<<<<<<<<

// check if the room was not already added to array
int _not_mapped_yet( string arg )
  { return ( ( member_array( arg, room_name )==-1 ) ? 1 : 0 ); }

// regular mapping loop which goes through the all exits in current room
int _mapping_loop()
{
    int i,k;               // loop index
    object pr_room;      // examined room 
    string ex_room_str;  // name of exit room 
    object ex_room;      // exit room itself as an object for mob_ok check
    string *exits;       // array of exits ( in couples: file and direction )

    // get room in process as an object 

    // TO BE CODED LATER
    // ...check if the object exists
    _DEBUG( "index : " + in_process + "\n");
    pr_room=find_object( (string)room_name[ in_process ] );
    if(pr_room==0 ) SAY("Room not found: " + room_name[ in_process ] + "\n" );
    // TO BE CODED LATER

    // allocate memory for array which will contain exits from processed room
    k=sizeof( (string*)pr_room->query_dest_dir() );
    exits=allocate( k ); 

    // TO BE CODED LATER
    // ... check for hidden dir as well query_room( " hidden_dir" )
    // ... set direction on that point ... trace way back from exit room
    // TO BE CODED LATER 

    // get all exits information from current room   
    exits=(string*)pr_room->query_room( "dest_dir"); 
    
   for( i=0; i<=k-1; i+=2 )
     {
      _DEBUG( "exits : " + exits[i] + "  " + i + " \n" );
      }

    // for all exits in the room do
   for( i=0; i<=k-1; i+=2 )
    {
	ex_room_str=exits[ i ];              // get name of exit room
        _DEBUG( "k = " + k + "\n" );
        _DEBUG( " getting room : " + ex_room_str + "\n" );
	ex_room=find_object( ex_room_str );  // get it as an object
        if( ex_room==0 )
         SAY( "Room not found: " + ex_room_str + "\n" );
	// TO BE CODED LATER
	// ...check if the object exists
	// TO BE CODED LATER

 
     _DEBUG("query_property : "+ex_room->query_property( "mob_ok" )+"\n");
     _DEBUG("not mapped yet : " + _not_mapped_yet( ex_room_str  )+ "\n" );
	if( ex_room->query_property( "mob_ok" ) )// if it is within area allowed
	    if ( _not_mapped_yet( ex_room_str  ) )  // if not already mapped
	    {
		room_name+= ({ exits[i] });    // add it to the list
		next_room+=({ in_process });   // set parent room -> next one
		done++;                        // increase counter of mapped rooms
              _DEBUG( "Insreting new room : " + done + "\n" );
	    }

	if( done >= max_rooms )  // check for amount of the room mapped
	    return 0;                // if it matches limit number return fail
    }
    return 1;                  // proper return
} 

// start mapping
void _start_mapping()
{
    _DEBUG( " MAPPING ROUTINE ENTERED ");
    // allocate arrays
    room_name=allocate( max_rooms ); // allocate column with names
    next_room=allocate( max_rooms ); // allocate column with indexes

    // init first line
    room_name=({ });
    next_room=({ });
    room_name+=({ goal_room });      // set target room to be first 
    next_room+=({ -1 });             // set next index to minus anything

    // set pickers
    in_process=0;                    // room being in process = the only one
    done=0;                          // number of rooms mapped already

    _DEBUG( " FIRST LINE OF THE ARRAY SET " );
    _DEBUG( room_name[0] + "\n" );

    while( in_process <= done )      // while there are still unmapped rooms
    {
	if( !_mapping_loop() )         // if reached limiting number
	{                             // send some debugging messages
	    _DEBUG( " NUMBER OF ROOMS MAPPED REACHED THE NUMBER SPECIFIED " );
	    // TO BE CODED LATER
	    // ... some more sensible solution 
	    // TO BE CODED LATER 
	    return;                      // end mapping because of err
	};
        _DEBUG( "Room in process : " + in_process + "\n" );
	in_process++;                  // go to next room to process
    }

    _DEBUG( " MAPPING FINISHED " );  // message mapping ok
    return;                          // proper exit
}


// >>>>>>>>>>>>>>> other routines connected with mapping <<<<<<<<<<<<<<<<<<
// check current table 
void _check()
{
    int i,j;
    j=(int)sizeof(room_name);
    for( i=j-1; i>=0; i-- )  
    {
	// test if the path convergates to 0
	if( next_room[i]>=i )
	{
	    SAY( "Error found at index " + i + "\n" );
	    SAY( "Next room is in opposit direction then target room.\n" );
	    SAY( "Room " + room_name[i] +  " suggests the next step to \n" +
	      room_name[ next_room[i] ] + " which is not right.\n");
	    // TO BE CODED LATER
	    // might be some log to file instead 
	    // TO BE CODED LATER
	}
    }
    return;
}

// report current status

void _report_status()
{
    int i;

    if( goal_room=="not_set" ) SAY("Goal room is not set yet.\n");
    else SAY("Goal room is set to: " + goal_room + "\n" );

    if( max_rooms==-1 )
	SAY("Maximum of rooms to be mapped is not set yet.\n");
    else SAY("MAximum rooms to be mapped: " + max_rooms + "\n" );

    if( goal_room=="not_set" || max_rooms==-1 )
    { SAY("Mapping cannot be started.\n");}

    SAY( "Number of rooms mapped : " + done +  "\n");
    SAY( "Current table : \n" );
       SAY( "\t<index>\t<room name>\t\t\t<index of next room> \n" );

    for( i=0; i<=sizeof(room_name)-1; i++ )
     SAY("\t" + i + "\t" + room_name[i] + "\t" + next_room[i] + "\n" );

    SAY( "\nEnd of report.\n" );
    return;
}
// >>>>>>>>>>>>>>>>> comunication with wizzard <<<<<<<<<<<<<<<<<<<<<<<<
// routine which handles whisper command
int _whisper_me( string arg )
{
    string who, rest, num, all;
    _DEBUG( " ENTERED HANDLE WHISPER ROUTINE " );

    if( !arg ) return 0;                        // nothing to whisper
    if( TPLVL<=(int)WIZ_LVL ) return 0;         // just wizards may command

    sscanf( arg,"%s %s", who, all );            // scan for subject 

    if( who!="mapper" ) return 0;               // it was not for you

    if( sscanf( all, "%s %s", rest, num ) != 2 )// if there are not 2 words 
	rest=all;                                 // then rest is same as all

    _DEBUG( " WHISPER ACCEPTED " );

    // handle the whisper message in the room and info for wiz
    say(CAP((string)TPRN)+" whispered something to mapping robot.\n" );
    write("You whispered to mapper: "+all+".\n" );

    // TO BE CODED LATER
    // ... might be some log to file that wiz commanded mapper
    // TO BE CODED LATER 

    // now listen carefully and handle the command
    switch( rest )
    {

    case "goal":
	// set this room to be the goal room for the mob
	goal_room="/" + file_name( ENV( TO ) );

	SAY( "Mapper says: OK I`ll consider this room as a goal room.\n"+
	  "Goal room is then : " + goal_room  + "\n" );
	return 1;

    case "max":
	// set maximum rooms to be mapped - limit for case of neverending loop
	// well, that kind of the loop should never happen ... but who knows ..
	if( !num )   // number was not given
	{
	    SAY( "Specify amount of rooms to be considered as maximum.\n" );
	    SAY( "Ccommand syntax: whisper mapper max # \n" );
	    return 1;
	}
	max_rooms=to_int( num ); // set given maximum

	SAY( "Mapper says: OK I`ll map up to "+max_rooms+" rooms.\n" );
	return 1;

    case "start":
	// start mapping procedure

	if( goal_room=="not_set" )  // check for goal room specified
	{
	    SAY( "You need to set goal_room first.\n" );
	    return 1;
	}

	if( max_rooms<1 )             // check for limiting number 
	{
	    SAY( "You need to set maximum of the rooms "+
	      "to be mapped first.\n" );
	    return 1;
	}

	// summary report
	SAY( "Mapper says: OK I`ll start mapping right now.\n"+
	  "Goal room is set to: "+goal_room+"\n" +
	  "Maximum of rooms to be mapped: " +max_rooms+ "\n" );
	_start_mapping(); // start mapping right now
           SAY("Mapping is finished, my lord.\n" );
	return 1;

    case "check":
	// check the result table if it is ok 
	SAY( "Mapper says: OK I`ll run the check for "+
	  "the current table.\n" );
	_check();
	return 1;

    case "report":
	// report current status of the mapping robot
	SAY( "Mapper says: OK I`ll here is my report.\n" );
	_report_status();
	return 1;

    default:
	// none of known commands was given --> give help
	write(
	  "Mapper looks confused and says: sorry but I only know        \n"+
	  "these commands ...  goal   .. to set this rooma as goal room \n"+
	  "                    max #  .. to set max_rooms to be mapped  \n"+
	  "                    start  .. to start mapping               \n"+
	  "                    check  .. check current table            \n"+
	  "                    report .. report current status          \n"+
	  "                    load   .. TO BE CODED LATER              \n"+
	  "                    save   .. TO BE CODED LATER              \n"+
	  " ... that's all I know mighty commander.                     \n"
	);
	say( "Mapper shrugs sadly and starts to repair its circuits.\n" );

	return 1; // default exit
    }          // end of switch statement
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>> RESET && INIT <<<<<<<<<<<<<<<<<<<<<<<<<<

// regular reset for monster --> will be replaced with object reset
// ... sp the mapper can't be killed 
void reset(int arg)
{
    ::reset(arg);
    if( arg ) return;          // do the following just on creation

    SG( 0 );                   // gender
    SAGG( 0 );                 // aggresive
    SN( "mapper" );            // name
    SA( "mob_mapper" );        // alias
    SAN( "robot" );            // alternate name
    SLVL( 100 );			      // level 
    SR( "robot" );             // race
    SW( 50 );                  // whimpy

    // short && long names
    SS( "Mapping robot." );
    SL( "The robot which maps the ways for mob leader.\n" );

    // init mapping values
    goal_room="not_set";
    max_rooms=-1;
}

// proper init with one add_action
void init()
{
    ::init();
    AA("_whisper_me","whisper");  // handle commands from wizards
}
// END OF FILE
