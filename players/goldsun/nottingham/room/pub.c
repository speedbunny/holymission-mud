inherit "room/room";
 
reset(arg) {
  if (!arg){
   set_light( 1);
   short_desc= "Nottingham pub";
   property=({"has_fire"});
   long_desc=
    "You are in the local pub. There is a nice fire here.\n"+
    "In front of you you can see some tables and chairs.\n"+
    "On the wall you can see the menu, which gives you better\n"+
    "information about the food and drinks in this establishment.\n";
    
    
    items=({
        "sign","There is something written on it",
        "menu","A small iron sign with something written on it",
        "table","A brown wooden table",
        "tables","Brown wooden tables",
	"wall","There is the menu hanging on the wall",
        "chair","A small wooden chair",
        "chairs","Some small wooden chairs" });

    dest_dir=({ "players/goldsun/nottingham/room/road1","north" });
 }
 ::reset(arg);       
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
     "()---------------------------------------------------------)\n"+
     " |                 NOTTINGHAM local PUB                   |\n"+
     " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"+
     " |We offer:                                               |\n"+
     " |                                                        |\n"+
     " |      Foods and drinks for the direct consume:          |\n"+
     " |                                                        |\n"+
     " |1   Wine                                    100 coins   |\n"+
     " |2   Beer                                     20 coins   |\n"+
     " |3   Roasted pork                             40 coins   |\n"+
     " |4   Nottingham mix                          150 coins   |\n"+
     " |                                                        |\n"+
     " |You can also use numbers....<buy 1> for the wine.       |\n"+
     "()---------------------------------------------------------)\n");
    
     
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
 if (str == "wine" || str == "1") {
  mess = "The wine makes you feel much better.... AHHHH";
  heal= 15;
  value = 100;
  strength = 12;
  art ="alko";
}
  else if (str == "beer" || str=="2") {
  mess = "You enjoy the good taste of a good beer.... AHHHH";
  heal= 7;
  value = 20;
  strength = 3;
  art = "alko";
}
  else if (str == "roasted pork" || str == "pork" || str=="3") {
  mess = "WELL.... Such a Roasted pork tastes fine";
  heal = 5;
  value = 40;
  strength = 6;
  art = "food";
}
  else if (str == "nottingham mix" || str == "mix" || str=="4") {
  mess = "DAMN. That taste like a Rockland herps";
  heal = 85;
  value = 150;
  strength = 5;
  art = "special";
}

 
else {
    write("The bartender stares at you, saying: We don't have that.\n");
    return 1;
  }
 
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (art=="alko" ) {
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("The bartender says: I think you've had enough.\n");
    
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

  write("You pay " + value + " coins.\n");
  this_player()->add_money(-value);
  if (art=="special")  this_player()->restore_spell_points(heal);
    else this_player()->heal_self(heal);
  write(mess + ".\n");
  return 1;
}
