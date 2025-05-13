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
   object waki, wak, katana;

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
      wak= clone_object("/players/tatsuo/guild/nweap/wakizashi");
      wak->set_owner(TP->query_real_name());
      move_object(wak,TP);
     }    else if ( ob->id( "_ryu_head_" ) ) {
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
             "Utsunomiya-San hands you the mighty weapon.\n");
             

      OWNERS->add_kat_owner( TP->query_real_name() );
      destruct( ob );
      katana= clone_object("/players/tatsuo/guild/nweap/katana"); 
      katana->set_owner(TP->query_real_name());
      move_object(katana,TP);      }
   else {
      write( "Utsunomiya-San says: Thank you for your present, but I don't need it.\n" +
             "Utsunomiya-San mumbles something and the item vanishes !\n" );
      destruct( ob );
   }

   return( 1 );
}


 
