#define NAME "saffrin"
#define DEST "room/mount_top2"
id(str) { return str == "tower"; }

short() {
    return "Saffrin's Rose Petal Tower";
}

long() {
    write("\nThis is Saffrin's Rose Petal Tower.  It is a place where reality and\n");
    write("and romance meet.  Secret loves share sweet kisses in the shadows behind\n");
    write("the rose colored stone wall.  The front arch of the castle has beautiful\n");
    write("hand carved roses etched in the stone.  The tower seems to rise to the\n");
    write("heavens, where the cupids of romance may watch over it.  The corner stone\n");
    write("has 'E + S' carved into it.  Love pours from every inch of the castle.\n");
    write("The castle gates are closed right now.  There is a sign on the door that\n");
    write("reads: Please, do not disturb.\n\n");
}

init() {
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("Saffrin is a little busy.  Her tower is not quite ready to be opened for the public.\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
}
