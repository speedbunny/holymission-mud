/* Main file of Colossus@HM's quest. Debugging and security */
/* checks have been installed. Do not edit without commenting */
/* the changes and contact Colossus about the changes made. */

inherit "room/room";

object captain;
string murderer, murder_weap, murder_room;
string murder_victim;
int repeat, in_progress, saying;

void init(){
    ::init();
    add_action("say", "say");
    add_action("say", "'");
    add_action("say", "\"");
    add_action("say"); add_xverb("'");
    // Purely for debugging purposes. If a bug occurs just
    // get a lord or arch to use these functions.
    if(this_player()->query_wizard() &&
      this_player()->query_level()>=40){
	add_action("show_solution", "show");
	add_action("quest_people", "questers");
    }
}

void reset(int arg){
    ::reset(arg);
    saying = 0;
    repeat = 0;
    in_progress = 0;
    if(!present("thain")){
	move_object(
	  clone_object("/players/colossus/mearth/shire/quest/guard_captain"),
	  this_object());
    }
    if(arg) return;
    set_light(1);
    short_desc = "Thain's office";
    long_desc =
    "This small room serves as the office for the Thain of the Shire.\n"+
    "A wooden book shelf is set against the east wall, filled with\n"+
    "books and paper. Near the south wall, next to it sits a large\n"+
    "wooden desk and a wooden chair.\n";

    dest_dir= ({
      "/players/colossus/mearth/shire/quest/hall", "north",
    });

    items = ({
      "shelf", "The shelf contains files and information regarding the poltical\n"+
      "affairs of the city, none of which are of any interest to you",
      "desk", "An oak wood desk with a smooth surface for writing",
      "chair", "The oak wood chair is old but steady",
      "book", "The books do not interest you",
      "paper", "The paper is a half-written warrant for the arrest of\n"+
      "a fugitive murderer",
    });
    if(!present("note")){
	move_object(
	  clone_object("/players/colossus/mearth/shire/quest/mnote"),
	  this_object());
    }
    property = ({ "no_steal", "no_fight", "no_clean_up" });
}

void restart_game(){
    in_progress=0;
    repeat=0;
}

void set_in_progress(int amt){ in_progress=amt; }

int query_in_progress(){ return in_progress; }
string query_murderer(){ return murderer; }
string query_murder_weap(){ return murder_weap; }
string query_murder_room(){ return murder_room; }
string query_murder_victim(){ return murder_victim; }

static string show_solution(){
    if((int)this_player()->query_level()>=40){
	write(murderer+"#"+murder_weap+"#"+murder_room+"#\n");
	return murderer +","+murder_weap+","+murder_room;
    }
}

int scan_string(string scan, string str){
    string *temp;
    int fin;

    fin=0;
    temp=explode(str, " ");
    if(member_array(scan, temp)>-1) fin=1;
    if(member_array(scan+"?", temp)>-1) fin=1;
    if(member_array(scan+".",temp)>-1) fin=1;
    if(member_array(scan+",",temp)>-1) fin=1;
    if(member_array(scan+"!",temp)>-1) fin=1;
    return fin;
}

void dispatch_witness(){
    object old_wit;
    old_wit = find_living("old gaffer");
    if(old_wit) 
	destruct(old_wit);
    old_wit = find_living("little hobbit girl");
    if(old_wit)
	destruct(old_wit);
    old_wit = find_living("hobbit traveller");
    if(old_wit) destruct(old_wit);
    call_out("witness",2,0);
    call_out("witness",4,1);
    call_out("witness",6,2);
}

void witness(string num){
    object wit;
    int i;

    wit=clone_object("/players/colossus/mearth/shire/quest/witness"+num);
    move_object(wit, "/players/colossus/mearth/shire/quest/hall"+(num+1));
    for(i=1;i<4;i++)
	environment(wit)->unset_done(i);
    wit->set_murderer(murderer);
    wit->set_murder_weap(murder_weap);
    wit->set_murder_room(murder_room);
    tell_room(environment(wit),
      wit->query_name()+" is brought in.\n");
    return;
}

void start_murder(){
    int val, val1, val2, val3;
    string *killers, *weapons, *places, *victim;

    killers=
    ({"johnny", "fatty", "jolly", "todo", "fents"});
    weapons=
    ({"dagger", "axe", "hammer", "rope", "sword"});
    places=
    ({"harbor", "island", "tree", "gate", "forest"});
    victim=({
      "odie the dog", "winnie the pooh", "billy the kid", "charlie brown",
      "garfield the cat"});
    val=random(5);
    murderer=killers[val];
    val1=random(5);
    murder_weap=weapons[val1];
    val2=random(5);
    murder_room=places[val2];
    val3=random(5);
    murder_victim=victim[val3];
    return;
}

void tell_story(){
    if(!in_progress){
	start_murder();
    }
    if(saying){
	tell_room(this_object(),
	  "Thain says: I'm already telling you about the murder!\n");
    }
    saying = 1;
    tell_room(this_object(),
      "Thain says: Well here is what we know so far..\n");
    tell_room(this_object(),
      "Thain says: "+
      capitalize(query_murder_victim())+
      " was found dead last night.\n");
    tell_room(this_object(),
      "Thain says: The body was found in one of the rooms in the Green Dragon.\n");
    tell_room(this_object(),
      "Thain says: But we have reasons to believe that the actual\n");
    tell_room(this_object(),
      "Thain says: site of the murder is elsewhere.\n");
    tell_room(this_object(),
      "Thain pauses to catch his breath.\n");
    call_out("part2",6);
}

