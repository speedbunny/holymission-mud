#pragma strict_types

void reset(int arg) {
    if(arg) return;
    move_object(this_object(), "/players/colossus/guild/rooms/home");
    enable_commands();
}

string get_spouse(string str) {
    string *list;
    string sp,junk;
    int i,l;
    list = explode(read_file("/players/colossus/TESTLOG")+"\n", "\n");
    l=sizeof(list);
    for(i=0;i<l;i++) {
	if(sscanf(list[i],"%s: " + str + " & %s: %s",junk,sp,junk)==3) return sp;
	if(sscanf(list[i],"%s: %s & " + str + ": %s",junk,sp,junk)==3) return sp;
	if(sscanf(list[i], "%s 1994: "+str+" & %s: %s", junk, sp, junk)==3) return sp;
    }
    write("Nothing found.\n");
}

void catch_tell(string str) {
    string me,them,junk;
    string *list;
    status f;
    int l;
    object ob, name;
    if(!sscanf(str, "%s says: give me ring", me)) return;
me = lower_case(me);
ob=find_living(me);
    if(!ob || !interactive(ob)) return;
    if(present("wedding_ring", ob)) return;
    if(get_spouse(me)){
	object ring;
	move_object(ring = clone_object("/players/colossus/obj/ring"),
	  this_player());
	ring->init_arg();
    }
}
