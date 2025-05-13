#include "/players/gareth/define.h"
inherit "/room/room"; 

void reset(int arg) 
{
  if (arg) return;
  set_light(1);
  short_desc= "Wendy's Place";
  long_desc= (
    "                      WELCOME!!\n"+
    " You stand in Wendy's famous fast food place. There's many\n"+
    "grills a blaze, cooking various types of food. You notice that\n"+
    "there are several skulls hanging on the wall as decoration. \n"+
    "There are several chairs and tables waiting to be used. Just  \n"
    "read the menu to find out what you want.\n");

    items=({
        "menu","A small iron sign with something written on it",
        "sign","A small iron sign with something written on it",
        "table","A white ivory table",
        "tables","White ivory tables",
        "chair","A white chair made of bone",
        "chairs","Some white chairs made of bone" });

    dest_dir=({ 
        ETOWN+"tr2","east",
             });
  
}
 
query_property(arg) {
   return arg=="no_fight";
  } 
init() 
{
  AA("order","order"); 
  AA("order","buy"); 
  AA("read","read"); 
 ::init();
}
read(str) {
 if (str=="menu" || str =="sign"  || str=="drink" || str=="drinks") {
write(
     "=======================================================\n"+
     "=               Welcome to Wendy's Place              =\n"+
     "=======================================================\n"+
     "= We offer:                                           =\n"+
     "= I.) Food and drinks to stay:                        =\n"+
     "= 1  Hot Tea                                 30 coins =\n"+
     "= 2  A WineCooler                           200 coins =\n"+
     "= 3  Warm Milk (cures poison)                20 coins =\n"+
     "= 4  Ham Sandwich                           800 coins =\n"+
     "= 5  Fish Fillet (fried)                    100 coins =\n"+
     "= 6  Chili                                  10 coins =\n"+
     "= II.) Fast food take out:                           =\n"+
     "= 7  A Burger (grilled)                     80 coins =\n"+
     "= 8  Cola (bottled)                         50 coins =\n"+
     "= You can consume also in numbers ---> <buy 1>       =\n");
    
     
  return 1;
}
}
order(str)
{
 string name, short_desc,art, mess;
   int value, cost, strength, heal;
   int pois;
   object dummy;
 if (!str) {
  write("What do you want???\n");
  return 1;
}
  if (str == "tea" || str == "1") {
  mess = "Yuck, Tea needs sugar but it does the trick!";
  heal = 5;
  value = 30;
  strength = -4;
  art ="alko";
}
  else if (str == "winecooler" || str == "2") {
  mess = "You feel refreshed!.... AHHHH";
  heal= 80;
  value = 200;
  strength = 4;
  art ="alko";
}
  else if (str == "milk" || str=="3") {
  mess = "Warm and sweet....HMMMMM....You feel better";
  heal= 25;
  value = 20;
  strength = 2;
  pois = 1;
  art = "alko";
}
  else if (str == "ham" || str=="4" || str == "sandwich") {
  mess = "Yummie!! Nice salty ham";
  heal = 180;
  value = 800;
  strength = 12;
  art = "food";
}
  else if (str == "fish" || str=="5" || str == "fillet") {
  mess = "Makes you wonder where the fish comes from";
  heal = 25;
  value = 100;
  strength = 4;
  art = "food";
}
  else if (str == "Chili" || str=="6") {
  mess = "Yipes! That's hot stuff!";
  heal = 20;
  value = 10;
  strength = 1;
  art = "food";
}
  else if (str == "burger" || str == "7") {
   if (TP->query_money() < 80) {
    write("The drow says: No money. No food!\n");
   return 1;
  }
  write("The drow hands you a burger.\n");
  dummy=CO(ITEM+"burger");
  if (TR(dummy,TP)) MO(dummy,environment(TP));
  TP->add_money(-80);
  return 1;
  }
  else if (str == "cola" || str == "8") {
   if (TP->query_money() < 50) {
    write("The drow says: NO money. No Food!\n");
   return 1;
  }
  write("The drow gives you some cola.\n");
  dummy=CO(ITEM +"cider");
  if (TR(dummy,TP)) MO(dummy,environment(TP));
  TP->add_money(-50);
  return 1;
  }
 
else {
    write("The drow screams: We don't sell that.\n");
    return 1;
  }
 
  if (call_other(TP, "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (art=="alko") {
  if (!call_other(TP, "drink_alcohol", strength)) {
    write("The drow says: You've had enough, damn Alcoholic\n");
    return 1;
  }
  if (pois == 1)
  {
     TP->add_poison(-this_player()->query_poisoned());
    
  }
}
  else if (art=="soft") {
  if (!call_other(TP,"drink_soft",strength)){
  write("The drow says: Your stomach does have a limit.\n");
  return 1;
 }
}
  else if (art=="food") {
  if (!call_other(TP,"eat_food",strength)){
  write("The drow says: You look sober to me.\n");
  say(TPN+" can't swallow anymore food.\n");
  return 1;
}
}

  write("You pay " + value + " coins.\n");
  call_other(TP, "add_money", - value);
  call_other(TP,"heal_self",heal*2);
  write(mess + ".\n");
  return 1;
}
