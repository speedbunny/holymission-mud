inherit "room/room";

int *counters;
string *stuff,*stuff_ids;
int *maxcnt,no_south;

reset(arg) {
    if(!arg) {
	set_light(1);
	property = "no_teleport";
	short_desc="Wuntvor's Storeroom";
	long_desc=
	"This is the storeroom of Wuntvor's Magic Shop.  It is pure chaos in here.  "+
	"Lightning bolts bounce around the room, giving it an eerie glow.\n";
	dest_dir=({ "/players/saffrin/guild/rooms/mshop","south" });
	stuff=({ 
	  "players/llort/animals_stuff/diamond",
	  "players/llort/animals_stuff/follow",
	  "players/llort/animals_stuff/judge",
	  "players/llort/animals_stuff/eye",
	  "players/llort/animals_stuff/football",
	  "players/llort/animals_stuff/lamp",
	  "players/llort/guild/obj/chalk",
	});
	maxcnt=({ 5,3,10,4,10,5,10 });
	stuff_ids=({ "diamond","ring","judge","eye","ball","lamp","chalk" });
	no_south=0;
    }
    fill_room();
}


fill_room() {
    int i,j,res;
    object *dir;

    res=0;
    counters=({ 0,0,0,0,0,0,0 });
    dir=all_inventory(this_object());
    for(i=0;i<sizeof(dir);i++) {
	for(j=0;j<sizeof(counters);j++) 
	    if(dir[i]->id(stuff_ids[j])) {
		counters[j]++;
		break;
	    }
    }
    for(i=0;i<sizeof(counters);i++) {
	for(j=counters[i];j<maxcnt[i];j++)
	    if(random(2)) {
		move_object(clone_object(stuff[i]),this_object());
		res=1;
	    }
    }
    if(res) tell_room(this_object(),"An object magically appears.\n");
}

got(arg) {
    return member_array(arg,stuff_ids)!=-1;
}

init() {
    ::init();
    if(!this_player()->id("wuntvor")) {
	schubs();
    } else {
	add_action("south","south");
    }
}

schubs() {
    object wu;
    write("As you enter the room, something falls down, rattling.\n");
    if(wu=present("wuntvor",
	find_object("/players/saffrin/guild/rooms/mshop")))
{
	command("north",wu);
    say("Wuntvor says: Hey, you little thief, drop all of my stuff.\n");
    call_out("go_s",1,wu);
    wu->set_aggressive(1);
    wu->attacked_by(this_player());
} else if(wu=present("wuntvor",this_object())) {
    no_south=1;
    say("Wuntvor says: Hey, you little thief, drop all my stuff.\n");
    call_out("go_s",1,wu);
    wu->set_aggressive(1);
    wu->attacked_by(this_player());
}
}

go_s(wu) {
    object *dir;
    int i;
    if(!wu) return;
    if(!(dir=all_inventory(this_object()))) {
	no_south=0;
	wu->set_aggressive(0);
	wu->move_player("south#players/saffrin/guild/rooms/mshop");
	return;
    }
    for(i=0;i<sizeof(dir);i++) 
	if(query_ip_number(dir[i])) { 
	    call_out("go_s",1,wu);
	    return;
	}
    no_south=0;
    wu->set_aggressive(0);
    wu->move_player("south#players/saffrin/guild/rooms/mshop");
}

south() {
    if(no_south) return 1;
}
