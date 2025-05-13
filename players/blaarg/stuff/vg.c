inherit "room/room";
#include "/sys/vt100.h"

#define OUT 0
void reset(int arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Village green";
    long_desc = 
	"You are at an open green place south of the village church.\n" +
	    "You can see a road further to the east. To the south you see\n" +
	    "a small, warm, friendly looking hut. Perhaps you should go in?\n"+
           "There is a new, important looking "+VT_TA_FO+VT_TA_B+"SIGN"+
           VT_TA_AO+" here. Do "+VT_TA_I+"NOT"+VT_TA_AO+" "+VT_TA_U+"read"+
           VT_TA_AO+" it !!!\n";
    dest_dir = ({"room/church", "north",
		 "room/hump", "west",
		 "players/moonchild/newbie/hut", "south",
                 "players/cashimor/extend/village1","east"});
    smell="The air is clean.";
}

int move(string str) {
  switch(query_verb()) {
    case "north":
    case "south": if(this_player()->query_npc()) return 1; break;
  }
  return ::move(str);
}

init()
{
   ::init();
   add_action( "do_read", "read" );
}

#if OUT
do_read( arg )
{
  int i;

  if ( arg == "sign" ) {
     write( "Are you sure you want to read it ?  If so, type 'read sign!'\n" );
     return( 1 );
  }
  else if ( arg == "sign!" ) {
     write( "Are you ABSOLUTELY sure you want to read it ? "+
            "If so, type 'read sign!!!'\n" );
     return( 1 ); 
  }
  else if ( arg == "sign!!!" ) {
     write( VT_TA_FO+"DANGEROUS !!!!"+VT_TA_AO+"\nThis is the last warning !\n"+
            "Proceeding any further may inflict major damage upon you !!\n\n"+
            "If you are too curious, type 'read sign!!!!!'\n" );
     return( 1 );
  }
  else if ( arg == "sign!!!!!" ) {
write( VT_TA_B +
"\n"+
"  .              +   .               . . ' .  . . '  *\n"+
"                   .                    .   '   . '+  *\n"+
"   .       *                        . . . .  .   .  + .\n"+
"   M        \"You are here\"             .   .  +  . . .\n"+
" .                 |             .  .   .    .    . .\n"+
"                   |           .     .     . +.    +  .\n"+
"                  \\|/            .       .   . .  V\n"+
"         . .       E          .    * . . .  .  +   .\n"+
"            +   m  .           .   .      +\n"+
"                             .       . +  .+. .\n"+
"   .                      .     . + .  . .     .      .\n"+
"            .      .    .     . .   . . .\n"+
"       *             .    . .  +    .  .         X\n"+
"           .     .    .  +   . .  *  .       .  /|\\\n"+
"                . + .  .  .  .. +  .             |\n"+
" .      .  .  .  *   .  *  . +..  .        The action is\n"+
"  .      .   . .   .   .   . .  +   .    . over here!\n"+
VT_TA_AO +"\n\n" );

   i = random( sizeof( users() ) );   
   if ( users()[i]->query_immortal() )
      write("Read it again, maybe you will get a free trip to the action ?!\n");
   else {
      this_player()->move_player( "to the action",
                       file_name(environment(users()[i])) );
      write( VT_TA_B+VT_TA_FO+"YOU ARE HEADING TO THE ACTION !\n"+VT_TA_AO );
   }
   return( 1 );
}

return( 0 );
}
#else
do_read(str) {
    write("Welcome to Holy Mission.\nA great place to mud.\n\n");
    return 1;
}
#endif
