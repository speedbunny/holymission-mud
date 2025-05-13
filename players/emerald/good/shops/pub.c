inherit "room/room";

#define TP    this_player()
#define TPN   TP->query_name()
#define INV   query_invis()
#define IMM   query_immortal()
#define HEAL  heal_self

void reset(int arg) {
  if (arg) return;

  set_light(1);

  short_desc="The Mountain pub";

  long_desc="Welcome to the Pub of the Mountains!  This is by far " +
            "the friendliest pub in the entire mud.  The owner is a "+
            "cheerful, smiling man.  The counter is clean, and there " +
            "is plenty of drink on hand to satisfy your thirst.  A menu " +
            "is hanging on the wall.\n";

  items=({
    "wall","There is a menu hanging on it",
    "pub","The Pub of the Mountains",
    "counter","An old wooden counter",
    "menu","You could read it",
  });

  dest_dir=({"/players/emerald/good/shops/shop_street1","west",
           });

  clone_list=({
    1,1,"owner","/players/emerald/good/obj/owner",0,
    -1,1,"club","obj/weapon",({
      "set_name","club",
      "set_class",15,
      "set_weight",4,
      "set_value",850,
      "set_alt_name","wooden club",
      "set_short","A large wooden club",
    }),
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
    write("1.     Mug of ale          :  12 coins\n"+
          "2.     Cup of coffee       :  20 coins\n"+
          "3.     A special           :  50 coins\n"+
          "4.     Hot toddy           : 150 coins\n"+
          "5.     Shot of Jack        : 450 coins\n\n");
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
  switch(str) {
    case "1" :
    case "ale" :
    case "mug of ale" :
      mess="You chug down a mug of cool ale.";
      mess2="chugs down a mug of cool ale.";
      heal=0;
      value=12;
      strength=2;
      art="alko";
      break;
    case "2" :
    case "coffee" :
      mess="Your head feels a little clearer.";
      mess2="looks a little more alert.";
      heal=0;
      value=20;
      strength=-2;
      art="alko";
      break;
    case "3" :
    case "special" :
      mess="You enjoy a special of the pub.";
      mess2="enjoys the special of the pub.";
      heal=10;
      value=50;
      strength=8;
      art="alko";
      break;
    case "4" :
    case "hot toddy" :
      mess="It warms you through.";
      mess2="happily sips a hot toddy.";
      heal=25;
      value=150;
      strength=12;
      art="alko";
      break;
    case "5" :
    case "jack" :
    case "shot of jack" :
      mess="You throw back a shot of Jack Daniels.";
      mess2="throws back a shot of Jack Daniels.";
      heal=60;
      value=450;
      strength=20;
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
