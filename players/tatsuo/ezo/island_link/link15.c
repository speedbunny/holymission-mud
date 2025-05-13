#define PPATH "/players/tatsuo/ezo/island_link/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     this_object();

inherit "/room/room";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(0);
   short_desc = "The gatehouse";
   long_desc = 
        "This is a huge gatehouse, obvious made by dwarves. It is so high,\n"+
        "that even the ceiling is beyond your sight. To the west is a large\n"+
        "gate with runes drawn onto it.\n";

   items = ({ "gate", "Solid iron. Runes are drawn onto it",
              "runes", "Maybe you should read them",
           });

   dest_dir = ({ PPATH + "link14", "east",
                      });
}

init()
{
   ::init();

   add_action( "do_read", "read" );
   add_action( "do_yell", "yell" );
   add_action( "do_open", "open" );
   add_action( "do_unlock", "unlock" );
   add_action("do_yell","nsay");
}

int do_unlock( string what )
{
   if ( what != "gate" )
      return(0);

   write( "There is no keyhole in this gate.\n" );
   return( 1 );
}

int do_read( string what )
{
   if ( !what )
      write( "What do you want to read ?\n" );
   else if ( what == "runes" || what == "rune" ) {
     if ( TP->query_race() == "dwarf" )
        write( "The runes are of such an old dwarvish tongue, that even\n"+
               "you cannot understand them.\n" );
     else
        write( "The runes seem to be dwarfish. You cannot understand them.\n"+
               "Maybe ask a dwarf what they could mean.\n" ); 
   }
   else
      write( "Impossible !\n" );

   return( 1 );
}

int do_yell( string what )
{
  if( what != "In the name of Amaterasu, I command thee to open" )
   {
      write( "Nothing happens.\n" );
      return( 1 );
   }

   say( TPN + " yells something and the gate opens.\n" );
   write( "The gate opens on thy command ...\n"+
          "and and invisible force carries you through the portal.\n" );
   TP->move_player( "through the portal#"+PPATH+"link16" );
   write( "The portal closes again.\n" );
   say( "After "+TPN+" was carried throught the gate by an invisible force,\n"+
        "it closes again.\n" );

   return( 1 );
}

int do_open( string arg )
{
   if ( !arg )
      write( "Open what ?\n" );
   else if ( arg == "gate" )
      write( "You are MUCH too punny to open this gate !!!\n" );
   else
      write( "And fish can fly, eh ?\n" );

   return( 1 );
}
