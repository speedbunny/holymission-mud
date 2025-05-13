/* Elephant Ring */
/* Gorlin 12.9.96 */

inherit "obj/armour";

reset ( arg ) {
   ::reset ( arg );
   if ( !arg ) {
      set_name("ring");
      set_short("A golden ring");
      set_long(
"A simple, unadorned golden ring... at least that's what you see at the\n" +
"first look. Continued examination results in discovering an inscription\n" +
"on the inside of the ring: 'rtrumpet' ???\n");
      set_weight(0);
      set_value(0);
      set_ac(0);
      set_type("ring");
   }
   return;
}

drop() {
   write("As you drop the ring it vanishes in a flash of light.\n");
   destruct( this_object() );
   return 1;
}

init()
{
   add_action("trumpet_to","rtrumpet");
}

trumpet_to(str)
{
   if (str=="all") {
      lshout("trumpets out loud.","\n",this_player() );
      write("You trumpet out loud, all the mud can hear!\n");
   }
   else {
      ltell( find_living( str ),"trumpets out to you.","\n",this_player() );
      write("You trumpet to "+ capitalize( str ) +".\n");
   }
   return 1;
}


