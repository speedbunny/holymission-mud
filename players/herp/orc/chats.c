get_chats() {

   if (!chats) {
	chats=allocate(5);
	chats[0]="Orc says: Yummy, here comes a little snack !\n";
	chats[1]="Orc says: Tell Shaggratt to heat to oven !\n";
	chats[2]="Orc says: Get lost, crap !\n";
	chats[3]="Orc says: Shall we eat him raw ?\n";
	chats[4]="Orc says: Bah, I don't like it when the food smells this way.\n";
    }
    return chats;
}
