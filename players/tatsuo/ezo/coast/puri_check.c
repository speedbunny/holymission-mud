inherit "obj/treasure";

#define  TP    (this_player())
#define GM        "guild/master"

int hands_washed, mouth_rinsed, is_medi;

reset( arg )
{
   ::reset( arg );

   name = "puri_check";
}

init()
{
   ::init();

   add_action( "do_nothing", "", 1 );
   add_action( "do_wakeup", "wakeup" );
   add_action( "do_concen", "concentrate" );
}

set_hands_washed()     { hands_washed = 1; }
query_hands_washed()   { return( hands_washed ); }
set_mouth_rinsed()     { mouth_rinsed = 1; }
query_mouth_rinsed()   { return( mouth_rinsed ); }

start_meditate()
{ 
   is_medi = 1;
   add_action( "do_nothing", "", 1 );
   add_action( "do_wakeup", "wakeup" );
   write( "You are one now with the void and can <concentrate> on the deities.\n" );

   move_object( this_object(), environment( this_object() ) );
}

do_wakeup()
{
   if ( !is_medi )
      return;

   write( "You stop meditating and stand up.\n" );
   say( TP->query_name() + " stops meditating and stands up.\n" );

   is_medi = 0;
   return( 1 );
}

do_concen( arg )
{
   if ( !arg ) {
      write( "You can concentrate on the following Shinto deities:\n" +
             "  Amaterasu    - Ruling Deity, Sun God\n" +
             "  Susano-O     - Storm God, Underworld God, Trickster God\n" +
             "  Hachiman     - War God\n" +
             "  O-kuni-nushi - Earth God\n" );
   }
   if ( TP->query_religion() != "Amaterasu" ) {
     if ( arg == "on Amaterasu" || arg == "on amaterasu" )
        write( "You concentrate on Amaterasu ...\n\n"+
               "Suddenly you think, you should find some almonds and\n" + 
               "\"sacrifice\" them here.\n" );
     else 
        write( "Before you can do this, you have to believe in Amaterasu.\n" );
     return( 1 );
   } 
   if ( arg == "on Amaterasu" || arg == "on amaterasu" ) {
      write( "You concentrate on Amaterasu ...\n" +
             "You think, that you should \""+
             "concentrate on Amaterasu about spells\".\n" );
   }
   else if ( arg == "on Amaterasu about spells" ||
             arg == "on amaterasu about spells" ) {
      write( "You concentrate on Amaterasu about spells...\n" +
             "Suddenly you can see a scroll levitating in front of you.\n" +
             "Written on the scroll, with ancient letters, is the following:\n"+
             "\n"+
      "Spell          Teacher      Effectivness      Exhaustion  Learning\n"+
      "------------------------------------------------------------------\n"+
      "Fireshuriken   Hachiman     medium (single)   low         very easy\n"+
      "Summon wind    Susano-O     medium (group)    high        easy\n"+
      "Earthgrip      O-kuni-nushi variable (single) medium      medium\n" +
      "Freeze         O-kuni-nushi variable (single) high        high\n\n"+
      "You can \"concentrate on <teacher> about <spell>\" to get more info.\n"+
      "You also can \"concentrate on <teacher> to learn <spell>\"\n" +
      "\nSuddenly, the scroll disappears.\n\n" );
   }
   else if ( arg == "on susano-o" || arg == "on susano-O" || 
             arg == "on Susano-O" ) {
      if ( TP->query_ghost() && TP->query_religion() == "Amaterasu" ) {
         write( "You concentrate on Susano-O ...\n" +
                "Suddenly you feel new life floating into you.\n" );
         TP->remove_ghost();
      }
      else
         write( "You concentrate on Susano-O ...\n" +
                "But nothing happens.\n" );
   }
   else if ( arg == "on susano-o about summon wind" ||
             arg == "on Susano-O about sommon wind" ) {
      write( "You concentrate on Susano-O about Summon Wind...\n\n"+
             "Suddenly you have the following vision:\n"+
             "You can see a sorcerer with a lot of orcs in a room.\n"
           + "The sorcerer raises his hands and all of a sudden a heavy storm\n"
           + "begins to blow and smashes all enemies to the ground.\n\n" +
             "You think, that you will have sacrifice a bit exp for this "+
             "spell\n\n" );
   }
   else if ( arg == "on Susano-O to learn summon wind" ||
             arg == "on susano-o to learn summon wind" )
   {
      write( "This spell has been removed !\n" );
   }
   else if ( arg == "on Hachiman" || arg == "on hachiman" ) {
      write( "You concentrate on Hachiman ...\n" +
             "You feel Hachiman smiling.\n" );
   }
   else if ( arg == "on Hachiman about fireshuriken" ||
             arg == "on hachiman about fireshuriken" ) {
      write( "You concentrate on Hachiman ...\n\n" +
             "Suddenly you have the following vision:\n" +
             "You see a sorcerer standing in front of an evil gaki.\n" +
             "She points to the gaki. Suddenly her hand begins to glow and\n" +
             "a shuriken, made of fire, shots out of her hand and smashes\n" +
             "the head of the gaki.\n\n" ); 
   }
   else if ( arg == "on Hachiman to learn fireshuriken" ||
             arg == "on hachiman to learn fireshuriken" )
   {
      write( "This spell has been removed !\n" );
   }
   else if ( arg == "on o-kuni-nushi" || arg == "on O-kuni-nushi" )
      write( "You concentrate on O-kuni-nushi ...\n\n" +
             "You feel the earth move under your feet !\n" );
   else if ( arg == "on o-kuni-nushi about earthgrip" ||
             arg == "on O-kuni-nushi about earthgrip" )
      write( "You concentrate on O-kuni-nushi ...\n\n" +
             "Suddenly you have the following vision:\n" +
             "You see a sorcerer concentrating himself. Suddenly the earth\n"+
             "around his opponent begins to soften and quickly hardens again.\n"
           + "His enemy is trapped in the earth !!!\n\n" +
             "You think, that you will have to sacrifice some exp for this "+
             "spell.\n\n" );
   else if ( arg == "on o-kuni-nushi to learn earthgrip" ||
             arg == "on O-kuni-nushi to learn earthgrip" )
   {
      write( "This spell has been removed !\n" );
   }
   else if ( arg == "on o-kuni-nushi about freeze" ||
             arg == "on O-kuni-nushi about freeze" )
      write( "You concentrate on O-kuni-nushi ...\n\n" +
             "Suddenly you have the following vision:\n" +
             "You see a sorcerer pointing with her open hands at an mukade.\n"+
             "Suddenly a blue globe shots out of her hands on the mukade and\n"+
             "turns it into a statue of ice !!!\n\n"+ 
             "You think, that you will have to sacrifice a lot of exp for this"
             +" spell.\n\n");
   else if ( arg == "on o-kuni-nushi to learn freeze" ||
             arg == "on O-kuni-nushi to learn freeze" )
   {
      write( "This spell has been removed !\n" );
   }
 
   return( 1 );
}

