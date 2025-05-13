inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light( 1);
}
 
short() {
 return "The Brown Boar";
}
 
init() {
  add_action("move"); add_verb ("south");
  add_action ("order"); add_verb ("order");
  add_action ("order"); add_verb ("buy");
  add_action("kill","kill");
  add_action ("read"); add_verb ("read");
  add_action("brzbrz","look");
  add_action("brzbrz","exa"); /* jep what  shells brzbrz sounds tja ok */
  smell = "A lot of alcohol must have been spilled here...\n";
}
 
brzbrz(str) {
  if (str=="barkeep" || str=="at barkeep") {
     write("A fat, jovial barkeep stands behind the counter waiting for\n"+
           "your order.\n");
     return 1;
    }
    else {
    return;
 }
}
kill(str) {
  if (str=="barkeep") {
     write("The barkeep mutters something about drunken adventurers and\n"+
           "pushes you back behind the counter.\n");
     return 1;
  }
  else {
  return;
}
}
move() {
  object ob;
call_other(this_player(),"move_player","south#players/silas/fghant/keidall3");
  return 1;
}
 
 
long() {
write("Welcome to the Brown Boar!\n"+
"This is a drinking establishment where you can relax and enjoy our brews.\n"+
"A barkeep stands behind the counter waiting for your order. On the back\n"+
"wall you can see a list of drinks; type <read menu> to read it.\n"+
 "The only obvious exit is to the south.\n");

}
 read(str) {
if(str == "menu") {
write("#####################################################\n");
write("              T H E  B R O W N  B O A R              \n");
write("#####################################################\n\n");
write("    Plutonium Punch.................4000 coins        \n");
write("    Moonshine.......................450 coins         \n");
write("    Goesser beer....................50 coins          \n");
write("    Jolt cola.......................350 coins        \n\n");
write("#####################################################\n");
  return 1;
}
}
order(str)
{
 string name, short_desc, mess;
   int value, cost, strength, heal;
 
 if (!str) {
  write("I can't read your mind; what do you want to order?\n");
  return 1;
}
if (str == "cola") {
mess = "Your surroundings don't look quite as blurred as they did before";
heal = 0;
value = 350;
strength = -2;
}
else if (str == "beer") {
mess = "The brew slightly numbs your senses as it runs down your throat";
heal= 8;
value = 50;
strength = 4;
}
else if (str == "moonshine") {
mess = "You feel like you're about to puke";
heal = 30;
value = 450;
strength = 8;
}
else if (str == "punch") {
mess = "Your skin starts to glow a strange fluorescent green color";
heal = 80;
value = 4000;
strength = 5;
}
else {
    write("We don't have that, try something else.\n");
    return 1;
  }
 
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (strength > (call_other(this_player(), "query_level") + 2)) {
  if (strength > (call_other(this_player(), "query_level") + 5)) {
      say(call_other(this_player(), "query_name", 0) + " orders a " +
	  str + ", and immediately throws it up.\n");
      write("You order a " + str + ", try to drink it, and throw up.\n");
    } else {
      say(call_other(this_player(), "query_name", 0) + " orders a " +
	  str + ", and spews it all over you!\n");
      write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
    }
    call_other(this_player(), "add_money", - value);
    return 1;
  }
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("The bartender says: I think you've had enough.\n");
    say(call_other(this_player(), "query_name", 0) + " asks for a " +
	str + " but the zombie refuses.\n");
    
    return 1;
  }
  write("You pay " + value + " coins for a " + str + ".\n");
  say(call_other(this_player(), "query_name", 0) + " enjoys a " + str + ".\n");
  call_other(this_player(), "add_money", - value);
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
  return 1;
}
