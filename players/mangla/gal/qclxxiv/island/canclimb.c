/* copied from /obj to add climb tree functionality */
run_away() {		   /* this is great */
    object here;
    int i, j;

    if(query_wimpy()==-1) return;
    here = environment();
    i = 0;
    j = random(13);
    while(i<13 && here == environment()) {
	i += 1;
	j += 1;
	if (j > 13)
	    j = 1;
	if (j == 1) command("east");
	if (j == 2) command("west");
	if (j == 3) command("north");
	if (j == 4) command("south");
	if (j == 5) command("up");
	if (j == 6) command("down");
	if (j == 7) command("southeast");
	if (j == 8) command("southwest");
	if (j == 9) command("northeast");
	if (j == 10) command("climb oak");
	if (j == 11) command("climb beech");
	if (j == 12) command("climb birch");
	if (j == 13) command("northwest");
    }
    if (here == environment()) {
	say(this_object()->query_name()+ " tried, but failed to run away.\n", this_object());
	}
}

