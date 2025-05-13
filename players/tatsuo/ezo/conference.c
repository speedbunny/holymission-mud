#define PPATH "/players/tatsuo/ezo/"
#define FILE  "/players/tatsuo/ezo/fconference"
#define GUILD_ROOM "/players/tatsuo/guild/room"
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#include "/players/tatsuo/guild/ndef.h"
#define SAN_LEVEL 20

inherit "room/room";
object board;
reset(arg) {
   if(arg) return;
   transfer(clone_object("/boards/guilds/ninja_guild_san"),this_object());
   set_light(1);
   short_desc = "Conference room";
   long_desc = 
      "This is the conference room in the residence of Matsumae Yoshihiro,\n"+
      "the evil Shogun of the island of Ezo. Only ninja sans are allowed to\n"+
      "be here. In the middle of the room is a large table, with cushions\n" +
      "arranged around it. At the northern wall is a sign.\n";
   items=({
	"chamber", long_desc,
        "floor", "The floor is made of wood",
        "walls", "The walls are made of wood",
        "wall", "The wall is made of wood and there is a board on it",
        "wood","It is teak",
        "table", "A large, long table",
        "cushions", "They look soft and inviting, you want to sit down",
        "sign", "@@query_sign@@",
   });
   smell = "You smell the odor of wood.";
   dest_dir=({  PPATH + "atShogun","down", });
}

init() {
   ::init( );
   add_action( "do_accept", "accept" );
   add_action( "do_banish", "banish" );
   add_action( "do_disp", "display" );
   add_action( "do_read", "read" );
}

do_read(arg) {
   if ( !arg || arg != "sign" )
      return( 0 );
   write( query_sign() + ".\n" );
   return( 1 );
}

do_accept(arg) {
   if ( TP->query_guild() != 8 )
      write( "You have to be a ninja to do this !\n" );
   else if ( TP->query_level() < 20 )
      write( "Only Sans are allowed to do this !\n" );
   else if ( !arg )
      write("You have to accept a player.\n");
   else {
      if ( FILE->do_accept( TP, lower_case( arg ) ) ) {   
         write("You just have allowed "+capitalize(arg)+" to join the ninjas"+
                ".\n" );
         say( TP->query_name() + " just allowed " + capitalize(arg) + 
              "to join the ninjas.\n" );
      }
      else
         write( "Something gone wrong !\n" );
   }
   return( 1 );
}

do_banish(arg) {
   string whom, why;
   if ( TP->query_guild() != 8 )
      write( "You have to be a ninja to do this !\n" );
   else if ( TP->query_level() < SAN_LEVEL )
      write( "Only Sans are allowed to do this !\n" );
   else if ( !arg )
      write("You have to banish a player for a reason.\n");
   else if ( sscanf( arg, "%s for %s", whom, why ) != 2 )
      write( "Error in the argument !\n" );
   else if ( strlen( why ) > 40 )
      write( "Reason too long. Aborted.\n" );
   else if ( !why || !strlen( why ) )
      write( "No reason given, aborted.\n" );
   else if ( !find_player(whom) )
      write( "This player is not online right now or invisible.\n"+
             "You have to wait until (s)he becomes visible logs on again.\n");
   else {
      if ( FILE->do_banish(TP, lower_case(whom), why) ) {   
         write("You just have banished "+capitalize(whom)+" because of "+
                why + ".\n" );
         say( TP->query_name() + " just banished " + capitalize(whom) + 
              " because of " + why + ".\n" );
         tell_object( find_player(whom),
                      "--------------------------------------------------\n"+
                      TPN+" just banished you from the guild !!!!!!\n"+
                      "Type \"help banished\" for more info about this.\n"+
                      "--------------------------------------------------\n" );
         GUILD_ROOM->commune_ninja(
                      "--------------------------------------------------\n"+
                      TPN+" just banished "+capitalize(whom)+" from the guild"+
                      " !!!!!\n"+
                      "--------------------------------------------------\n" );
      }
      else
         write( "Something gone wrong !\n" );
   }
   return( 1 );
}

