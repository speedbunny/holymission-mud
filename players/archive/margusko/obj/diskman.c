inherit "/players/leslie/std/object";
inherit "/players/leslie/functions";

string dir = "/players/margusko/songs";
string ext = ".cd";
string *sss;
int counter;

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("diskman");
    set_id( ({ "diskman", "cd player", "player", "cdp" }) );
    set_short("Margusko's CDplayer");
    set_long("A cool cdPlayer from Margusko\n\
You should:\n\
read songs: to get a list of the songs in the drive\n\
insert disk <dirname>: put another disk in the drive\n\
play <songname | number>: play the wanted song\n\
stop : stops the current song.\n\
Any more ideas to me :)\n\
");
    set_weight(0);
    set_value(0);
}

void init() {
    ::init();
    add_action("read", "read");
    add_action("insert", "insert");
    add_action("play", "play");
    add_action("stop", "stop");
}

int scan_dir(string name) {
    int n;
    n = strlen(ext);
    if(name[<n..<1] == ext) return 1;
    return 0;
}
string *get_songs() {
    string *all;
    if(!dir) return 0;
    if(file_size(dir) != -2) return 0;
    all = get_dir(dir+"/*");
    all = filter_array(all, "scan_dir", this_object());
    return all;
}
int read(string str) { 
    int n;
    string * songs;
    if(!str || (str != "songs")) return (int)notify_fail("Read what?\n");
    if(!(songs = get_songs())) return (int)notify_fail("No disk in drive, or disk defect.\n");
    n = sizeof(songs);
    if(!n) return (int)notify_fail("The disk has no songs on.\n");
    write("The songs in "+dir+":\n\n");
    if(file_size(dir+"/TITLE") > 0) write(read_file(dir+"/TITLE"));
    while(n--) {
	write(
	  sprintf("%4d: %s\n", sizeof(songs) - n, replace_string(explode(songs[n], ext)[0], "_", " ") ));
    }
    return 1;
}

int insert(string str) {
    if(!str) return 0;
    if(sscanf(str, "disk %s", str) != 1) return (int)notify_fail("What do you want to insert?\n");
    if(file_size(str) != -2) return (int)notify_fail("There is no such directory.\n");
    dir = str;
    write("Inserting disk: "+str+"\n");
    return 1;
}

int play(string str) {
    int n;
    if(sscanf(str, "%d", n) == 1) {
	str = get_songs()[<n];
	str = dir + "/" + str;
    }
    else
	str = dir + "/" + replace_string(str, " ", "_") + ext;
    if(file_size(str) < 1) return (int)notify_fail("No such song.\n");
    sss = explode(read_file(str), "\n");
    counter = 0;
    set_heart_beat(1);
    write("You press the play button ...\n");
    return 1;
}

void heart_beat() {
    if(strlen(sss[counter]))
	tell_object(environment(this_object()), "CD: "+sss[counter]+"\n");
    counter++;
    if(counter < sizeof(sss) ) return;
    set_heart_beat(0);
    tell_object(environment(this_object()), "Your diskman stops playing.\n");
}

int stop() {
    write("You press the stop button.\n");
    if(!sss) return 1;
    if(!sizeof(sss)) return 1;
    set_heart_beat(0);
    write("The cdplayer stops playing.\n");
    return 1;
}

mixed query_auto_load() { return base_name(this_object())+":"; }
