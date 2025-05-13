reset(arg) {
  if (arg) return;
  set_light( 1);
}
 
short() {
 return "Temple speak-easy";
}
 
init() {
   add_action ("look", "look");
  add_action("move", "east"); 
  add_action ("order", "order"); 
  add_action ("order", "buy"); 
  add_action ("read", "read"); 
}
 
move() {
  object ob;
    this_player()->move_player("east#players/airborne/temple/levela/room1");
  return 1;
}
look(str){
   if(str == "stone" || str == "at stone"){
	write("A very old stone that looks like the front of a bar.\n");
	return 1;
	}
  else if (!str) {
	long();
	return 1;
  }
  else {
	write("Look at what?\n");
	return 1;
	}
   }
long() { write(
"Hidden behind the great barrels is this ancient speak-easy.\n"+
"The stone walls keep the room silenced from the noise outside.\n"+
"There is a long stone about chest high that looks like a bar and a\n"+
"strange sign with ancient symbols hangs above.\n"+
"	The obvious exits : east \n");
}
 read(str) {
if(str == "sign" || str == "symbols" || str == "strange sign") {
write("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n\n");
write("  Baal-Rog's Revenge                   - 8000        \n");
write("  Gut shaker!                          -  500        \n");
write("  Zombie knocker                       -  300        \n");
write("  Taste of Hell                        -   25        \n");
write("  Undead sensation                     -  100        \n");
write("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n\n");
  return 1;
}
}
order(str)
{
 string name, short_desc, mess;
   int value, cost, strength, heal;
 
 if (!str) {
  write("The room remains calm as the magic does not work.\n");
  return 1;
}
if (str == "undead" || str == "sensation" || str == "undead sensation") {
mess = "You feel as though you are walking in the world between life and death";
heal = 1;
value = 100;
strength = -2;
}
else if (str == "taste" || str == "hell" || str == "taste of hell") {
mess = "The taste of hell burns going down";
heal = 6;
value = 25;
strength = 2;
}
else if (str == "zombie" || str == "knocker" || str == "zombie knocker") {
mess = "A favorite drink of all the Zombies"; 
heal = 30;
value = 300;
strength = 10;
}
else if (str == "gut" || str == "shaker" || str == "gut shaker") {
mess = "Your stomach quivers and shakes";
heal = 50;
value = 500;
strength = 10;
}
else if (str == "baal-rog" || str == "revenge" || str == "baal-rog's revenge") {
mess = "The Baal-Rog himself couldn't down it any better";
heal = 115;
value = 8000;
strength = 15;
} 
else {
    write("The magic doesn't seem to work. Maybe you asked for the wrong drink?\n");
    return 1;
  }
 
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That would cost you " + value + " gold coins,\nwhich you don't have.\n");
    return 1;
  }
  if (strength > (call_other(this_player(), "query_level") + 2)) {
    if (strength > (call_other(this_player(), "query_level") + 5)) {
      /* This drink is *much* too strong for the player */
      say(call_other(this_player(), "query_name", 0) + " Calls for a " +
	  str + ", and immediately throws it up.\n");
      write("You call for a " + str + ", try to drink it, and throw up.\n");
    } else {
      say(call_other(this_player(), "query_name", 0) + " orders a " +
	  str + ", and spews it all over you!\n");
      write("You call for a " + str + ", try to drink it, and sputter it all over the room!\n");
    }
    call_other(this_player(), "add_money", - value);
    return 1;
  }
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("You get the feeling that you've had enough.\n");
    say(call_other(this_player(), "query_name", 0) + " calls for a " +
	str + " but the magic doesn't work.\n");
    
    return 1;
  }
  write("You pay " + value + " coins for a " + str + ".\n");
  say(call_other(this_player(), "query_name", 0) + " enjoys a " + str + ".\n");
  call_other(this_player(), "add_money", - value);
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
  return 1;
}
