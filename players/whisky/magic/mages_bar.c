
inherit "room/room";
   
 
reset(arg) {
   if (arg) return;
   set_light( 1);
   short_desc= "In the mages-bar";
   long_desc=
    "You have now entered the bar of the mages tower.\n"+
    "In front of you you can see some tables and chairs.\n"+
    "There is the menu hanging on the wall, which gives you\n"+
    "better information about food and drinks.\n"; 
    
    
    items=({
        "menu","A small iron sign with something written on it",
        "table","A brown wooden table",
        "tables","Brown wooden tables",
        "chair","A small wooden chair",
        "chairs","Some small wooden chairs" });

    dest_dir=({ "players/llort/guild/tower/hallway","north" });
        
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
     "                     THE MAGES BAR                     \n"+
     "#######################################################\n"+
     "We offer:\n\n"+
     "A.) Food and drinks for the direct consume:\n"+
     "1   Ambrosia                               4000 coins \n"+
     "2   Pangalactic garglblaster (HOT!)        2000 coins \n"+
     "3   Wine                                    200 coins \n"+
     "4   Beer                                     30 coins \n"+
     "5   Pizza                                   500 coins \n"+
     "6   Muesli                                   40 coins \n"+
     "7   Coffee                                   40 coins \n"+
     "8   Water                                    12 coins \n"+
     "9   Mages special (SP-boost)		    200 coins \n"+
     "You can consume also in numbers....<buy 1> for the Ambrosia.\n");
    
     
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
  if (str == "ambrosia" || str == "1") {
  mess = "The Ambrosia refreshes you.... AHHHH";
  heal = 100;;
  value = 4000;
  strength = 42;
  art ="alko";
}
  else if (str == "garglblaster" || str == "2") {
  if(15+random(15)+random(15)>=this_player()->query_con()) {
       write("As you taste the drink you get a UNCONTROLABLE urge to"+
             " run and run and run ...\n");
       shout(this_player()->query_name()+" screams in agony.\n");
       for(i=0;i<10;i++) this_player()->run_away();
       return 1;
  }
  mess = "#@*\"*&^$%@*&! You think your throat tries to leave you!!! OH YEA";
  heal= 150;
  value = 2000;
  strength = 50;
  art ="alko";
}
  else if (str == "wine" || str == "3") {
  mess = "The wine makes you feel much better.... AHHHH";
  heal= 30;
  value = 200;
  strength = 16;
  art ="alko";
}
  else if (str == "beer" || str=="4") {
  mess = "You enjoy the good taste of a good beer.... AHHHH";
  heal= 8;
  value = 30;
  strength = 3;
  art = "alko";
}
  else if (str == "pizza" || str=="5") {
  mess = "MMMM.... Such a pizza tastes fine";
  heal = 30;
  value = 500;
  strength = 20;
  art = "food";
}
  else if (str == "muesli" || str=="6") {
  mess = "WELL.... Such a muesli block tastes fine";
  heal = 5;
  value = 40;
  strength = 6;
  art = "food";
}
  else if (str == "coffee" || str=="7") {
  mess = "WELL.... You feel your head getting clearer !";
  heal = 0;
  value = 40;
  strength = -2;
  art = "alko";
}
  else if (str == "water" || str == "8") {
  mess = "WELL.... You feel your head getting clearer !";
  heal = 0;
  value = 12;
  strength = -1;
  art = "alco";
}
  else if (str == "special" || str == "9")
 {
  mess = "Your head twists like crazy, and the world seems to turn purple.";
  heal = 120;
  value = 200;
  strength = 6;
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
  if (art=="alko" || art=="special") {
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("The bartender says: I think you've had enough.\n");
    
    return 1;
  }
 }
  else if (art=="soft") {
  if (!call_other(this_player(),"drink_soft",strength)){
  write("The bartender says: Sorry, I don't think you have a cow stomach.\n");
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
  if(art=="special") this_player()->restore_spell_points(heal);
  else this_player()->heal_self(heal);
  write(mess + ".\n");
  if(strength==50) say(this_player()->query_name()+" groals a blaster, "+
       "and leaps off to run a round on the ceiling.\n");
  return 1;
}
