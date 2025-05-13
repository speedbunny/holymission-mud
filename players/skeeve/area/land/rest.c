inherit "room/room";

#include "/players/skeeve/area.h"
 
reset(arg) {
  if (!arg) {
    set_light( 1);
    short_desc= "Druid Lakmir's bar";
    long_desc=
      "You have now entered druid Lakmir's bar.\n"+
      "In front of you you can see some tables and chairs. "+
      "There is the menu hanging on the wall which gives you "+
      "information about food and drinks.\n"; 
      
    items=({
        "menu","A small iron sign with something written on it",
        "table","A brown wooden table with a candle on it",
        "tables","Brown wooden tables",
        "chair","A small wooden chair",
        "chairs","Some small wooden chairs",
        "candle", "It's a burning candle"
    });

    dest_dir=({ LAND+"fork","out" });
    property=({ "has_fire" });
  }
  
  CASTLE->add_sphinx_obj("broom",this_object());
  if (!present("rambling hobgoblin"))
    move_object(clone_object(MONSTERS+"hobgoblin")->config("rambling"),this_object());
  if (!present("poor hobgoblin"))
    move_object(clone_object(MONSTERS+"hobgoblin")->config("poor"),this_object());
  if (!present("fat hobgoblin"))
    move_object(clone_object(MONSTERS+"hobgoblin")->config("fat"),this_object());
  if (!present("tanked hobgoblin"))
    move_object(clone_object(MONSTERS+"hobgoblin")->config("tanked"),this_object());
}
 
init() {
  add_action("order","order"); 
  add_action("order","buy"); 
  add_action("read","read"); 
 ::init();
}

read(str) {
 if (str=="menu" || str=="sign") {
write(
     "#######################################################\n"+
     "                   DRUID LAKMIR'S BAR                  \n"+
     "#######################################################\n"+
     "We offer:\n\n"+
     "A.) Food and drinks for direct consumption:\n"+
     "1   Wine                                    400 coins \n"+
     "2   Beer                                     60 coins \n"+
     "3   Fishsoup                                500 coins \n"+
     "4   Muesly                                   40 coins \n"+
     "5   Coffee                                   50 coins \n"+
     "6   Water                                    20 coins \n"+
     "You can consume also in numbers...<buy 1> for the Wine.\n");
  return 1;
  }
}
order(str) {
  string name, short_desc,art, mess;
  int value, cost, strength, heal;
  object dummy;

  if (!str) {
    write("You might feel the chaos in this world..order what??\n");
    return 1;
  }
  if (str == "wine" || str == "1") {
    mess = "The wine makes you feel much better.... AHHHH";
    heal= 30;
    value = 400;
    strength = 10;
    art ="alko";
  } else if (str == "beer" || str=="2") {
    mess = "You enjoy the good taste of a good beer.... AHHHH";
    heal= 10;
    value = 60;
    strength = 8;
    art = "alko";
  } else if (str == "fishsoup" || str=="3") {
    mess = "MMMM.... Such a fishsoup tastes fine";
    heal = 60;
    value = 500;
    strength = 20;
    art = "food";
  } else if (str == "muesly" || str=="4") {
    mess = "WELL.... Such a muesly block tastes fine";
    heal = 10;
    value = 40;
    strength = 6;
    art = "food";
  } else if (str == "coffee" || str=="5") {
    mess = "WELL.... You feel your head getting clearer !";
    heal = 5;
    value = 50;
    strength = -6;
    art = "alko";
  } else if (str == "water" || str == "6") {
    mess = "WELL.... You feel your head getting clearer !";
    heal = 1;
    value = 20;
    strength = -2;
    art = "alco";
  } else {
    write("The bartender stares at you, saying: We don't have that.\n");
    return 1;
  }
 
  if (this_player()->query_money() < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (art=="alko") {
    if (!this_player()->drink_alcohol(strength)) {
      write("The bartender says: I think you've had enough.\n");  
      say(capitalize(this_player()->query_name())
       +" is thirsty but the bartender refuses.\n");
      return 1;
    }
  } else if (art=="soft") {
    if (!this_player()->drink_soft(strength)){
      write("The bartender says: Sorry, I don't think you have a cow stomach.\n");
      say(capitalize(this_player()->query_name())
       +" is thirsty but the bartender refuses.\n");
      return 1;
    }
  } else if (art=="food") {
    if (!this_player()->eat_food(strength)){
      write("The bartender says: I think you are sober.\n");
      say(capitalize(this_player()->query_name()) 
       +" is hungry but the bartender refuses.\n");
      return 1;
    }
  }
  write("You pay " + value + " coins.\n");
  this_player()->add_money(-value);
  this_player()->heal_self(heal);
  write(mess + ".\n");
  return 1;
}

light_text(str) {
  write("You hold the "+str+" to the candle of the table to light it.\n");
  say(capitalize(this_player()->query_name())+" lights a "+str+",\n"
    + "using the candle of the table.\n");
}
