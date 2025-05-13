inherit "room/room";
 
reset(arg) {
  if (!arg){
   set_light( 1);
   short_desc= "Rockland castle pub";
   property=({"has_fire"});
   long_desc=
    "You are in the pub. There is a nice fire here.\n"+
    "On the wall you can see the menu, which gives you better\n"+
    "information about the drinks in this establishment.\n";
    
    
    items=({
        "sign","There is something written on it",
        "menu","A small iron sign with something written on it",
	"wall","There is the menu hanging on the wall" });

    dest_dir=({ "players/goldsun/green_island/room/residence8","south" });
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
     " |                 Rockland castle pub                    |\n"+
     " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"+
     " |We offer:                                               |\n"+
     " |                                                        |\n"+
     " |      Foods and drinks for the direct consume:          |\n"+
     " |                                                        |\n"+
     " |1   Wine                                    150 coins   |\n"+
     " |2   Beer                                     80 coins   |\n"+
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

 if (!str) {
  write("You might feel the chaos in this world..order what??\n");
  return 1;
 }
 if (str == "wine" || str == "1") {
  mess = "The wine makes you feel much better.... AHHHH";
  heal= 15;
  value = 150;
  strength = 12;
  art ="alko";
 }
  else if (str == "beer" || str=="2") {
  mess = "You enjoy the good taste of a good beer.... AHHHH";
  heal= 7;
  value = 80;
  strength = 3;
  art = "alko";
 } else {
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


  write("You pay " + value + " coins.\n");
  this_player()->add_money(-value);
  this_player()->heal_self(heal);
  write(mess + ".\n");
  return 1;
}
