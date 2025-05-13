
inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"
 
void reset(int arg) 
{
  if (arg) return;
  set_light( 1);
   short_desc="Jinbo Ecchu's Sushi Bar";

  long_desc="You are in a small bar filled with tables and chairs. It looks "+
	"like a very respectable establishment. It's the most popular bar "+
	"in Mikawa. A small sign hangs on the wall. \n";

    items=({
	"sign", "Why don't you try reading it?",
        "table","A brown wooden table",
        "tables","Brown wooden tables",
        "chair","A small wooden chair",
        "chairs","Some small wooden chairs" });

	DD= ({ ZZ+"/mroad1", "east" });
}
 
query_property(arg) {
   return arg=="no_fight";
  } 
init() 
{
  add_action("order","order"); 
  add_action("order","buy"); 
  add_action("read","read"); 
 ::init();
}
read(str) {
 if (str=="menu" || str =="sign"  || str=="drink" || str=="drinks") {
write(
     "*******************************************************\n"+
     "		Jinbo Ecchu's Sushi Bar Menu 		     \n"+
     "*******************************************************\n"+
     "1) Water	\n"+
     "2) Sushi	\n"+
     "3) Eggroll	\n"+
     "4) Beef Chow Mein	\n"+
     "5) General Chein's Chicken \n"+
     "6) Trout's Famous Rootbeer Float \n"+
	
     " \n Order by name or number! \n ");
  return 1;
}
}
order(str)
{
 string name, short_desc,art, mess;
   int value, cost, strength, heal;
   object dummy;
 if (!str) {
  write("Order what ?\n");
  return 1;
}
 if( str=="water" || str=="1"){
 mess= "You pound a glass of clean, refreshing water";
 heal= 0;
 value= 60;
 strength= -6;
 art="food";
}
 else if (str=="sushi" || str=="2"){
  mess= "Mmmmm, that's good fish!! ";
 heal= 9;
 value= 75;
  strength= 1;
  art="food";
}
 else if(str=="beef"||str=="beef chow mein"||str=="4"){
  mess= "You wolf down the entire plate of beef chow mein ";
  heal= 20;
 value= 150;
  strength= 2;
 art="food";
}
  else if(str=="eggroll" || str=="3") {
  mess= "You munch on a tasty eggroll!";
 heal= 5;
 value= 25;
 strength= 1;
 art="food";
}
 else if( str=="chicken" || str=="general chein's chicken" || str=="5"){
 mess= "You devour a plate of the general's awesome chicken!";
 heal= 175;
 value= 450;
 strength= 4;
  art = "food";
}
 else if( str=="float" || str=="rootbeer float" || str=="6"){
 mess= "It's the best rootbeer float you've ever had! Damn, trout's good!";
 heal= 110;
 value= 350;
  strength = 4;
 art= "alko";
}
 
else {
    write("Jinbo looks at you confused saying: I don't have that. \n");
    return 1;
  }
 
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (art=="alko") {
  if (!call_other(this_player(), "drink_alcohol", strength)) {
   write("Jinbo says: I better cut you off that rootbeer! /n");
    return 1;
  }
}
  else if (art=="food") {
  if (!call_other(this_player(),"eat_food",strength)){
 write("Jinbo says: I think you've had enough. \n");
  say(this_player()->query_name()+" is hungry but Jinbo refuses. \n");
  return 1;
	}
}

  write("You pay " + value + " coins.\n");
  call_other(this_player(), "add_money", - value);
 call_other(this_player(), "heal_self", heal);
 write(mess + " \n");
  return 1;
}
