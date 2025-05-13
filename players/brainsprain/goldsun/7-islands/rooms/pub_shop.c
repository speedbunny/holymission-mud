inherit "/obj/std_shop";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

int i;
void reset(int arg)
{
  ::reset(arg);
  short_desc = "In the hut";
  long_desc = (
"You have entered small hut.  The walls are made of mud bricks "+
"and the floor is made of spruce wooden lathes.  This is a place "+
"where Zuzana trades and buys things.  You can also buy a drinks here.  "+
"There is a sign on the wall saying:\n"+
"Shop commands: list, buy <item>, buy <number>\n"+
"Pub commands : read menu, order <item>, order <number>\n");

 set_light(1);
   store = ir+"/main_store";
   keeper = "Zuzana";
   maxlist=35;

  items = ({
    "walls","The walls are made of mud bricks",
    "desk","It's a wooden desk",
    "bottom","It's made of spruce wooden lathes",
    "lathes","They are spruce wooden",
    "zuzana","She is standing behind the desk smiling at you",
    "sign","Type 'list' or 'read menu' for more information !"
       });

  dest_dir = ({ PATH+"coast4","out" });

  move_object(clone_object("/obj/torch"),query_store());
   move_object(clone_object("/players/cashimor/objects/match"),query_store());

  if (!present("trashcan",this_object()))
     move_object(clone_object("/players/whisky/shops/trashcan"),TO);
}

query_property(arg)
{
   return arg=="no_fight";
 }

init() {
  add_action("order","order");
  add_action("read","read");
 ::init();
}

read(str) {
 if (str=="menu" || str=="sign") {
write(
     "()==========================================================)\n"+
     " |We offer:                                                 |\n"+
     " |                                                          |\n"+
     " |      Foods and drinks for the direct consume:            |\n"+
     " |                                                          |\n"+
     " |1   Seafarer special                       2000 coins     |\n"+
     " |2   Whisky                                 1000 coins     |\n"+
     " |3   Wine                                    600 coins     |\n"+
     " |4   Rum                                     200 coins     |\n"+
     " |5   Beer                                     30 coins     |\n"+
     " |6   Lambs                                   600 coins     |\n"+
     " |7   Breather                                 40 coins     |\n"+
     " |8   Water                                    12 coins     |\n"+
     " |9   Cook's secret                           200 coins     |\n"+
     " |                                                          |\n"+
     " |You can consume also in numbers....<order 3> for the Wine.|\n"+
     "()=========================================================)\n");


  return 1;
  }
}
order(str)
{
 string name, short_desc,art, mess;
   int value, cost, strength, heal,i;
   object dummy;
 if (!str) {
  write("You might feel the chaos in this world..order what??\n");
  return 1;
}
  if (str == "seafarer special" || str=="special" || str=="seafarer"
                 || str == "1")
  {
   mess = "You are feeling strongly like old seafarer Hook.... AHHHH";
   heal = 130;;
   value = 2000;
   strength = 52;
   art ="alko";
  }
  else if (str == "whisky" || str == "2") {
  mess = "You feel special herbs in it.... AHHHH";
  heal= 80;
  value = 1000;
  strength = 40;
  art ="alko";
 }
  else if (str=="wine" || str=="3"){
  mess = "The wine makes you feel much better.... AHHHH";
  heal= 70;
  value =600;
  strength = 30;
  art ="alko";
 }
  else if (str == "rum" || str == "4") {
  mess = "It tastes like sailors rum ... AHHHH";
  heal= 30;
  value = 200;
  strength = 15;
  art ="alko";
}
  else if (str == "beer" || str=="5") {
  mess = "You enjoy the good taste of a good beer.... AHHHH";
  heal= 8;
  value = 30;
  strength = 3;
  art = "alko";
}
  else if (str=="lambs" || str=="lamb" || str=="6") {
  mess = "MMMM....";
  heal = 35;
  value = 600;
  strength = 25;
  art = "food";
}
  else if (str == "breather" || str=="7") {
  mess = "WELL.... This breather tastes fine";
  heal = 5;
  value = 40;
  strength = 4;
  art = "food";
}
  else if (str == "water" || str == "8") {
  mess = "WELL.... You feel your head getting clearer !";
  heal = 0;
  value = 12;
  strength = -1;
  art = "alco";
}
  else if (str == "secret" || str=="cooks secret" || str=="Cooks secret"
                || str == "9")
 {
  mess = "You feel immortal force in body";
  heal = 90;
  value = 200;
  strength = 7;
  art = "special";
}


else {
    write(keeper+" stares at you, saying: We don't have that.\n");
    return 1;
  }

  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (art=="alko" || art=="special") {
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write(keeper+" says: I think you've had enough.\n");

    return 1;
  }
 }
  else if (art=="soft") {
  if (!call_other(this_player(),"drink_soft",strength)){
  write(keeper+" says: Sorry, I don't think you have a cow stomach.\n");
  return 1;
  }
}
  else if (art=="food") {
  if (!call_other(this_player(),"eat_food",strength)){
  write(keeper+" says: I think you are sober.\n");
  say(this_player()->query_name()+" is hungry but "+keeper+" refuses.\n");
  return 1;
  }
}

  write("You pay " + value + " coins.\n");
  this_player()->add_money(-value);
  if(art=="special") this_player()->restore_spell_points(heal);
  else this_player()->heal_self(heal);
  write(mess + ".\n");
  return 1;
}








