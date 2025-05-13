inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light( 1);
    short_desc = "Nickum's Tavern";
    long_desc=
      "You are in Nickum's Tavern, the best pub around.  The"+
      " bar is kept very clean and tidy.  There is a long "+
      "wooden bar with stools and several tables with"+
      " chairs along the walls.  There is a menu hanging above"+
      " the bar.  Mages come here to forget their troubles and"+
      " relax.  Feel free to come in as often as you like.\n";
    items=({
      "menu","A small iron sign with something written on it",
      "bar", "A long wooden bar with bottles along it",
      "stools", "Brown wooden stools",
      "stool", "A brown wooden stool",
      "bottle","The bottle have playing cards inside them",
      "cards", "Playing cards that are the trademark of the pub",
      "table","A brown wooden table",
      "tables","Brown wooden tables",
      "chair","A small wooden chair",
      "chairs","Some small wooden chairs" 
    });
    dest_dir=({
      TOWER+"room/hall1", "north",
      TOWER+"room/kegshop", "northwest",
    });
    ::reset();
}

init() {

    AA("order","order"); 
    AA("order","buy"); 
    AA("read","read"); 
    ::init();
}

read(str) {

  if (str=="menu" || str=="sign") {
     ME(
      "#######################################################\n"+
      "                 NICKUM'S TAVERN                        \n"+
      "#######################################################\n"+
      "Nickum is proud to offer:\n\n"+
      "Food and beverages for direct consumption:\n"+
      "1   Haggis                                 4000 coins \n"+
      "2   Jalapeno liqueur (**HOT**)             2000 coins \n"+
      "3   Dandelion wine                          200 coins \n"+
      "4   Heather Ale                              30 coins \n"+
      "5   Cheese crowdie                          500 coins \n"+
      "6   Grundy                                   40 coins \n"+
      "7   Coffee                                   40 coins \n"+
      "8   Water                                    12 coins \n"+
      "9   Magi's mage boost (SP-boost)            200 coins \n"+
      "You can also consume by numbers:  <buy 1> for Haggis.\n"
      );
  return 1;
  }
}

order(str) {

  string name, short_desc,art, mess;
  int value, cost, strength, heal,i;
  object dummy;

  if (!str) {
      ME("Nickum looks at you with a puzzled expression.\n");
  return 1;
  }
  if (str == "haggis" || str == "1") {
      mess = "The haggis taste incredible.....YUMMMM!";
      heal = 100;;
      value = 4000;
      strength = 42;
      art ="alko";
  }
  else
  if (str == "jalapeno" || str == "liqueur" || str == "2") {
      if(15+random(15)+random(15)>=TPCON) {
        ME("As you start to drink, you get a POWERFUL urge to"+
	   " run and run and run ...\n");
/*  Airborne:  this is unnecessary.
        shout(TPQN+" shouts like a maniac:  WATER, WATER, WATER!!!\n");
*/
             for(i=0;i<10;i++) this_player()->run_away();
      return 1;
      }
      mess = "#$%^&*@!  You start to run around screaming out:  "+
            "WATER, WATER, WATER!!!";
      heal= 150;
      value = 2000;
      strength = 50;
      art ="alko";
  }
  else
  if (str == "wine" || str == "dandelion" || str == "3") {
      mess = "The dandelion wine makes you feel much better.... AHHHH";
      heal= 30;
      value = 200;
      strength = 16;
      art ="alko";
  }
  else
  if (str == "ale" || str == "heather" || str=="4") {
      mess = "You enjoy the great taste of heather ale.... AHHHH";
      heal= 8;
      value = 30;
      strength = 3;
      art = "alko";
  }
  else
  if (str == "crowdie" || str == "cheese" || str=="5") {
      mess = "MMMM.... Cheese crowdie tastes mighty fine";
      heal = 30;
      value = 500;
      strength = 20;
      art = "food";
  }
  else
  if (str == "grundy" || str=="6") {
      mess = "The sweet grundy melts in you mouth....MMMMMMMM";
      heal = 5;
      value = 40;
      strength = 6;
      art = "food";
  }
  else if (str == "coffee" || str=="7") {
      mess = "AHH.... Your thoughts become clearer!\n";
      heal = 0;
      value = 40;
      strength = -2;
      art = "alko";
  }
  else
  if (str == "water" || str == "8") {
      mess = "AHH.... You feel your head getting clearer!\n";
      heal = 0;
      value = 12;
      strength = -1;
      art = "alco";
  }
  else
  if (str == "boost" || str=="9"){
      mess = "You choke on the power of this drink.  You now "+
             "feel energized.\n";
      heal = 120;
      value = 200;
      strength = 6;
      art = "boost";
  }
  else
  {
  ME("Nickum stares at you, saying: We don't serve that here.\n");
  return 1;
  }
  if (call_other(TP, "query_money", 0) < value) {
      ME("That costs " + value + " gold coins, which you don't have.\n");
  return 1;
  }
  if (art=="alko" || art=="boost") {
     if (!call_other(TP, "drink_alcohol", strength)) {
        ME("Nickum says: I think you have had enough.\n");
     return 1;
     }
  }
  else
  if (art=="soft") {
      if (!call_other(TP,"drink_soft",strength)){
         ME("Nickum says: Sorry, I don't think your stomach can"+
            " not take much more.\n");
      return 1;
      }
  }
  else
  if (art=="food") {
      if (!call_other(TP,"eat_food",strength)){
         ME("Nickum says: Hey, pal, I think you are sober.\n");
         say(TPQN+" is hungry but Nickum refuses.\n");
      return 1;
      }
  }
  ME("You pay " + value + " coins.\n");
  TP->GP(-value);

  if(art=="special") TP->restore_spell_points(heal);
    else 
    TP->heal_self(heal);
    ME(mess + ".\n");

  if(strength==50) say(TPQN+" jumps up and begins "+
      "to dance in a frenzy on the bar.\n");
  return 1;
}
