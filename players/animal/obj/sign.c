id(str) { return str == "sign"; }
 
short() {return "A large sign explaining the rules"; }
 
long() { 
write("\n");
write("To make a party type 'register'. You will then be asked for a name\n");
write("the party will go by. Use any name you want as long as it is in\n");
write("good taste. To divide out the xp type in 'divvy'. Do this whenever\n");
write("you kill something or want to divide the xp. To quit the party just\n");
write("drop the symbol. When a player dies no divvy will be called because\n");
write("the player who died does not need the xp. Link death is handled by\n");
write("calling a divvy and then dropping the player who got link death.\n");
write("In order to prevent cheating and to promote teamwork, if a player\n");
write("is idle for more than 4 minutes that player is booted from the\n");
write("party with NO divvy called. You cannot advance in level\n");
write("while in a party for obvious reasons. All players in the room when\n");
write("the party is registered will be in the party. You CANNOT be in\n");
write("two parties at one time. Higher level characters get more of the xp\n");
write("because they contribute more to the party.\n");
write("\n");
}
