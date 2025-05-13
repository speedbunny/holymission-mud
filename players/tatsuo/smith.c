#define TO this_object()

inherit "/players/tatsuo/GenObj/mymonster";

#define TP         (this_player())
#define TPRN       TP->query_real_name()
#define OWNERS     "/players/tatsuo/guild/nweap/weap_owners"
#define WEAP_PATH  "/players/tatsuo/guild/nweap/"

object weapon;

reset( arg )
{
   ::reset( arg );
    
   if ( arg )
      return;
  
   set_name("Ujihiro Utsunomiya");
   set_alt_name("utsunomiya-san");
   set_alias("ujihiro utsunomiya");
   set_level( 55 );
   set_short("Ujihiro Utsunomiya");
   set_long( "This is Ujihiro Utsunomiya, the eremit. He is a very good smith, but\n" +
             "he had troubles with the civilisation, so he decided to live alone.\n" +
             "But he looks very friendly and is very high honoured.\n" );

   load_chat( 1,  ({ "Ujihiro Utsunomiya smiles in a very strange, but friendly kind.\n",
             }) );

   load_a_chat(20,
           ({ "Ujihiro Utsunomiya laughs at you.\n",
              "Ujihiro Utsonomiya says: You will suffer in pain, bastard.\n",
              "Ujihiro Utsonomiya spits at you.\n",
             }) );

   set_gender(1);
   set_no_fear();
   set_follow_chance(0);
   set_parry(10);
   set_n_ac( 15 );
   
   set_ninja();
   set_accuracy( 15 );

   weapon = clone_object( "/players/tatsuo/guild/nweap/sai" );
   transfer( weapon, this_object() );
   command( "wield sai" );
}

init()
{
   add_action( "kat_restore", "katana" );
   add_action( "waki_restore", "wakizashi" );
   add_action( "nt_restore", "ninja-to" );
   add_action( "rent", "store" );
}

kat_restore( arg )
{
   object weap;

   if ( OWNERS->is_kat_owner( TPRN ) ) {
      weap = clone_object( WEAP_PATH+"katana" );
      if ( transfer( weap, TP ) )
         write( "Utsonomiya-san says: You cannot carry any more !\n" );
      else {
         write( "Utsonomiya-san says: Here you are !\n" );
         write( "Utsonomiya-san gets a katana from the chest and gives it"+
                " to you !\n" );
         weap->set_owner( TP->query_real_name() );
      }
   }
   else 
      write( "Utsonomiya-san says: You have not gained a katana, fellow !\n" );

   return( 1 );
}

waki_restore( arg )
 
{
   object weap;

   if ( OWNERS->is_waki_owner( TPRN ) ) {
      weap = clone_object( WEAP_PATH+"wakizashi" );
      if ( transfer( weap, TP ) )
         write( "Utsonomiya-san says: You cannot carry any more !\n" );
      else {
         write( "Utsonomiya-san says: Here you are !\n" );
         write( "Utsonomiya-san gets a wakizashi from the chest and gives it"+
                " to you !\n" );
         weap->set_owner( TP->query_real_name() );
      }
   }
   else 
      write("Utsonomiya-san says: You have not gained a wakizashi, fellow !\n");
   return( 1 );
}

nt_restore( arg )
{
   object weap;

   if ( OWNERS->is_nt_owner( TPRN ) ) {
      weap = clone_object( WEAP_PATH+"ninja_ton" );
      if ( transfer( weap, TP ) )
         write( "Utsonomiya-san says: You cannot carry any more !\n" );
      else {
         write( "Utsonomiya-san says: Here you are !\n" );
         write( "Utsonomiya-san gets a Ninja-to from the chest and gives it"+
                " to you !\n" );
         weap->set_owner( TP->query_real_name() );
      }
   }
   else 
      write("Utsonomiya-san says: You have not gained a Ninja-to, fellow !\n");

   return( 1 );
}

rent( arg )
{
   object weap;

   if ( arg != "katana" && arg != "wakizashi" && arg != "ninja-to" )
   {
      write( "You can only store your katana, wakizashi or ninja-to here.\n" );
      return( 1 );
   }

   weap = present( arg, TP );
   if ( !weap )
      write("Utsonomiya-san says: You do not have a "+arg+", fellow !\n");
   else {
      if ( weap->query_owner() != TP->query_real_name() &&
           (arg == "katana" || arg == "wakizashi") ) {  
         write("Utsonomiya-san says: This is NOT your "+arg+", fellow !\n");
         write("Utsonomiya-san growls at you, makes a nifty move and gets\n");
         write("the "+arg+", securing it in the chest.\n" );
         destruct( weap );
         return( 1 );
      }
      write("Utsonomiya-san takes the "+arg+" from you and stores it in the"+
            "  chest.\n");
      transfer( weap, "/room/void" );
      destruct( weap );
   }

   return( 1 );
}

