#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()
#define TPN TP->query_name()
#define BAR (PPATH + "guild_bar")

inherit "room/room";
object trader;
string trader_name;
reset(arg) {
   if ( !trader ) {
      trader = clone_object( "/players/tatsuo/eastMonst/gbartender" );
      if ( trader )
         transfer( trader, this_object() );
      trader_name = trader->query_name();
      BAR->set_trader( trader_name );
   }
   if(arg) return;
   set_light(1);
   short_desc = "In the bar";
   long_desc=
	"This is the bar of the residence of Matsumae Yoshihiro, the evil\n"+
        "Shogun of the island of Ezo. The floor is made of wood and there\n" +
        "is a low table in the middle of the room. Some cushions are arranged\n" +
        "around the table. There is a sign fixed at the western wall.\n";
   items=({
	"chamber", long_desc,
        "bar",long_desc,
        "floor", "The floor is made of wood",
        "wood", "It is teak",
        "walls", "The walls are made of wood",
        "wall", "The wall is made of wood",
        "sign", "There are some nihonese letters written on it",
        "table", "It is a low table. It was polished lately",
        "cushions", "They look very soft, it invites you to sit down",
       "cushion", "It looks very soft, it invites you to sit down",
   });
   smell = "You smell the odor of alcohol.";
   dest_dir=({
	PPATH + "weaponery","north",
	PPATH + "inner-yard","east",
	PPATH + "store","south",
	PPATH + "broker","west",
   });
}

init() {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "move" );
   add_action( "get_it", "take" );
   add_action( "get_it", "push" );
   add_action( "sit_down", "sit" );
   add_action( "read_it", "read" );
   add_action( "buy_it",  "buy"  );
}

sit_down(arg) {
   if(!arg) return;
   if ( arg == "down" || arg == "down on cushion" || arg == "on cushion" ) {
      write( "You make yourself comfortable on one of the soft cushions.\n" );
      say( TPN + " sits down on one of the cushions.\n" );
   }
   return( 1 );
}

get_it(arg) {
   if(!arg) return;
  if((arg=="cushion")||(arg=="cushions")||(arg=="table")) {
    write("It is securely fixed to the floor, you fail with your attempt.\n");
    return 1;
  }
  return 0;
}

read_it(arg) {
   if ( TP->query_guild() == 8 )
      return( BAR->read( arg ) );
   else
      write( "You don't understand this language.\n" );
   return( 1 );
}

buy_it(arg) {
   if ( trader && present(trader,this_object()) )
      return( BAR->buy( arg ) );
   else
      write("Someone has killed "+trader_name+", so he cannot serve you.\n");
   return( 1 );
}
