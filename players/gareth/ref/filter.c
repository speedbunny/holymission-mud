inherit "room/room";

int k;

int check(); // Predeclaration of function or prototyping

void reset(int arg){
    ::reset(arg);
    k = 0; //This is to reset the number to 0 so it will not accumlate
    check(); // Calling the check function to check number of mace of dooms
    if(arg) return;
    set_light(1);
    short_desc = "Filter array example room";
    long_desc = 
    "This room clones a mace if there's less than 3 on the\n\
game at a given time. Read the file, it hopefully will\n\
explain what the filter_array does.\n";
}

int check(){
    object *u; // The array of players or users() on the game
    /* The i and j variables are for: i is for a loop that */
    /* goes on for the number of players with the mace */
    /* j is the number of people with the mace */
    int i, j;
    /* The filter array filters the array of users() or players */
    /* and it runs it through the process: filter_items which   */
    /* checks for people with the mace of doom.                 */
    u = filter_array(users(), "filter_items", this_object());
    j = sizeof(u);
    if(k<3){ // If there are less than 3 maces on players
	move_object(clone_object("/players/colossus/weapons/mace"),
	  this_object());
	return 1;
    }
}

/* This is the "filter" which filters out those with maces */
/* The rest is pretty explanatory */
int filter_items(object ob){
    object *inv;
    int i, j;
    inv = all_inventory(ob);
    j = sizeof(inv);
    for(i=0;i<j;i++)
	if(inv[i]->query_name()=="mace of doom")
	    k++;
    return 1;
}

/* I just added this for my own benefit so I can check */
/* if the code was working perfectly */
int query_number(){
    return k;
}
