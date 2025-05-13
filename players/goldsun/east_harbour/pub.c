/*  EASTERN HARBOUR PUB */

/* last edit: Goldsun 12.04.95 Bratislava   */

inherit "room/room";
 
void reset(int arg) {
   
  if (!arg){

   clone_list=({1,1,"billy","players/goldsun/east_harbour/billy",0,
	        2,1,"valerio","players/goldsun/east_harbour/valerio",0});
   set_light(1);

   short_desc="Old Cook's Pub";

   property=({"has_fire","no_fight","no_teleport"});

   long_desc=
    "You are in the Old Cook's Pub in Eastern Harbour. The pub is made\n"+
    "of oak wood. There are some tables and chairs. Over the entrance\n"+
    "you can see a painting of captain Cook and on the wall in front of\n"+
    "you a menu which gives you better information about food and drinks.\n"+
    "A nice fireplace with fire in the corner makes this pub very cosy.\n";
   smell="You smell oak wood";

   items=({
        "pub",long_desc,
        "painting","A painting of captain Cook",
	"fire","Ahh. It's pleasantly warm",
        "fireplace","There is a nice fire in it",
        "entrance","You enter through it",
        "wood","Old oak wood, maybe from Sherwood",
        "oak","It looks old",
        "sign","There is something written on it",
        "menu","A small iron sign with something written on it",
        "table","A brown wooden table",
        "tables","Brown wooden tables",
	"wall","There is the menu hanging on the wall",
        "chair","A small wooden chair",
        "chairs","Some small wooden chairs" });

   dest_dir=({"players/beardy/east_harbour/room/road002","east"});
 }
 ::reset(arg);       
}
 
init() {
  add_action("order","order"); 
  add_action("order","buy"); 
  add_action("read","read"); 
  add_action("sit","sit");
 ::init();
}


read(str) {
 if (str=="menu" || str=="sign") {
write(
     "()=========================================================)\n"+
     " |                    Old Cook's Pub                      |\n"+
     " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"+
     " |We offer:                                               |\n"+
     " |                                                        |\n"+
     " |      Foods and drinks for the direct consume:          |\n"+
     " |                                                        |\n"+
     " |1   Seafarer special                       2000 coins   |\n"+
     " |2   Whisky                                 1000 coins   |\n"+
     " |3   Wine                                    600 coins   |\n"+
     " |4   Rum                                     200 coins   |\n"+
     " |5   Beer                                     30 coins   |\n"+
     " |6   Lambs                                   600 coins   |\n"+
     " |7   Breather                                 40 coins   |\n"+
     " |8   Water                                    12 coins   |\n"+
     " |9   Cook's secret                           200 coins   |\n"+
     " |                                                        |\n"+
     " |You can consume also in numbers....<buy 3> for the Wine.|\n"+
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
   mess = "You are feeling strongly like old seafarer hook.... AHHHH";
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
  mess = "It taste like right sailor rum.... AHHHH";
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
  return 1;
}


int sit(string str){
 notify_fail("Sit where?\n");
 if (str=="down" || str=="down on chair" || str=="sit chair" ||
     str=="down chair")
 {
  write("You sit down on chair.\nWhat about to buy something?\n");
  say(this_player()->query_name()+" sits down on chair.\n");
  return 1;
 }
}

