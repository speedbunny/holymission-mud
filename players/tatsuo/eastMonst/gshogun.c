#define TO this_object()
inherit "/players/tatsuo/GenObj/mymonster";
#define TP     (this_player())

object weapon;

reset( arg )
{
   ::reset( arg );
    
   if ( arg )
      return;
  
   set_name("Matsumae Yoshihiro");
   set_alt_name("yoshihiro-san");
   set_alias("matsumae yoshihiro");
   set_level( 72 );
   set_short("Matsumae Yoshihiro");
   set_long( "His is Matsumae Yoshihiro, the Shogun of the island of Ezo.\n" +
             "He is dressed in a black kimono with golden ornaments, which shows\n" +
             "evil ryus. He sits on this throne and looks very unfriendly at you.\n"+
             "But maybe you can ask him about something !?\n" );

   load_chat( 3,  ({ "Matsumae Yoshihiro says: Why do you disturb me, ninja ?\n",
                     "Matsumae Yoshihiro growls at you.\n",
                     "Matsumae Yoshihiro raises his left eye-brow.\n",
             }) );

   load_a_chat(20,
           ({ "Matsumae Yoshihiro laughs at you.\n",
              "Matsumae Yoshihiro says: You will suffer in pain, bastard.\n",
              "Matsumae Yoshihiro spits at you.\n",
             }) );

   set_gender(1);
   set_no_fear();
   set_follow_chance(0);
   set_parry(20);
   set_n_ac( 0 );
   
   set_ninja();
   set_accuracy( 20 );

}

init( )
{
   ::init();

   add_action( "ask_him", "ask" );
   add_action( "do_show", "show" );
}

