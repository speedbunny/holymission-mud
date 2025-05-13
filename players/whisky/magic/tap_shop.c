#include "../guild.h"
inherit "room/room";
   object machine;
 
reset(arg) {
  if (!machine) {
     machine=clone_object("players/whisky/shops/slotmachine");
     move_object(machine,this_object());
    }
  if (arg) return;
  set_light( 1);
  short_desc= "In the monks-bar";
  long_desc=
    "You are now in the eastern restroom of the monks-chapel.\n"+
    "In front of you you can see some tables and chairs.\n"+
    "It looks nearly like a bar, but it can't be  HOLY COW !!!!\n"+
    "There is the menu hanging on the wall and a monk serving\n"+
    "meals and drinks. Hmmmm let's read the sign to get more\n"+
    "information.\n";
    items=({
        "menu","A small iron sign with something written on it",
        "table","A brown wooden table",
        "tables","Brown wooden tables",
        "chair","A small wooden chair",
        "chairs","Some small wooden chairs" });

    dest_dir=({ 
        "players/whisky/guild/room/c10","west",
        "players/whisky/guild/room/shop","east" });
  
}
 
query_property(arg) {
   return arg=="no_fight";
  } 
init() {
  object ob;
  ob=present("ring of following",TP);
  if (RAUS) {
   if (ob) move_object(ob,E(TP));
   TP->move_player(WO);
  return 1;
  }
  add_action("order","order"); 
  add_action("order","buy"); 
  add_action("read","read"); 
 ::init();
}
read(str) {
 if (str=="menu" || str=="drink" || str=="drinks") {
write(
     "#######################################################\n"+
     "                 THE HOLY CANTINE                      \n"+
     "#######################################################\n"+
     "We offer:\n"+
     "A.) Food and drinks for the direct consume:\n"+
     "1  A Holy Wine                              1500 coins \n"+
     "2  A Ricewine                                200 coins \n"+
     "3  A Nunswetter                               20 coins \n"+
     "4  A Lambssteak                             1000 coins \n"+
     "5  A Chicken (roasted)                       100 coins \n"+
     "6  A Fishrice                                 10 coins \n"+
     "B.) Food and drinks to take away:\n"+
     "7  A Lambscutlet (roasted)                    80 coins \n"+
     "8  A Cider (bottled)                          50 coins \n"+
     "You can consume also in numbers....<buy 1> for the Holy Whine.\n");
    
     
  return 1;
}
}
order(str)
{
 string name, short_desc,art, mess;
   int value, cost, strength, heal;
   object dummy;
 if (!str) {
  write("You might feel the chaos in this world..order what??\n");
  return 1;
}
  if (str == "holy wine" || str == "1") {
  mess = "The Holy wine refreshes you.... AHHHH";
  heal = 180;
  value = 1500;
  strength = 8;
  art ="alko";
}
  else if (str == "ricewine" || str == "2") {
  mess = "The Ricewine makes you feel much better.... AHHHH";
  heal= 40;
  value = 200;
  strength = 4;
  art ="alko";
}
  else if (str == "nunswetter" || str=="3") {
  mess = "You enjoy the good taste of herbs.... AHHHH";
  heal= 12;
  value = 20;
  strength = 2;
  art = "alko";
}
  else if (str == "lambssteak" || str=="4") {
  mess = "MMMM.... Such a lambsteak tastes fine";
  heal = 120;
  value = 1000;
  strength = 12;
  art = "food";
}
  else if (str == "chicken" || str=="5") {
  mess = "WELL.... Such a chicken tastes fine";
  heal = 20;
  value = 100;
  strength = 4;
  art = "food";
}
  else if (str == "fishrice" || str=="6") {
  mess = "WELL.... Such a fishrice tastes fine";
  heal = 5;
  value = 10;
  strength = 1;
  art = "food";
}
  else if (str == "lambscutlet" || str == "7") {
   if (this_player()->query_money() < 80) {
    write("The monk says: Sorry, but you don't have enough money.\n");
   return 1;
  }
  write("The monk gives you a lambscutlet.\n");
  dummy=clone_object("players/whisky/guild/obj/lambcotlet");
  if (transfer(dummy,this_player())) move_object(dummy,environment(this_player()));
  this_player()->add_money(-80);
  return 1;
  }
  else if (str == "cider" || str == "8") {
   if (this_player()->query_money() < 50) {
    write("The monk says: Sorry, but you don't have enough money.\n");
   return 1;
  }
  write("The monk gives you a cider.\n");
  dummy=clone_object("players/whisky/guild/obj/cider");
  if (transfer(dummy,this_player())) move_object(dummy,environment(this_player()));
  this_player()->add_money(-50);
  return 1;
  }
 
else {
    write("The monk stares at you, saying: We don't have that.\n");
    return 1;
  }
 
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (art=="alko") {
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("The monk says: I think you've had enough.\n");
    
    return 1;
  }
}
  else if (art=="soft") {
  if (!call_other(this_player(),"drink_soft",strength)){
  write("The monk says: Sorry, I don't think you have a cow stomach.\n");
  return 1;
 }
}
  else if (art=="food") {
  if (!call_other(this_player(),"eat_food",strength)){
  write("The monk says: I think you are sober.\n");
  say(this_player()->query_name()+" is hungry but the old sailor refuses.\n");
  return 1;
}
}

  write("You pay " + value + " coins.\n");
  call_other(this_player(), "add_money", - value);
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
  return 1;
}
