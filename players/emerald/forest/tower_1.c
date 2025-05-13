inherit "/room/room";

#define TP    this_player()
#define TPN   TP->query_name()
#define INV   query_invis()
#define IMM   query_immortal()
#define HEAL  heal_self

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Tower Bar";
  long_desc="This is the bar in Moonchild's forest tower.  Reputedly, " +
            "the Wizard likes to have a bar in his private tower " +
            "because he likes making money off of his guests.  Other " +
            "people darkly mutter that he's just an alcoholic.  Probably " +
            "the real truth will never be known.  A dark stairway leads " +
            "up, while a spiral staircase leads back down.  Oh yes, and " +
            "there's a menu here if you want to read it.\n";

  dest_dir=({"/players/emerald/forest/tower_2", "up",
             "/players/emerald/forest/tower_g", "down"
           });

  items=({"menu", "You normally read these",
          "bar", "Just an ordinary bar",
          "tower","Moonchild's tower, and a dank place it is indeed",
          "stairway","It goes further up into this strange place",
          "staircase","It leads down, and possibly into peril",
        });

  ::reset();

}

void init() {
  ::init();
  add_action("_read","read");
  add_action("_order","order");
  add_action("_order","buy");
}

int _read(string str) {
  if(str=="menu") {
    write(
      "Moonchild's Wiazardly Concoctions:\n\n"+
      "1   Light ale                                20 coins\n"+
      "2   Whisky                                   70 coins\n"+
      "3   Scrumpy cider                           300 coins\n"+
      "4   Holy wine                               750 coins\n"+
      "5   Black coffee                             25 coins\n"+
      "6   Ham Salad                                70 coins\n"+
      "7   T-bone steak                            225 coins\n"+
      "8   Glass of spring water                    12 coins\n"+
      "9   Milkshake                               100 coins\n");
    return 1;
  }
  return 0;
}

int _order(string str) {
  string art, mess, mess2;
  int value, cost, strength, heal;

  if(TP->INV && !TP->IMM) {
    write("The server doesn't seem to think you exist.\n");
    write("Perhaps you are invisible.\n");
    return 1;
  }
  switch(str) {
    case "1" :
    case "light ale" :
    case "ale":
      mess = "You drink a mug of ale.";
      mess2="drinks a mug of ale.";
      heal=5;
      value=20;
      strength=5;
      art="alko";
      break;
    case "2" :
    case "whiskey" :
      mess="You throw back a shot of whiskey.";
      mess2="throws back a shot of whiskey.";
      heal=14;
      value=70;
      strength=10;
      art="alko";
      break;
    case "3" :
    case "scrumpy cider" :
    case "cider" :
      mess="You drink some scrumpy cider.";
      mess2="drinks some scrumpy cider.";
      heal=40;
      value=300;
      strength=20;
      art="alko";
      break;
    case "4" :
    case "holy wine" :
    case "wine" :
      mess="It's quite strong!";
      mess2="gasps on some rather strong wine.";
      heal=110;
      value=750;
      strength=36;
      art="alko";
      break;
    case "5" :
    case "black coffee" :
    case "coffee" :
      mess="You feel a little less fuzzy.";
      mess2="looks a little more alert.";
      heal=0;
      value=250;
      strength=-1;
      art="alko";
      break;
    case "6" :
    case "ham salad" :
    case "salad" :
      mess="You think the ham is a little moldy.";
      mess="eats some suspicious looking ham salad.";
      heal=10;
      value=70;
      strength=5;
      art="food";
      break;
    case "7" :
    case "t-bone steak" :
    case "steak" :
      mess="You enjoy a rare and juicy steak.";
      mess2="enjoys a really excellent steak.";
      heal=32;
      value=225;
      strength=16;
      art="food";
      break;
    case "8" :
    case "water" :
    case "spring water" :
    case "glass of spring water" :
      mess="You drink a refreshing glass of spring water.";
      mess2="drinks a glass of spring water.";
      heal=2;
      value=12;
      strength=-1;
      art="alko";
      break;
    case "9" :
    case "milkshake" :
    case "shake" :
      mess="You drink a nice foamy milkshake.";
      mess2="drinks a foamy milkshake.";
      heal=14;
      value=100;
      strength=7;
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
      write("The server says: You'll be sick if you eat more.\n");
      say(TPN+" is hungry, but the innkeeper refuses.\n");
      return 1;
    }
  }

  if(art=="alko" || art=="add_sp") {
    if(!TP->drink_alcohol(strength)) {
      write("The server says: I think you've had enough.\n");
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

