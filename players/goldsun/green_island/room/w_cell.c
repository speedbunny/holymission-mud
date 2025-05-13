inherit "/room/room";
#define TP this_player()
#define TO this_object()
#define PATH "/players/goldsun/green_island/room/"
#define NUM_OF_AXE 3

void lost_all(){
    object *all;
    int i;

    all=all_inventory();
    for(i=0;i<sizeof(all);i++){
	if (all[i]->query_goldsun_special()) destruct(all[i]);
    }
    return;
}


void make_axes(){
    object axe;
    int i,j;
    j=random(NUM_OF_AXE);
    for(i=0;i<NUM_OF_AXE;i++){
	axe=clone_object("/players/goldsun/green_island/obj/genAxe");
	axe->set_type(i);
	axe->set_name(axe->query_type()+" axe");
	axe->set_alias("axe");
	if (j==i) axe->set_alt_name("goldsun_quest_axe");
	axe->set_short("A "+axe->query_type()+" axe");
	axe->set_long("The axe looks nice.\n");
	axe->set_value(random(100)+100);
	axe->set_weight(1);
	transfer(axe,TO);
    }
}


reset(arg){

    ::reset(arg);
    if (arg) return;
    set_light(1);
    short_desc=("In a cellar");
    long_desc=
    ("You are in a cellar under the wood-cutter cottage. There are many\n"+
      "shelfs on the walls here. A sign is hanging down from the ceiling.\n");

    smell="You smell dump air.";

    dest_dir=({ PATH + "cottage",   "up" });

    items=({"shelf","A shelf made of wood. There are many axes on it",
      "shelfs","They are made of wood. There are many axes on it",
      "sign","There is something written on it",
      "wood","It is very rare teak"
    });
    make_axes();

}

init(){
    ::init();
    add_action("read","read");
    add_action("get","get");
    add_action("get","take");
}


int get(string str){
    object axe;

    notify_fail("Get what?\n");
    if (!str) return 0;
    if (str=="all"){
	write("You cannot take all !\n");
	return 1;
    }
    if (present(str,TO)){
	axe=present(str,TO);
	if (transfer(axe,TP)==1) write("You can't carry that much.\n");
	else{
	    write("Ok.\n");
	    lost_all();
	}
	write("Axes disappear in a fog.\n");
	return 1;
    }
    write("That is not here.\n");
    return 1;
}

int read(string str){
    if (str=="sign" || str=="shelf"){
	write("Taking one, losing all\n");
	say(TP->query_name()+" reads a sign.\n");
	return 1;
    }
}


