#define PPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()

inherit "room/room";

#define SMITH "/players/tatsuo/eastMonst/smith"

object smith;

reset( arg )
{
   if ( !smith || !present( smith, this_object() ) ) {
      smith = clone_object( SMITH );
      transfer( smith, this_object() );
   }

   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In a cave";
   long_desc =
    "You are in a cave of a mountan. But this cave is not a normal cave.\n" +
    "The walls are plain and in the middle of the cave is a large workbench\n" +
    "with an amboss on it. Near the wall is a carpet with nihonese symbols.\n" +
   "Placed near aside the carpet is a small table, with candles on it, which\n"+
"lighten most of the room. You enjoy the comfort of this cave and turn happy.\n"+
    "You wonder why anyone would live way up here.\n";
   items = ({ "walls", "They are plain and made of stone",
              "wall", "The wall is plain and made of stone",
              "workbench", "There is an amboss on it, but the amboss is too heavy to lift",
              "amboss", "A quite normal amboss, but very, very heavy",
              "carpet", "It is a very nice carpet, looking very soft",
              "symbols", "Some nihonese symbols, one is the symbol for \"tao\"",
              "table", "A table in nihonese styling. It is very low",
              "candles", "The candles illuminates most of the room. They are fixed to the table",
              "note", "Maybe you should read it",
              "chest", "It is a magic chest and cannot be opened by you",
              });
              
   dest_dir = ({ PPATH + "valley4", "north",
              });
   
   smell = "You smell the odor of steel.";
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   add_action( "enter_it", "enter" );
   add_action( "read_it", "read" );
}

read_it( what )
{
   if ( what != "note" )
      return( 0 );

   write( 
      "+-----------------------------------------------------------+\n"+
      "| If you already have a katana, a wakizashi or a ninja-to,  |\n"+
      "| you may store it here. Just type \"store <weapon>\" to      |\n"+
      "| do so.                                                    |\n"+
      "| To get your weapon back, type \"katana\", \"wakizashi\",      |\n"+
      "| or \"ninja-to\".                                            |\n"+
      "| This, of course, can only be done, when Utsonomiya-san    |\n"+
      "| is here.                                                  |\n"+
      "| YOU MUST EXCHANGE YOUR daito, shuto OR old ninja-to here. |\n"+
      "| THIS IS DONE BY STORING THE ITEM AND GETTING IT BACK !!!  |\n" +
      "+-----------------------------------------------------------+\n" );

   return( 1 );
}

search( arg )
{
   if ( !arg )
      return;
         
   write("You search and search, but find nothing special.\n");
   say(this_player()->query_name()+" searches around.\n");
   
   return( 1 );
}
