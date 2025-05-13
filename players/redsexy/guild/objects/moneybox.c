#include "/players/redsexy/guild/guilddefs.h"

int numcoins;

id(arg) {
  return arg == "box" || arg == "money box" ||
    arg == "donation box";
}

short() { return "A donation box"; }

long() {
  string how_many;
  write("    This box is meant to hold money for those that need it. If\n");
  write("you have coins to spare, please \"donate <amount>\" into the\n");
  write("box. If you need coins, type \"accept <amount>\".\n");
  switch(numcoins) {
    case 0:
      how_many = "are no coins";
      break;
    case 1:
      how_many = "is one coin";
      break;
    default:
      how_many = "are " + numcoins + " coins";
      break;
  }
  write("    Currently there " + how_many + " in the box.\n");
}

reset(arg) {
  if(arg) return;
  restore_object(GLD + "text/money");
}

init() {
  add_action("donate", "donate");
  add_action("accept", "accept");
}

donate(arg) {
  int num;
  string how_many;
  if(sscanf(arg, "%d", num)) {
    if(TP->query_money() >= num) {
      if(num > 0) {
	if(num ==1) how_many = "one coin";
	else how_many = num + " coins";
	TP->add_money(- num);
	numcoins += num;
	write("You donate " + how_many + ".\n");
	say(TP->NAME + " graciously donates " + how_many + ".\n");
        log_file("guild_donate",
		   TP->LEVEL + " " + TP->SNAME + " donated " +
		   how_many + " on " + ctime(time()) + ".\n");
	save_object(GLD + "text/money");
	return 1;
      }
      write("You must donate a positive amount.\n");
      return 1;
    }
    write("You do not have that much money.\n");
    return 1;
  }
  write("Donate how much?\n");
  return 1;
}

accept(arg) {
  int num;
  string how_many;
  if(sscanf(arg, "%d", num)) {
    if(num <= numcoins) {
      if(num > 0) {
	if(num == 1) how_many = "one coin";
	else how_many = num + " coins";
	write("You take " + how_many + " from the donation box.\n");
	say(TP->NAME + " takes " + how_many + " from the donation box.\n");
	write_file(LOGS + "guild_donate",
		   TP->LEVEL + " " + TP->SNAME + " accepted " +
		   how_many + " on " + ctime(time()) + ".\n");
	TP->add_money(num);
	numcoins -= num;
	save_object(GLD + "text/money");
	return 1;
      }
      write("You may only accept a positive amount.\n");
      return 1;
    }
    write("The box does not contain that much money.\n");
    return 1;
  }
  write("Accept how much?\n");
  return 1;
}
