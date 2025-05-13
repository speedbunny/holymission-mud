inherit "room/room";

#define TP    this_player()
#define TPN   TP->query_name()
#define INV   query_invis()
#define IMM   query_immortal()
#define HEAL  heal_self

void reset(int arg) {
  if (arg) return;

  set_light(1);

  short_desc="The local inn";

  long_desc=
    "You have entered a bright cheery room.  Townspeople are " +
    "sitting at some of the many tables in the common room, and " +
    "a fire crackles in the grate.  The innkeeper is a large man " +
    "with a smiling face.  There is a menu on the wall.\n";

  items=({
    "tables","Sturdy wooden tables",
    "fire","It is safely confined to the fireplace",
    "innkeeper","He is waiting to serve you",
    "menu","You could read it",
    "grate","The fireplace where the fire is burning",
  });

  dest_dir=({
    "/players/emerald/town/t20","south",
  });

  ::reset(arg);
}
 
void init() {
  ::init();
  add_action("_order","order");
  add_action("_order","buy");
  add_action("_read","read");
}

int _read(string str) {
  if(str=="menu") {
    write(
      "X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X\n"+
      "                     THE SILVER FOX\n"+
      "X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X\n"+
      "We offer:\n\n"+
      "1   A bowl of porridge                       20 coins\n"+
      "2   A bowl of stew                           50 coins\n"+
      "3   Fresh bread                              10 coins\n"+
      "4   A plate of chicken                       100 coins\n"+
      "5   A slice of roast ox                      500 coins\n");
    return 1;
  }
  return 0;
}

int _order(string str) { 
  string art, mess, mess2; 
  int value, cost, strength, heal; 
 
  if(TP->INV && !TP->IMM) {
    write("The innkeeper doesn't even seen to notice you exist.\n");
    write("Perhaps you are invisible.\n");
    return 1;
  }

/* A switch statement is better than using a large group of
   if-else statements or you have multiple options to match.
   The cases are the options that the variable must be equal
   to in order to execute the code in that particular case
   statement. Once a case matches up, it will execute all
   code under that case and subsequent cases until a break,
   continue or return is found. (Ie. in this example, if 
   "1" == str, then all the code under porridge is executed
   until the break statement which makes the code jump out of
   the switch statement. If no break was there, then it would've
   continued to execute the code located under "stew" also.)
   The default stands for if none of the cases provided a match,
   then the code under the default is executed.
*/

  switch(str) { 
    case "1" : 
    case "porridge" : 
      mess = "You swallow a bowl of porridge.";
      mess2="eats some porridge.";
      heal=5;
      value=20;
      strength=1;
      art="food";
      break;
    case "2" :
    case "stew" :
      mess="You slurp a bowl of stew.";
      mess2="slurps a bowl of stew";
      heal=15;
      value=50;
      strength=10;
      art="food";
      break;
    case "3" :
    case "bread" :
      mess="You munch on some bread.";
      mess2="munches some bread.";
      heal=4;
      value=10;
      strength=1;
      art="food";
      break;
    case "4" :
    case "chicken" :
      mess="The chicken is a little tough.";
      mess2="chews a tough old chicken.";
      heal=25;
      value=100;
      strength=20;
      art="food";
      break;
    case "5" :
    case "roast" :
    case "ox" :
      mess="You eat some juicy roast ox.";
      mess2="eats some juicy roast ox.";
      heal=40;
      value=500;
      strength=25;
      art="food";
      break;
    default :
      notify_fail("Order what?\n");
      return 0;
  }
 
  if(TP->query_money() < value) {
    write("That costs "+value+" gold coins, which you don't have.\n");
    return 1;
  }

  if(art=="food" || art=="add_sp") {
    if(!TP->eat_food(strength)) {
      write("The innkeeper says: You'll be sick if you eat more.\n");
      say(TPN+" is hungry, but the innkeeper refuses.\n");
      return 1;
    }
  }

  write("You pay "+value+" coins.\n");
  TP->add_money(-value);
  TP->HEAL(heal);
  write(mess+"\n");
  say(TPN+" "+mess2+"\n");
  return 1;
} 
 
