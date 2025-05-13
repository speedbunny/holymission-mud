#define PPATH "/players/tatsuo/ezo/island_link/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     this_object()

inherit "/room/room";

int *door_status, *ghast;

void gimme_ghast( int which );


reset( arg )
{
   door_status = ({0,0,0,0});
   ghast = ({0,0,0,0});
   if ( arg )
      return;
      
   set_light(1);
   short_desc = "Inside the tomb";
   long_desc = 
        "You are inside a tomb. The stench of rotten corpses in here is\n"+
        "overwhelming and nearly makes you puke. Lined along the wall are\n"+
        "chambers, tall enough for a man to fit in. The cambers all have\n"+
        "lids and it is obvious, that they are used as burrial-chambers.\n"
        "The nausea is REALLY overwhelming you now and you cannot hold back\n"+
        "your dinner for very much longer ...\n";

   items = ({ "wall", "There are chambers along the wall",
              "chambers", "They are huge enough for a man to fit in",
              "lid", "Made of wood, nearly rotten",
              "lids", "Made of wood, nearly rotten",
           });

   dest_dir = ({ "/players/tatsuo/shadows/gy2", "out",
                   });
}

init()
{
   ::init();

   add_action( "do_open", "open" );
   add_action( "do_close", "close" );
   add_action( "do_enter", "enter" );
}

int do_open( string arg )
{
   if ( !arg )
      write( "Open what, your eyes ? If so, say it ...\n" );
   else if ( arg == "eyes" )
      write( "Which one ? The left eye, the right eye, or both eyes ?\n" );
   else if ( arg == "left eye" || arg == "right eye" )
      write( "Wouldn't it be better to raise just your eyelid ?\n" );
   else if ( arg == "both eyes" )
      write( "Wouldn't it be better to raise just your eyelids ?\n" );
   else if ( arg == "lid" )
      write( "Which one ? Open lid 1 or open lid 2 ... or open lid 4.\n" );
   // ---- i know i can do the following shorter, but i don't care
   // ---- if YOU do, shorten it
   else if ( arg == "lid 1" ) {
      if ( !door_status[0] ) {
        gimme_ghast(0);
        door_status[0] = 1;
      }
      else
        write( "This lid is already open. The grave-chamber is empty.\n" );
   } 
   else if ( arg == "lid 2" ) {
      if ( !door_status[1] ) {
        gimme_ghast(1);
        door_status[1] = 1;
      }
      else
        write( "This lid is already open. The grave-chamber is empty.\n" );
   } 
   else if ( arg == "lid 3" ) {
      if ( !door_status[2] ) {
        door_status[2] = 1;
        gimme_ghast(2);
      }
      else
        write( "This lid is already open. The grave-chamber is empty.\n" );
   } 
   else if ( arg == "lid 4" ) {
      if ( !door_status[3] ) {
        gimme_ghast(3);
        door_status[3] = 1;
      }
      else
        write( "This lid is already open. The grave-chamber is empty.\n" );
   } 
   else
      write( "And your mama is a pinguin, eh ?\n" );

   return( 1 );
}

int do_close( string arg )
{
   if ( !arg )
      write( "Close what, your eyes ? If so, say it ...\n" );
   else if ( arg == "eyes" )
      write( "Which one ? The left, the right, or both eyes ?\n" );
   else if ( arg == "left eye" || arg == "right eye" )
      write( "Wouldn't it be better to just lower your eyelid ?\n" );
   else if ( arg == "both eyes" )
      write( "Wouldn't it be better to just lower your eyelids ?\n" );
   else if ( arg == "lid" )
      write( "Which one ? Open lid 1 or open lid 2 ... or open lid 4.\n" );
   // ---- i know i can do the following shorter, but i don't care
   // ---- if YOU do, shorten it
   else if ( arg == "lid 1" ) {
      if ( door_status[0] ) {
        write( "You close the lid.\n" );
        door_status[0] = 0; 
      }
      else
        write( "This lid is already closed.\n" );
   } 
   else if ( arg == "lid 2" ) {
      if ( door_status[1] ) {
        write( "You close the lid.\n" );
        door_status[1] = 0;
      }
      else
        write( "This lid is already closed.\n" );
   } 
   else if ( arg == "lid 3" ) {
      if ( door_status[2] ) {
        write( "You close the lid.\n" );
        door_status[2] = 0;
      }
      else
        write( "This lid is already closed.\n" );
   } 
   else if ( arg == "lid 4" ) {
      if ( door_status[3] ) {
        write( "You close the lid.\n" );
        door_status[3] = 0;
      }
      else
        write( "This lid is already closed.\n" );
   } 
   else
      write( "And your mama is a pinguin, eh ?\n" );

   return( 1 );
}

int do_enter( string arg )
{
   int    which;
   string dummy;

   if ( !arg )
      return(0);

   sscanf( arg, "%s %d", dummy, which );

   if ( arg == "chamber" )
      write( "Which one ? Enter chamber 1 or enter chamber 3 ....\n" );
   else if ( dummy == "chamber" && which == 3 ) {
      if ( !door_status[which-1] )
         write( "Right through the lid ?  Strange concept ....\n" );
      else {
         write( "You crawl to the chamber and realise, that there is a chamber"+
                "right behind it\nYou move on and stand in a chamber.\n" );
         TP->move_player( "into one of the chamber. Will he ever come back ?#"+
                          PPATH+"link18" );
      }
   }
   else if ( dummy == "chamber" && which >= 1 && which <= 4 ) {
      if ( !door_status[which-1] )
         write( "Right through the lid ?  Strange concept ....\n" );
      else
         write( "Your character refuses to enter !\n" );
   } 

   return( 1 );
}

void gimme_ghast( int which )
{
   int    no;
   object monst;

   if ( which < 0 || which > 3 )
      return;
   if ( ghast[which] ) {
      write( "You open the lid.\n" );
      return;
   }
   if ( which == 2 ) {
      write( "You open the lid.\n" );
      say( TPN+" opens on of the lids.\n" );
      return;
   }

   ghast[which] = 1;

   no = random(3)+1;   
   if ( no == 1 ) {
    write( "You open one of the lids and an undead creature crawls out !!!\n" );
    say( TPN+" opens one of the lids and an undead creature crawls out !!!\n" );
   }
   else {
    write( "You open one of the lids and undead creatures crawl out !!!\n" );
    say( TPN+" opens one of the lids and undead creatures crawl out !!!\n" );
   }

   while ( no ) {
      monst = clone_object( PPATH+"ghast" );
      transfer( monst, TO );
      no--;
   } 

   if ( which == 1 ) {
      write( "You found a key !!!\n" );
      transfer( clone_object(PPATH+"skull_key"),TP );
   }
}