do_nothing( arg )
{
   if ( is_medi ) {
      write( "You cannot do this while being one with the void!\n" );
      return( 1 );
   }
}

write_learn_fs()
{
   write( "You concentrate on Hachiman ...\n\n" +
          "Suddenly you can see the air around you beginning to shimmer\n"+
          "in a bright reddish color and drifting into you !!!\n\n" +
          "You fall flat down and feel very exhausted.\n\n" +
          "Then the air around you looks normal again.\n\n" );
} 

write_learn_sw()
{
   write( "You concentrate on Susano-O ...\n\n" +
          "Suddenly the air around you begins to move and floating into\n" +
          "you. You feel the air pressing you down at the ground.\n\n" +
          "After the air has calmed down again, you feel better, but\n" +
          "somehow less experienced.\n" );
}

write_learn_eg()
{
   write( "You concentrate on O-kuni-nushi ...\n\n" +
          "Suddenly the earth around you begins to soften and harden again.\n" +
          "But fortunately you are in a spherical state, so it doen't affect\n"+
          "you.\n\n" +
          "You feel less experienced.\n" );
}

write_learn_f()
{
   write( "You concentrate on O-kuni-nushi ...\n\n" +
          "Suddenly the air around you gets colder and shimmers in a blue\n" +
          "faint. Then it floats into you. You are knocked down at the floor"+
          " !!!\n\nYou feel very exhausted and less experienced.\n" ); 
}
