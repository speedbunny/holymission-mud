
inherit "room/room";
   
 
reset(arg) {
   if (arg) return;
   set_light(1);
   short_desc= "At the counter of the vampirebar";
   long_desc=
       "You right in front of the vampire bar, the bartender stares at\n" +
       "you with glooming eyes. He says: Read the menu.\n";
   items=({
       "bartender","A vampire servin blood",
       "bar","The vampire bar",
       "barkeeper","A vampire servin blood",
         });
   dest_dir=({ 
       "players/sherman/hills/hill2","north",
       "players/sherman/darkl9","west",
            });
}
 
init() {
  add_action("order","order"); 
  add_action("order","buy"); 
  add_action("read","read"); 
 ::init();
}


read(str) {
 if (str=="menu") {
write(
     "!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!\n"+
     "                    THE BLOOD PAPER                    \n"+
     "?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?\n"+
     "We offer:\n\n"+
     "1   Dragonblood                            2000 coins \n"+
     "2   Humanblood                              400 coins \n"+
     "3   Orcblood                                 30 coins \n"+
     "4   Elfblood                                 60 coins \n"+
     "5   Dragonsteak                             600 coins \n"+
     "6   Goblinflesh                              50 coins \n"+
     "7   Lichsoup                                400 coins \n");
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
  if (str == "dragonblood" || str == "1") {
  mess = "You feel like a hero as you drink the pure, darkred liquid! Hmm ..";
  heal = 300;
  value = 2000;
  strength = 15;
  art ="alko";
}
  else if (str == "humanblood" || str == "2") {
  mess = "You feel like a canibal as you poor down the blood.";
  heal= 60;
  value = 400;
  strength = 6;
  art ="alko";
}
  else if (str == "orcblood" || str=="3") {
  mess = "You feel like vomiting as you drink that brew.";
  heal= 12;
  value = 30;
  strength = 3;
  art = "alko";
}
  else if (str == "elfblood" || str=="4") {
  mess = "You feel like an orc as while you drink your cup of elfblood.";
  heal = 1;
  value = 60;
  strength = -6;
  art = "alko";
}
  else if (str == "dragonsteak" || str=="5") {
  mess = "The flesh seems to melt on your tounge.";
  heal = 60;
  value = 600;
  strength = 20;
  art = "food";
}
  else if (str == "goblinflesh" || str=="6") {
  mess = "You gasp as you eat the ugly flesh.";
  heal = 10;
  value = 50;
  strength = 6;
  art = "food";
}
  else if (str == "lichsoup" || str="7") {
  mess = "You hardly can stand the urge to puke as the eyes in that brew"+
         " stare at you.";
  heal = 120;
  value = 400;
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
  if (art=="alko") {
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
  else if (art=="food" || "special") {
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
  write(mess + "\n");
  return 1;
}
