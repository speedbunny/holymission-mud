inherit "room/room";

#define TP    this_player()
#define TPN   TP->query_name()
#define INV   query_invis()
#define IMM   query_immortal()
#define HEAL  heal_self

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc= "Druid Lakmir's bar";
  long_desc="You have entered the bar of Druid Lakmir.  There are plenty "+
            "of chairs and tables setting around for the customers.  "+
            "Candles set on the tables provide the light.  There is a "+
            "menu on the wall and the barman is ready to serve you.\n";

    items=({"menu","A small iron sign with something written on it",
            "tables","Brown wooden tables with candles on them",
            "chairs","Some small wooden chairs",
            "candles", "They are lighted",
            "barman","He waits for your order",
            "wall","A wooden wall with a menu hanging on it",
    });

    dest_dir=({"/players/emerald/lakmir/fork","out" 
             });

    property=({ "has_fire" });

  clone_list=({
    1,1,"hobgogblin","obj/monster", ({
      "set_name","rambling hobgoblin",
      "set_alias","hobgoblin",
      "set_race","hobgoblin",
      "set_level",10,
      "set_short","A rambling hobgoblin",
      "set_long","A rambling hobgoblin happily sitting at a table.\n",
      "add_money",400,
    }),
    2,1,"poor","obj/monster", ({
      "set_name","poor hobgoblin",
      "set_race","hobgoblin",
      "set_alias","poor",
      "set_short","A poor hobgoblin",
      "set_long","This poor hobgoblin is thirsty, but out of money.\n",
      "set_level",10,
    }),
    3,1,"fat","obj/monster", ({
      "set_name","fat hobgoblin",
      "set_alias","fat",
      "set_race","hobgoblin",
      "set_short","A pudgy hobgoblin",
      "set_long","A fat hobgoblin who sits here everyday and eats his fill.\n",
      "set_level",13,
      "add_money",400,
    }),
    4,1,"drunk","obj/monster", ({
      "set_name","drunk hobgoblin",
      "set_alias","drunk",
      "set_race","hobgoblin",
      "set_short","A drunk hobgoblin",
      "set_long","A totally inebriated hobgoblin.\n",
      "set_level",9,
      "add_money",300,
    }),
  });

  ::reset();

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
     "#######################################################\n"+
     "                   DRUID LAKMIR'S BAR                  \n"+
     "#######################################################\n"+
     "We offer:\n\n"+
     "A.) Food and drinks for direct consumption:\n"+
     "1   Wine                                    400 coins \n"+
     "2   Beer                                     60 coins \n"+
     "3   Fish soup                               500 coins \n"+
     "4   Muesli                                   40 coins \n"+
     "5   Coffee                                   50 coins \n"+
     "6   Water                                    20 coins \n"+
     "You can consume also in numbers...<buy 1> for the Wine.\n");
  return 1;
  }
}


int _order(string str) {
  string art, mess, mess2;
  int value, cost, strength, heal;

  if(TP->INV && !TP->IMM) {
    write("The innkeeper doesn't even seen to notice you exist.\n");
    write("Perhaps you are invisible.\n");
    return 1;
  }

  switch(str) {
    case "1" :
    case "wine" :
      mess = "You quietly sip a glass of wine.";
      mess2="quietly sips a glass of wine.";
      heal=30;
      value=400;
      strength=10;
      art="alko";
      break;
    case "2" :
    case "beer" :
      mess="You guzzle a mug of beer.";
      mess2="guzzles a mug of beer.";
      heal=10;
      value=60;
      strength=8;
      art="alko";
      break;
    case "3" :
    case "fish soup" :
      mess="You eat a bowl of fish soup.";
      mess2="eats a bowl of fish soup.";
      heal=60;
      value=500;
      strength=20;
      art="food";
      break;
    case "4" :
    case "muesli" :
      mess="You eat a block of muesli.";
      mess2="eats a block of muesli.";
      heal=10;
      value=40;
      strength=6;
      art="food";
      break;
    case "5" :
    case "coffee" :
      mess="You drink a mug of coffee.";
      mess2="drinks a mug of coffee.";
      heal=5;
      value=50;
      strength=-6;
      art="alko";
      break;
    case "6" :
    case "water" :
      mess="You drink a glass of water.";
      mess2="drinks a glass of water.";
      heal=1;
      value=20;
      strength=-2;
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

  if(art=="food" || art=="add_sp") {
    if(!TP->eat_food(strength)) {
      write("The innkeeper says: You'll be sick if you eat more.\n");
      say(TPN+" is hungry, but the innkeeper refuses.\n");
      return 1;
    }
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

light_text(str) {
  write("You hold the "+str+" to the candle of the table to light it.\n");
  say(TPN+" lights a "+str+", using the candle of the table.\n");
}
