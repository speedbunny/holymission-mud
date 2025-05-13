#define TP this_player()
#define TPN TP->query_name()
#define TPM TP->query_money()

#define FOOD_PATH "/players/tatsuo/guild/food/"
string trader;

id(str) {
   return str=="bar";
}
  
short() {
   return "The bar";
}

long() {
   return "The bar";
}

query_name() {
   return( "bar" );
}

set_trader(n) {
   trader = n;
}

query_trader() {
   return( trader );
}

buy(arg) {
   if(!arg) return;
   switch(arg) {
	 case "wine":
	 case "rice wine":
         case "keg of rice wine":
		 return( buy_item( "RiceWineKeg" ) );     
     case "watered rice beer": 
	 case "watered beer": 
         return( buy_item( "wateredRiceBeer" ) );
     case "weak rice beer":
	 case "weak beer": 
         return( buy_item( "weakRiceBeer" ) );
     case "strong rice beer":
	 case "strong beer": 
         return( buy_item( "strongRiceBeer" ) );
     case "poor sake": 
         return( buy_item( "poorSake" ) );
     case "average sake": 
         return( buy_item( "avSake" ) );
     case "best sake": 
         return( buy_item( "bestSake" ) );
     case "fruit brandy":
	 case "brandy": 
         return( buy_item( "fruitBrandy" ) );
     case "shochu": 
         return( buy_item( "shochu" ) );
     default: 
       write( trader + " says: Sorry, I don't have this item.\n" );
     return( 1 );
	 }
   return( 1 );
}

read(arg) {
   if (arg!="sign") return;
   write(
      "**************************************************\n" +
      "* watered rice beer     1 bottle         2 coins *\n" +
      "* weak rice beer        1 bottle         4 coins *\n" +
      "* strong rice beer      1 bottle         6 coins *\n" +
      "* poor sake             1 bottle        10 coins *\n" +
      "* average sake          1 bottle        18 coins *\n" +
      "* best sake             1 bottle        26 coins *\n" +
      "* fruit brandy          1 bottle        36 coins *\n" +
      "* shochu                1 bottle        50 coins *\n" +
	  "* rice wine             1 keg          400 coins *\n" +
      "**************************************************\n"
   );
   return( 1 );
}

buy_item(arg) {
   object obj;
   int    value;
   if(!arg) return;
   obj = clone_object( FOOD_PATH + arg );
   value = obj->query_value() * 2;
   if ( TP->query_money() < value ) {
      write( trader + " says: Sorry, but you don't have enough coins !\n" );
      destruct( obj );
      return( 1 );
   }
   if ( transfer( obj, TP ) ) {
      write( trader + " says: Sorry, but you can't carry any more.\n" );
      destruct( obj );
      return( 1 );
   }
   write( trader + " gives you a " + obj->query_name() + ".\n" );
   say( TPN + " buys a " + obj->query_name() + ".\n" );  
   TP->add_money( -value );
   return( 1 );
}
