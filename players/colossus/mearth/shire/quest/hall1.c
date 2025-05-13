inherit "room/room";

string *done;
string murderer, murder_weap, murder_room;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Interrogation chamber";
    long_desc =
    "This small square chamber serves as an interrogation chamber for the\n"+
    "Shire guards. Everyday suspects to murders and robberies are brought\n"+
    "in and questioned before they are tried in the court. The chamber,\n"+
    "surrounded by stone walls on all sides, is sparsely furnished, save for\n"+
    "a wooden table and two small wooden chairs sitting in the center of the room.\n";
    dest_dir = ({
      "/players/colossus/mearth/shire/quest/hall", "southeast",
    });

    items = ({
      "wall", "The thick stone walls look hard and cold",
      "walls", "The thick stone walls look hard and cold",
      "table", "The old wooden table squeaks noisily when force is applied",
      "chairs", "The wooden chairs are old and unsteady",
    });
    done=allocate(4);
}

void set_done(int val){
    val=(int)val;
    if(val==1) done[1]="done";
    if(val==2) done[2]="done";
    if(val==3) done[3]="done";
}

void unset_done(int val){
    val=(int)val;
    if(val==1) done[1]=0;
    if(val==2) done[2]=0;
    if(val==3) done[3]=0;
}

void init(){
    ::init();
    add_action("say", "say");
    add_action("say", "'");
    add_action("say","\"");
    add_action("say");add_xverb("'");
}


int scan_string(string scan, string str){
    string *temp;
    int fin;

    fin=0;
    temp=explode(str," ");
    if(member_array(scan,temp)>-1) fin=1;
    if(member_array(scan+".",temp) > -1) {
	fin = 1;
	tell_room(this_object(),"fin = "+fin+", m_a = "+member_array(scan,temp)+", scan = "+scan+", temp = "+temp+".\n");
    }
    if(member_array(scan+"?",temp)>-1) fin=1;
    /*
	if(member_array(scan+".",temp)>-2) fin=1;
    */
    if(member_array(scan+",",temp)>-1) fin=1;
    return fin;
}

int say(string str){
    object witness, captain, ob;
if(!str) return 0;
    witness=present("HOBBIT_WITNESS0", this_object());
    if(!witness) return 0;
    if(scan_string("job",str))
	witness->state_job(this_player());
    else if(scan_string("name", str))
	witness->state_name(this_player());
    else if(scan_string("pier",str) && !done[3])

	witness->state_murder_room("harbor", this_player());
    else if(scan_string("island", str) && !done[3])
	witness->state_murder_room("island", this_player());
    else if(scan_string("tree", str) && !done[3])
	witness->state_murder_room("tree", this_player());
    else if(scan_string("gate", str) && !done[3])
	witness->state_murder_room("gate", this_player());
    else if(scan_string("forest", str) && !done[3])
	witness->state_murder_room("forest", this_player());
    else if(scan_string("dagger",str) && !done[2])
	witness->state_murder_weap("dagger", this_player());
    else if(scan_string("axe", str) && !done[2])
	witness->state_murder_weap("axe", this_player());
    else if(scan_string("hammer", str) && !done[2])
	witness->state_murder_weap("hammer", this_player());
    else if(scan_string("rope", str) && !done[2])
	witness->state_murder_weap("rope", this_player());
    else if(scan_string("sword", str) && !done[2])
	witness->state_murder_weap("sword", this_player());
    else if(scan_string("johnny", str) && !done[1])
	witness->state_murderer("johnny", this_player());
    else if(scan_string("fatty", str) && !done[1])
	witness->state_murderer("fatty", this_player());
    else if(scan_string("jolly", str) && !done[1])
	witness->state_murderer("jolly", this_player());
    else if(scan_string("todo", str) && !done[1])
	witness->state_murderer("todo", this_player());
    else if(scan_string("fents", str) && !done[1])
	witness->state_murderer("fents", this_player());
    else return 0;
    if(done[1] && done[2] && done[3]){
	ob=clone_object("obj/treasure");
	move_object(ob, "/players/colossus/mearth/shire/quest/hall4");
	captain=present("thain", environment(ob));
	destruct(ob);
	if(captain)
	    captain->set_free(witness);
    }
    return 1;
}