void part2(){
    tell_room(this_object(),
      "The Thain continues his story.\n");
    remove_call_out("tell_story");
    call_out("part3", 4);
}

void part3(){
    tell_room(this_object(),
      "Thain says: We were able to narrow down the suspects to 5.\n");
    tell_room(this_object(),
      "Thain says: Johnny, Fatty, Jolly, Todo, and Fents.\n");
    tell_room(this_object(),
      "Thain says: Write it down, I hate repeating myself.\n");
    tell_room(this_object(),
      "Thain waits as you write down the names.\n");
    remove_call_out("part2");
    call_out("part4",6);
}

void part4(){
    tell_room(this_object(),
      "Thain says: We also narrowed down the possible weapons.\n");
    tell_room(this_object(),
      "Thain says: Dagger, axe, hammer, rope, and sword.\n");
    tell_room(this_object(),
      "Thain says: Remember those.\n");
    tell_room(this_object(),
      "Thain gets off his chair and walks around a bit.\n");
    remove_call_out("part3");
    call_out("part5",6);
}

void part5(){
    tell_room(this_object(),
      "Thain says: Here are the probable sites of the murder.\n");
    tell_room(this_object(),
      "Thain says: Pier, party tree, forest, island.\n");
    tell_room(this_object(),
      "Thain says: I think there's one more...\n");
    tell_room(this_object(),
      "Thain pauses to think.\n");
    remove_call_out("part4");
    call_out("part6",4);

}

void part6(){
    tell_room(this_object(),
      "Thain says: Ahh I got it! The gate to the Shire.\n");
    remove_call_out("part5");
    call_out("part7",4);
}

void part7(){
    tell_room(this_object(),
      "After another pause, the Thain continues.\n");
    if(!in_progress){
	tell_room(this_object(),
	  "Thain says: We have found 3 witnesses you should speak to.\n");
	tell_room(this_object(),
	  "Thain says: Each of them agreed to answer 3 questions.\n");
	tell_room(this_object(),
	  "Thain says: No more, no less.\n");
	tell_room(this_object(),
	  "Thain says: If you talk too much they will ignore you.\n");
	tell_room(this_object(),
	  "Thain says: Meet them in the interrogation chambers.\n");
	in_progress=1;
	saying = 0;
	dispatch_witness();
    }

    tell_room(this_object(),
      "Thain says: Good luck! Find the killer!\n");
    repeat++;
    saying = 0;
    remove_call_out("part7");
    return;
}

int say(string str){
    object stuff, captain, *u;
    string ck1,ck2,ck3;
    int amt;

    if (!str) return 0;
    if (in_progress == 3) return 0;
    amt = (int) sscanf(str,
      "murder was committed by %s with %s at %s", ck1,ck2,ck3);
    captain = present("thain",this_object());
    if (!captain) return 0;
    if (!(ck1 && ck2 && ck3) && scan_string("murder",str)) {
	if(repeat < 3){
	    tell_story();
	}
	else
	    tell_room(this_object(),
	      "Thain says: No more! I've repeated enough times!\n");
	return 1;
    }
    if (amt != 3) return 0;
    u = filter_array(users(), "invis_filter", this_object(), 0);
    if(sizeof(u) >=1){
	tell_room(this_object(), 
	  "Thain says: Someone is already investigating the murder.\n");
	return 1;
    }
    tell_room(this_object(),
      this_player()->query_name()+" says:  Murder was committed by "+
      capitalize(ck1) + " with " + ck2 + " at " + ck3 + ".\n");
    if(ck3 == "island") ck3 = "island";
    if(ck3=="party tree" || ck3=="tree") ck3="tree";
    if(ck3 == "gate") ck3 = "gate";
    if(ck3 == "harbor" || ck3 == "harbour")
	ck3 = "harbor";
    if(ck3 == "forest") ck3 = "forest";
    if(present("invis_search", this_player())){
	tell_room(this_object(),
	  "Thain says: Test your assumption first!\n");
	return 1;
    }
    tell_room(this_object(),
      "Thain says: Very well you better go and search for proof.\n");
    if(in_progress==2) return 1;
    stuff = clone_object("/players/colossus/mearth/shire/quest/invis2");
    if(ck1==murderer && ck2==murder_weap && ck3==murder_room){
	stuff->set_item_name(ck2);
	stuff->set_room_name(ck3);
	in_progress=2;
    }
    move_object(stuff, this_player());
    return 1;
}

mixed invis_filter(object ob){
    return present("invis_search", ob) && !ob->query_idle(900)
    && !ob->query_linkdeath();
}

int quest_people(){
    object *u;
    int i, j;
    u = filter_array(users(), "invis_filter", this_object());
    j = sizeof(u);
    write("People currently on the quest with "+
      "the object invis_search:\n");
    for(i=0;i<j;i++){
	write(capitalize(u[i]->query_real_name())+"\n");
    }
    return 1;
}