enter_inventory( ob )
{
   object waki;

   if ( TP->query_guild() != 8 ) {
      write( "Utsunomiya-San thanks you.\n" );
      destruct( ob );
      return( 1 );
   }

   if ( ob->id( "_onyx_ring_" ) ) {
     /* if ( ob->query_owner() != TP ) {
         write("Utsunomiya-San growls: Don't play tricks with me, you bastard !!!\n" +
         "Utsunomiya-San hits you very hard with his fist !!!\n" );
         TP->hit_player( 50 );
         this_object()->attack_object( TP );
         destruct( ob );
         return( 1 );
      }  */
      write( "Utsunomiya-San bows to you.\n\n" +
             "Utsunomiya-San says: Thank you for bringing me back my ring !!!\n\n" +
             "Utsunomiya-San goes to the amboss, takes some steel and begins to hammer.\n" +
             "Suddenly, with a blink of an eye, he is holding a wakizashi in his hands.\n"+
             "He stores the wakizashi in his secured chest and says to you:\n"+
             "You are now privileged to wield a wakizashi ! Just tell me, when you want it.\n");

      OWNERS->add_waki_owner( TP->query_real_name() );
      destruct( ob );
      move_object(clone_object("/players/tatsuo/guild/nweap/katana"),TP);  }
   else if ( ob->id( "_ryu_head_" ) ) {
    /*  if ( ob->query_owner() != TP ) {
         write( "Utsunomiya-San growls: Don't play tricks with me, you bastard !!!\n" +
         "Utsunomiya-San hits you very hard with his fist !!!\n" );
         TP->hit_player( 50 );
         this_object()->attack_object( TP );
         destruct( ob );
         return( 1 );
      } */



      write( "Utsunomiya-San bows to you.\n\n" +
             "Utsunomiya-San says: You have slayed it, congratulations !!!\n"+
             "Utsunomiya-San goes to the amboss, takes some steel and begins to hammer.\n" +
             "Suddenly, with a blink of an eye, he is holding a katana in his hands.\n"+
             "He stores the katana in his secured chest and says to you:\n"+
             "You are now privileged to wield a katana ! Just tell me, when you want it.\n");

      OWNERS->add_kat_owner( TP->query_real_name() );
      destruct( ob );
      move_object(clone_object("/players/tatsuo/guild/nweap/wakizashi"),TP);   }
   else {
      write( "Utsunomiya-San says: Thank you for your present, but I don't need it.\n" +
             "Utsunomiya-San mumbles something and the item vanishes !\n" );
      destruct( ob );
   }

   return( 1 );
}

/* ----- the info-function ----------------------------------------------- */
catch_tell( arg )
{
   string *words, x;
   int i;
   
   if ( !arg )
      return;
      
   sscanf( arg, "%s says: %s\n", x, arg );
   words = explode( arg, " " );
   
   if ( words && sizeof( words ) ) {
      i = 0;
      while ( i < sizeof( words ) ) {
         if ( words[i] == "wakizashi" ) {
            write( "Utsunomiya-San says: You want to have a wakizashi. Oh, therefor you have\n" +
                   "   to know, that you won't just get a wakizashi easily from me. You have\n" +
                   "   to prove, that you are worth getting one.\n" +
                   "   So do me the following favour, and I, Ujihiro Utsunomiya, will make you\n" +
                   "   the best wkizashi, I have ever made for a mortal.\n\n" +
                   "Ujihiro Utsunomiya closes his old eyes. Is he thinking ?\n\n" );
            call_out( "waki", 50, this_player() );
         }
         else if ( words[i] == "katana" ) {
            write( "Utsunomiya-San says: It is the reward for the head of "+
                   "the ryu!\n" );
         }

         i++;
      }
   }
   else
      write( "Utsunomiya-San looks confused.\n" );

   return( 1 );
}


waki( player )
{
   if ( present( player, environment( this_object() ) ) ) {
      write( "Ujihiro Utsunomiya opens his eyes and looks at you. He seems to be a little\n" +
             "   bit confused and disoriented.\n" +
             
"He says: Who are you ? .... Aren't you the one, who asked me about a wakizashi.\n" +
             "   Yes, I remember, I asked you for a favour. Well, here it is.\n\n" );
   /*   call_out( "waki1", 30, player ); */

   }
}
/*
waki1( player )
{ 
   if ( present( player, environment( this_object() ) ) ) { 
      write( "Ujihiro Utsunomiya says: I am sure, you know the volcano on Ezo and the huge\n" +
             "   cave-system in it. Long time ago I was in it, searching a Mujina, who\n" +
             "   brought a lot of pain over Ezo. I weared my magic ring, which is a very,\n" +
             "   very powerful and strong ......\n\n" +
             "Suddenly Ujihiro Utsunomiya interrupts and looks hard at you.\n\n" );
      call_out( "waki2", 40, player );
   }
}

waki2( player )
{
   if ( present( player, environment( this_object() ) ) ) {
      write( "Ujihiro Utsunomiya says: Forget, what I have told you about the ring. It does\n" +}

waki4( player )
{
   if ( present( player, environment( this_object() ) ) ) {
      write( "Ujihiro Utsunomiya has calm down and says with his friendly voice:\n" +
             "   I hope, that Ameratsu will be at your side and remember: Run away, if\n" +
             "   the Mujina starts to unmask itself. Few has survived to describe the\n" +
             "   evil looking of the face, but these has turned insane, brumble like\n" +
             "   childrens and shiver in pain, if they only hear the name Mujina !\n\n" );
      call_out( "waki5", 30, player );
             "   not affect this story. But your business is, to bring me back my long lost\n" 
             "   ring and I will make the wakizashi for you.\n\n" )
      call_out( "waki3", 40, player )
   
waki3( player 
   if ( present( player, environment( this_object() ) ) ) 
      write( "Ujihiro Utsunomiya looks very sharp at you and says in a rough voice:\n" 
             "   But never wear this ring ! It is much too powerful for you and you are\n" 
             "   too young for meeting all the heros in the Nirvana. Never wear it !!!\n\n" )
      call_out( "waki4", 40, player )
   
   
waki5( player 
   if ( present( player, environment( this_object() ) ) ) 
      write( "Ujihiro Utsunomiya says:\n" 
             "   And now leave me, Ninja, make your own way.\n\n" 
             "Ujihiro Utsunomiya sits down, closes his eyes and starts meditating.\n\n" )
   
*/
