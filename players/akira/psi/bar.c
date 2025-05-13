
inherit "room/room";
#include "/players/akira/defs.h"
 
void reset(int arg) 
{
  if (arg) return;
  set_light( 1);
   short_desc="The Whole Year Inn.";
   long_desc=("This is one of the most used rooms in the entire tower.\n"+
              "The stress placed on the mind of a psionicist, has driven\n"+
              "many members of the guild to a life at the bottom of the\n"+
              "bottle. There is a sign on the wall above the bar.\n");


    items=({
	"sign", "Why don't you try reading it?",
        "table","A brown wooden table",
        "tables","Brown wooden tables",
        "chair","A small wooden chair",
        "chairs","Some small wooden chairs" });

        dest_dir=({"/players/akira/psi/hall2", "north"});
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
     "              The Hole You're In                       \n"+
     "*******************************************************\n"+
     "1) Water	\n"+
     "2) Beer   \n"+
     "3) Vodka          \n"+
     "4) Mind-Bleeder   \n"+
     "5) Pain Killer   \n"+
     "6) Akira Special \n"+
	
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
 else if (str=="beer" || str=="2"){
  mess= "Nothing like a nice cold beer!";
 heal= 9;
 value= 75;
  strength= 1;
  art="alko";
}
else if(str=="vodka" || str=="3"){
mess= "YEEeessss! Vodka, Nothing like it!";
  heal= 20;
 value= 150;
  strength= 2;
 art="alko";
}
else if(str=="bleeder" || str=="4"){
  mess= "You have no clue what it was, but boy was it good!";
 heal= 5;
 value= 25;
 strength= 1;
 art="alko";
}
else if(str=="Pain Killer" || str=="killer" || str=="5"){
mess= "You drink a shot of some strange liquid, and for a second the\n"+
      "pains and sounds in your head stop, but then they come back!\n";
 heal= 175;
 value= 450;
 strength= 4;
  art="alko";
}
else if(str=="special" || str==" Akira Special" || str=="6"){
mess=" Boy can that Akira make a drink!";
 heal= 110;
 value= 350;
  strength = 4;
 art= "alko";
}
 
else {
write("The bar keep looks at you funny and says: I don't have that.\n");
    return 1;
  }
 
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (art=="alko") {
  if (!call_other(this_player(), "drink_alcohol", strength)) {
   write("Your head is already spinning, maybe you should stop!\n");
    return 1;
  }
}
  else if (art=="food") {
  if (!call_other(this_player(),"eat_food",strength)){
write("The bar-keep says: Thats enough for you.\n");
  return 1;
	}
}

  write("You pay " + value + " coins.\n");
  call_other(this_player(), "add_money", - value);
 call_other(this_player(), "heal_self", heal);
 write(mess + " \n");
  return 1;
}
