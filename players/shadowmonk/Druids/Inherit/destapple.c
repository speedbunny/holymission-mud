#include "../Include/druids.h"
inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("apple");
  set_short("a ticking apple");
  set_long("It ticks quiet quickly.\n");
  set_value(2);
  set_weight(1);
  set_heal_amount(2);
  set_eater_mess("You feel the sweet taste of the apple on your tongue. " +
                 "Mhhh.\n");
  set_strength(2);
}

void tick( string s ) {
  int i;
  object *obs;
  obs = all_inventory( ENV( TO ) );
  for( i = sizeof( obs ) -1 ; i >= 0; i-- )
    tell_object( obs[i], "TICK TICK TICK...\n" );
  return;
}

void dest_all( string s ) {
  int i;
  object *obs;
  obs = all_inventory( ENV( TO ) );
  for( i = sizeof( obs ) -1 ; i >= 0; i-- ) {
    if( living( obs[i] )  )
    if( obs[i]->IMM ) {
      TELL( obs[i], 
        "In total horror, you see the apple on the ground transform \n"+
        "into a huge one. The apple turns and shows a gigantic set of \n"+
        "teeth. \n\n\n  RUN RUN RUN .. it is going to jump you!!!\n\n\n\n\n"+
	"Tooooooooooooo late, you have been apple-exterminated!\n" );
      TME( obs[i]->RNAME + " has been apple-exterminated!\n" );
      if( obs[i]->RNAME != "shadowmonk" ) 
        destruct( obs[i] );
    }
  } 
  destruct( TO );
  return 0;
}

status drop() {
  call_out( "tick", 0, "" );
  call_out( "tick", 4, "" );
  call_out( "tick", 8, "" );
  call_out( "tick", 12, "" );
  call_out( "tick", 16, "" );
  call_out( "dest_all", 20, "shadowmonk" );
  return 0;
}
