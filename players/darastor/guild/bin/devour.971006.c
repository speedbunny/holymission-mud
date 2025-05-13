// 6-5-97 Kryll - changed to check for some kind of eat_food and
//                lowered the healing slightly

/*=========================================================================
	BARBARIAN'S DEVOUR CORPSE --- ie. heal
=========================================================================*/

#include "/players/darastor/guild/barb.h"

int main( string str ) {

   int     amt;
   object ob;

   if( str != "corpse" ) {
	write( "What do you want to devour?!?\n" );
	return 1;
   }

   ob = present( "corpse", environment( TP ) );
   if( !ob ) ob = present( "corpse", TP );
   if( !ob ) {
	write("There isn't a corpse to devour!\n");
	return 1;
   }

/*
   TP->heal_self( (int)ob->query_weight()*5 );
*/
   amt = (int)ob->query_weight() * 3;
   if(TP->eat_food(amt/6)) {
      TP->heal_self(amt/2 + random(amt));
   write("You devour the corpse in one gulp.\n");
   say( TP->NAME + " devours the corpse in one gulp, spilling blood and " +
	"entrails \neverywhere. You feel quite disgusted at the frankly " +
	"rather grisly sight.\n" );

   destruct( ob );

   call_out( "burp", 4 + random( 10 ), 0 );
   }

   return 1;

}

