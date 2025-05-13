#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()
#define TPN TP->query_name()
#define TO     (this_object())
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";
object shogun;
reset(arg) {
   if ( !shogun ) {
      shogun = clone_object( "/players/tatsuo/eastMonst/gshogun" );
      if ( shogun )
         transfer( shogun, this_object() );
   }
   
   if(arg) return;
   set_light(1);
   short_desc = "At Matsumae Yoshihiro";
   long_desc=
	"This is the chamber of Matsumae Yoshihiro, the evil Shogun of\n"+
	"the island of Ezo. At the ground lies a very expensive looking\n"+
	"carpet and the walls are covered with pictures. To the north is\n"+
	"the throne of Matsumae Yoshihiro and behind the throne is a\n"+
	"tapestry. Thre is also a set of stairs at the backside of the\n"+
	"room leading up.\n";
   items=({
	"chamber", long_desc,
        "floor", "The floor is made of wood. Carpets covers it",
        "walls", "The walls are made of wood. There are many pictures at them",
        "wall", "The wall is made of wood. There are pictures at it",
        "wood","It is very expensive teak",
        "carpet","The carpet is very expensive looking and has a nihonese design",
              "picture", "The picture shows Yoshihiro-san, as he slayed a gaint ryu",
        "pictures", "The pictures show the famous fights of Yohihiro-san",
        "tapestry", "The tapestry is dark black",
        "throne", "The throne is made of three crossed katanas and a shield",
        "katanas", "Katanas, only katanas, nothing else",
         "shield", "It is a platinum shield, connected to the katanas",
   });
   smell = "You smell the odor of fear.";
   dest_dir=({
	PPATH + "inner-yard1","north",
	PPATH + "tearoom","east",
	PPATH + "restroom","west",
   });
}

init() {
   ::init( );
   add_action("get_it","get" );
   add_action("get_it","take" );
   add_action("up", "up" );
}

up(arg) {
   if(arg) return;
  if(this_player()->query_guild() != 8) return;
  if(this_player()->query_level() <20 )
      write( "The shogun growls at you: Only Sans are allowed to go up !!!\n" );
   else
      this_player()->move_player( "up#"+PPATH+"conference" );
   return( 1 );
}

get_it(arg) {
   object ob;
   if(!arg) return;
   if ( arg == "throne" ) {
      write( "You don't dare to get the throne,\n" +
             "because you fear the wrath of Yoshihiro-san.\n" );
      return( 1 );
   }
   else if ( arg == "katana" ) {
      ob = present( "katana", TO );
      if ( ob ) {
         if ( ob->get() ) {
            if ( transfer( ob, TP ) )
               write( "You can't take that !\n" );
            else
               write( "Ok.\n" );
         }
      }
      else
         write( "You don't dare to get the katana from the throne,\n" + 
                "because you fear the wrath of Yoshihiro-san.\n" );
      return( 1 );
   }
   else if ( arg == "shield" ) {
      ob = present( "shield", TO );
      if ( ob ) {
         if ( ob->get() ) {
            if ( transfer( ob, TP ) )
               write( "You can't take that !\n" );
            else
               write( "Ok.\n" );
         }
      }
      else
         write( "You don't dare to get the shield from the throne,\n" + 
                "because you fear the wrath of Yoshihiro-san.\n" );
      return( 1 );
   }
   return( 0 );
}
