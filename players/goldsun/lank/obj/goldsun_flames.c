 /* some hot burning flames */
int    fire;
object who;
string KON, KOPOS;

reset( arg )
 {
   if ( arg )  return;
   fire = 0;
 }

id( str )
 {
   return( str == "_goldsun_flames_" );
 }

query_weight()
 {
   return( 0 );
 }

start_burning( w, v )
 {
   KON = w->query_name();
   KOPOS = w->query_possessive();
   fire = v;
   who = w;
   fire_hit();
 }

fire_hit()
 {
   string msg1, msg2;

  if (who->query_ghost())
   {
         fire=0;
	 tell_object( who, "You leave this horror place.\n");
	 transfer(who,"/players/goldsun/lank/room/coast4");
   }

  if ( fire > 0 ) {

      switch( random(5) ){
       case 0: msg1="Flames lick up from your shoes to your hair !";
	       msg2="Flames lick up from "+KON+"'s shoes to "+KOPOS+" hairs !";
	       break;	
       case 1: msg1="The heat of the fire takes your breath away !";
	       msg2=KON+" desperately tries to breath, but\n"
		+ "only smoke gets in "+KOPOS+" nostrils !";
	       break;	
       case 2: msg1="You feel like Satan has come to visit you !";
               msg2="Satan has come to visit "+KON+" !";
	       break;	
       case 3: msg1="You feel your left eyeball burst as a flame "
		+"burns your head !";
	       msg2=KON+" screams with horror as "+KOPOS+" left eyeball "
		+"burst\nlike a toad being blown up !";
	       break;
       case 4: msg1="Blister grow from your back as the flames shift\n"
		+"slowly from your back to your toes !";
	       msg2="Blister grow from "+KON+"'s back as the flames\n"
		+"shift slowly from "+KOPOS+" back to "+KOPOS+" toes !";
	       break;			
      }

      if ( fire > 20 ) {
        who->reduce_hit_point( 20 );
        say( msg2+"\n" );
        tell_object( who, msg1+"\n");
        fire -=20;
        call_out( "fire_hit", 2 );
      }
      else {
         who->reduce_hit_point( 20 );
         say( msg2+"\n" );
         tell_object( who, msg1+"\n");
         "/players/goldsun/lank/room/cottage"->end_fire();
	 transfer(who,"/players/goldsun/lank/room/coast4");
         destruct( this_object() );
      }
   }
   else {
      "/players/goldsun/lank/room/cottage"->end_fire();
      transfer(who,"/players/goldsun/lank/room/coast4");
      destruct( this_object() );
    }
}
