#define TO this_object()

inherit "/players/tatsuo/GenObj/mymonster";

object weapon;

reset( arg )
{
   ::reset( arg );
    
   if ( arg )
      return;
  
   set_name("Miyamoto Makimura");
   set_alt_name("makimura-san");
   set_alias("miyamoto makimura");
   set_level( 30 );
   set_short("Miyamoto Makimura");
   set_long( "This is Miyamoto Makimura. He is wearing a brown kimono with golden\n" +
             "symbols on it. You see, that one of the symbols is the letter for Tao.\n" +
             "He sits on the floor and take care, that noone steal something from the\n" +
             "shelf. But maybe you can trade with him.\n" );

   load_chat( 10, ({ "Miyamato Makimura says: I will make you a good price, master.\n",
                     "Miyamato Makimura bows to you.\n",
                     "Miyamato Makimura looks at the shelf.\n",
                     "Miyamato Makimura looks at your fingers.\n", 
             }) );

   load_a_chat(20,
           ({ "Miyamoto Makimura growls at you.\n",
              "Miyamoto Makimura says: You won't live long, bastard.\n",
             }) );

   set_gender(1);
   set_no_fear();
   set_follow_chance(0);
   set_parry(20);
   set_n_ac( 0 );
   set_feelings();
   
   set_ninja();
   set_accuracy( 25 );

   weapon = clone_object( "/players/tatsuo/guild/nweap/naginata" );
   transfer( weapon, this_object() );
   command( "wield naginata" );
}