/* ----- the info-function ----------------------------------------------- */
ask_him( arg )
{
   string *words, x;
   int i;
   
   if ( !arg )
      return( 0 );
   arg += " ";

   if ( TP->speaks_in() != 1 ) {
      write( "Yoshihiro-San looks at you, seemingly understanding not a "+
             "single word !\n" );
      return( 1 );
   }
   
   words = explode( arg, " " );
   
   if ( words && sizeof( words ) ) {
      i = 0;
      while ( i < sizeof( words ) ) {
         if ( words[i] == "dart" || words[i] == "darts" 
              || words[i] == "poison-dart" ) {
            write( "Yoshihiro-San says: Well, I've heard something about "+
                   "these poison-darts.\n" +
                   "   These are very powerful weapons. As far as i can "+
                   "remember, you need some\n" +
                   "   bark of a birch and some fugu for the production. "+
                   "But you only can create\n" +
                   "   the poison at a holy place. But I've forgotten the" +
                   " spell, which you need.\n" +
                   "   Maybe ask someone, who is more confident with " +
                   "religious behaviours.\n" ); 
            return(1);
         }
         else if ( words[i] == "blind" || words[i] == "blinding" ||
              words[i] == "blinding-egg" || words[i] == "blind-egg" ||
              words[i] == "blinding-eggs" ) {
            write( "Yoshihiro-San says: The blinding egg !! "+
                   "You don't know something of it.\n" +
                   "   Well, that's not good for you. When I was "+
                   "young and travelled around\n" +
                   "   fighting, it helped me a lot. And it is "+
                   "very easy to obtain. You just\n" +
                   "   need some fluorescent liquid as in the fountain "+
                   "of my residence and\n" +
                   "   some moss, which grows here on Ezo. "+
                   "Put these two things in an egg and\n" +
                   "   mumble these holy words: \"takayoto ai gemosa\". "+
                   "But I'm really suprised\n" +
                   "   that you don't know something about this !\n\n" );
            write( "Yoshihiro-San shakes his head and looks at you.\n" +
                   "You feel very small and unexperienced and your "+
                   "cheeks are burning.\n" );
            return( 1 );
         }
         else if ( words[i] == "blood" || words[i] == "blood-egg" 
                   || words[i] == "blood-eggs" )
         {
            write( "Yoshihiro-San says: Oh, I heard of that egg. "+
                   "It is very usefull for\n" +
                   "   groups of monsters. But I never found out, "+
                   "how it works.\n\n" +
                   "   But wait, I remember a very old and wise traveller, "+
                   "who told me\n" +
                   "   something about an almond tree here in this crater, "+
                   "as I asked him\n" +
                   "   about the blood-egg. I think, "+
                   "I should go to the tree soon and check\n" +
                   "   out, what he has meant.\n" );
            return( 1 );
         }          
         else if ( words[i] == "egg" || words[i]=="'egg'" || words[i]=="eggs") {
            write( "Yoshihiro-San says: Our beloved egg. Well, I'm "+
                   "sure it is one of the best\n" +
                   "   things, a ninja can use in combat. "+
                   "And there are various kinds of eggs,\n" +
                   "   such as blood-eggs, blinding-eggs and pepper-bombs.\n" );
            return( 1 );
         } 
         else if ( words[i] == "wakizashi" ) {
            write( "Yoshihiro-San says: Many has changed in the world, "+
                   "since I have earned the\n" +
                   "   shuto. But I think, you still can get "+
                   "it from the eremit of Ezo.\n" +
                   "   He lives at the southernmost end of Ezo. "+
                   "Ask him about the shuto,\n" +
                   "   I'm sure that he can tell you more than I can.\n" );
            return( 1 );
         } 
         else if ( words[i] == "blood" ) {
            write( "Yoshihiro-San says: Ask me about the egg " +
                   "and I can tell you more.\n" );
            return( 1 );
         }
         else if ( words[i] == "fugu"|| words[i] == "moss" ) {
            write( "Yoshihiro-San says: Ask me about the dart " +
                   "and I can tell you more.\n" );
            return( 1 );
         }
         else if ( words[i] == "ki" || words[i] == "kis" ) {
            if (TP->query_religion()!="ZEN" &&
                TP->query_religion()!="Amaterasu" )
            write( "Yoshihiro-San says: Well, you can raise your kis "+
                   "here, it you want.\n" +
                   "Just type \"help raise\" to get more info.\n" ); 
            else
               write("Yoshihiro-San says: Well, the kis are very important.\n");
            return( 1 );
         }
         else if ( words[i] == "katana" ) {
            write( "Yoshihiro-San says:\nWell, I have earned the daito by "+
                   "slaying the demonic ryu,\n"+
                   "who was messing around here in Ezo.\nBut I have learned, "+
                   "that a ryu is again here at Ezo.\n" +
                   "I'm sure, when you slay it and bring the head to the "+
                   "eremit of Ezo, he will\n" +
                   "make you one of these powerful weapons.\n" +
                   "But be careful, the ryu is really strong and DON'T forget"+
                   " to behead it !!!\n\n" +
                   "So, fellow, choose your fate !\n\n" ); 
            return( 1 );
         }
         else if ( words[i]=="pepper" || words[i]=="bomb" || 
                   words[i] == "pepper-bomb" || words[i] == "pepper bomb" ) {
            write( "Yoshihiro-San says:\n"+
                   "Ah, the pepper bomb. I love this egg, it is gorgeous !\n"+
                   "All these creatures start whining and sneezing \n"+
                   "and even fumbling, missing you all the time. "+
                   "And they are soo clumsy then !\nBut you must take the "+
                   "right dose and mixture that this affect occurs.\n"+
                   "I will always be grateful to Sushi-San for this idea !\n"+
                   "Yoshihiro-San smiles from ear to ear ...\n" );
             return( 1 );
         }

         i++;
      }
   }

   write( "Yoshihiro-San says: You can ask me about the folling topics:\n" +
          "   darts, poison-darts, blinding-eggs, blood-eggs, blood, fugu,\n"+
          "   moss, kis and some weapons.\n" );

   return( 1 );
}

do_show( string arg )
{
   if ( !arg ) {
      write( "Show what to whom ?\n" );
   }
   else if ( !(arg == "parchment to yoshihiro-san" || 
        arg == "parchment to Yoshihiro-san") )
   {
       write( "Yoshihiro-san ignores you. Have you used the right title ?\n" );
   }
   else {
      if ( present( "unreadable_ninja_parch", this_player() ) ) {
         write( "Yoshihrio-san says in nihonese: Very ancient runes indeed and I cannot\nunderstand them. Maybe you should show it to Hudriwudri-san.\n" );
         say( "Yoshihrio-san says in nihonese: Very ancient runes indeed and I cannot\n   understand them. Maybe you should show it to Hudriwudri-san.\n" );
      }
      else {
         write( "Yoshihiro-san ignores you. Have you used the right title ?\n" );
      }
   }
   return( 1 );
}
