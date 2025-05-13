#include "../garden.h"
object ob,ob2;
/* generell art of bar Whisky(c) feel free to copy and change */
 
reset(arg) {
if (!ob) { ob=clone_object("players/whisky/garden/obj/scroll");
           move_object(ob,this_object());
    }
if (!ob2) { ob2=clone_object("players/whisky/shops/slotmachine");
            move_object(ob2,this_object());
          }
  if (arg) return;
  set_light( 1);
}
 
short() {
 return "In a little bar";
}
 
init() {
  add_action("move"); add_verb ("south");
  add_action("order"); add_verb ("order");
  add_action("order"); add_verb ("buy");
  add_action("read"); add_verb ("read");
}
 
move(str) {
  if (!str) str=query_verb();
  this_player()->move_player("south#"+ROOM+"/garden5");
  return 1;
}
 
 
long() {
write("You have entered the little garden bar of Chantilly's garden.\n"+
"A waiter is waiting behind the counter waiting for you to order\n"+
"drinks or snacks. There is a menu hanging on the wall. Just type\n"+
"<read menu> to see what we've got.\n"+
"    The only obvious exit is south.\n");

}

read(str) {
if(str == "menu") {
write("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n"
    + "    A glass of cold beer (25 coins)                  \n"
    + "    A glass of dry gin (9 coins)                    \n"
    + "    A glass of cold milk (12 coins)                   \n"
    + "    A glass of fresh mountain water (1 coin)         \n"
    + "    A cheese and ham sandwich (14 coins)              \n\n"
    + "+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  return 1;
}
}
order(str)
{
 string name, short_desc,art, mess;
   int value, cost, strength, heal;
 
 if (!str) {
  write("You might feel the chaos in this world..order what??\n");
  return 1;
}
if (str == "sandwich") {
mess = "You eat a delicious cheese and ham sandwich";
heal = 4;
value = 14;
strength = 8;
art ="food";
}
else if (str == "beer") {
mess = "AHHH You are enjoying the taste of a really good beer";
heal= 12;
value = 25;
strength = 4;
art ="alko";
}
else if (str == "gin") {
mess = "You are drinking a good glass of dry gin";
heal = 5;
 value = 9;
strength = 2;
art = "alko";
}
else if (str == "milk") {
mess = "You are enjoying a glass of fresh milk";
heal = 3;
 value = 12;
 strength = 8;
 art = "soft";
}
  else if (str == "water") {
 mess = "You are drinking a glass of excellent mountain water";
heal = 1;
  value = 1;
strength = 4;
art = "soft";
}
else {
    write("The waiter stares at you, saying: We don't have that.\n");
    return 1;
  }
 
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (art=="alko") {
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("The bartender says: I think you've had enough.\n");
    say(call_other(this_player(), "query_name", 0) + " asks for a " +
	str + " but the bartender refuses.\n");
    
    return 1;
  }
}
  else if (art=="soft") {
  if (!call_other(this_player(),"drink_soft",strength)){
  write("The bartender says: Sorry, I don't think you have a cow stomach.\n");
  say(this_player()->query_name()+" asks for a "+str+" but the bartender\n"+
    "refuses.\n");
   return 1;
 }
}
 else if (art=="food") {
 if (!call_other(this_player(),"eat_food",strength)){
 write("The bartender says: I think you are sober.\n");
 say(this_player()->query_name()+" is hungry but the bartender refuses.\n");
 return 1;
}
}

  write("You pay " + value + " coins for a " + str + ".\n");
  say(call_other(this_player(), "query_name", 0) + " enjoys a " + str + ".\n");
  call_other(this_player(), "add_money", - value);
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
  return 1;
}