do_disp(arg) {
   mixed *arr;
   int   i, j;
   string who, why;
   if ( arg == "accepted" ) {
      arr = FILE->query_accepted();
      if ( !arr )
         write( "There ain't any players accepted now.\n" );
      else {
         write( left_align("player",15)+left_align("who accepted",15) );
         write( left_align("player",15)+left_align("who accepted",15) + "\n");
        write("------------------------------------------------------------\n");         for ( i = 0; i < sizeof( arr[0] ); i++ ) {
            write( left_align(arr[0][i],15) + left_align(arr[1][i],15) );
            if ( (i%2) ) write( "\n" );
         }
         if ( (i%2) ) write( "\n" );
        write("------------------------------------------------------------\n");
      } 
   }
   else if ( arg == "banished" ) {
      arr = FILE->query_permitted();
      if ( !arr )
         write( "There aren't any players banished now.\n" );
      else {
         write( left_align("player",15)+left_align("who banished",15)+
                left_align("why banished",40) +"\n" );
         write("------------------------------" +
               "----------------------------------------\n"); 
         for ( i = 0; i < sizeof( arr[0] ); i++ ) {
            write( left_align(arr[0][i],15) );
            who = explode( arr[1][i], "#" );
            why = explode( arr[2][i], "#" );
            if ( !(who && sizeof(who)) )
               write( "BUG, please mail your guild-master.\n" );
            else {
               write( left_align(who[0],15) + left_align(why[0],40) + "\n" );
               for ( j = 1; j < sizeof( who ); j++ ) {
                  if ( who[j] && why[j] && strlen(who[j]) && strlen(why[j]) )
                     write( left_align( "", 15 ) +
                         left_align(who[j],15) + left_align(why[j],40) + "\n" );
               }
            }
         }
         write("------------------------------" +
               "----------------------------------------\n"); 
      } 
   }
   else
      write( "Display what ?\n" );
   return( 1 );
}

do_sit(arg) {
   if ( arg == "down" ) {
      write( "You take place at one of the cushions.\n" );
      say( TP->query_name() + " takes place at one of the cushions.\n" );
   }
   else if ( arg == "table" || arg == "at table" || arg == "down at table" ) {
      if ( TP->query_real_name() == "tatsuo" ) {
         write( "You sit down on the table.\n" );
         say( "Tatsuo sits down on the table.\n" );
      }
      else
         write( "You don't dare to sit at Tatsuo's place !!!\n" );
   }
   return( 1 );
}

query_sign() {
   return( 
       "You can do the following things here:\n\n" +
       "\"accept <player>\":\n"+
       "   If a player wants to join the ninja-guild, at least one of the\n"+
       "   Sans have to accept this player. You can do this here.\n\n" +
       "\"banish <player> for <reason>\":\n"+
       "   This gives you the possibility, to lock a player out of the guild.\n"
     + "   You can do this before the player joins the guild (then it is\n" +
       "   impossible for him/her to join) or when the player already belongs\n"
     + "   to us (this will kick him/her out then). You need three Sans,\n"+
       "   who must banish the player.\n"+
       "   Also you must give a reason (up to 40 char).\n" +
       "   NOTE: Once a player is banished, there is no way back !!!!!\n" +
       "         This should force you think about this drastic step.\n" +
       "         I WILL DEAL HARSHLY WITH PEOPLE MISUSING THIS COMMAND!!\n"+
       "         It was invented for sanctioning players, who are betraying\n"+
       "         the guild, annoying members or perform other violent acts\n"+
       "         against the guild. Do not misuse it for flames or other\n"+
       "         personal reasons !!!\n"+
       "         I promise you, you will not like the sanctions at all I\n"+
       "         will lay upon you if I discover any misuse. And I, of\n"+
       "         course, can take back banishment and will do so, it it is\n"+
       "         unjustyfied !\n\n"+
       "\"display accepted|banished\":\n" +
       "    You can look at the accepted|banished - list" );
}

left_align(str,w) {
   str += "                                               ";
   w--;
   return( str[0..w] );
}
