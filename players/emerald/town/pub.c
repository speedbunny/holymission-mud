inherit "room/room";

#define TP    this_player()
#define TPN   TP->query_name()
#define INV   query_invis()
#define IMM   query_immortal()
#define HEAL  heal_self

void reset(int arg) {
  if (arg) return;

  set_light(1);

  short_desc="The town pub";

  long_desc=
    "You have entered a dim, smoky room.  A few patrons are " +
    "sitting at the counter, quietly drinking frothy ale from " +
    "mugs.  There is a menu on the wall, and bartender behind " +
    "the counter.\n";

  items=({
    "patrons","They are minding their own business",
    "counter","An old wooden counter",
    "bartender","He is waiting to serve you",
    "menu","You could read it",
    "ale","A strong alcoholic beverage",
    "mugs","Thick ceramic drinking vessels",
  });

  dest_dir=({
    "/players/emerald/town/t16","south",
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
      "                     THE KEG AND CASK\n"+
      "X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X\n"+
      "We offer:\n\n"+
      "1   A glass of white wine                     20 coins\n"+
      "2   A glass of red wine                       50 coins\n"+
      "3   A mug of ale                             100 coins\n"+
      "4   A mug of beer                            150 coins\n"+
      "5   A shot of whiskey                        500 coins\n");
    return 1;
  }
  return 0;
}

int _order(string str) { 
  string art, mess, mess2; 
  int value, cost, strength, heal; 
 
  if(TP->INV && !TP->IMM) {
    write("The bartender doesn't even seen to notice you exist.\n");
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
    case "white wine" : 
    case "wine" :
      mess="You quietly sip a glass white wine.";
      mess2="quietly sips a glass of white wine.";
      heal=5;
      value=20;
      strength=1;
      art="alko";
      break;
    case "2" :
    case "red wine" :
      mess="You sip a glass of red wine.";
      mess2="sips a glass of red wine.";
      heal=15;
      value=50;
      strength=10;
      art="alko";
      break;
    case "3" :
    case "beer" :
      mess="You guzzle a mug of beer.";
      mess2="guzzles a mug of beer.";
      heal=30;
      value=150;
      strength=20;
      art="alko";
      break;
    case "4" :
    case "ale" :
      mess="The ale is very strong.";
      mess2="drinks a strong ale.";
      heal=25;
      value=100;
      strength=20;
      art="alko";
      break;
    case "5" :
    case "whiskey" :
      mess="You throw back a shot of whiskey.";
      mess2="throws back a shot of whiskey.";
      heal=40;
      value=500;
      strength=25;
      art="alko";
      break;
    default :
      notify_fail("Order what?\n");
      return 0;
  }
 
  if(TP->query_money() < value) {
    write("That costs "+value+" gold coins, which you don't have.\n");
    return 1;
  }

  if(art=="alko" || art=="add_sp") {
    if(!TP->drink_alcohol(strength)) {
      write("The bartender says: I think you've had enough.\n");
      say(TPN+" wants to get drunk, but the bartender refuses.\n");
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
 
