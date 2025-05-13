/* Axlrose - Modified Moonchild's Crystal Box */

#define IMP(x,y)  sizeof(x) > 2 ? x[0] + y + x[1] : x[0]                  
#define SONGDIR   "/players/axlrose/songs/"
#define TR(x)     tell_room(environment(), x + "\n");

#include "/obj/adjust.h"

status playing;
string *lyrics;
int line,ly_size;

status id(string str) {
    return str=="box" || str=="crystal box" || str=="crystals";
}

string short() {
    return "Multi-colored crystals and precious stones designed into a box";
}

void long() {
    string *song_list;
    int i,j;
    write("Multi-colored crystals and precious stones are formed into a box.\n");
    if(playing)
	write("Numerous crystals and stones are vibrating to give off a soft glow.\n");
    write("The diamonds are mounted in writing, saying: select <number> and listing:\n\n");
    song_list=filter_array(get_dir(SONGDIR + "*"), "dot_filter", this_object());
    j=sizeof(song_list);
    for(i=0;i<j;i++) {
	song_list[i]=implode(explode(song_list[i] + "_", "_"), " ");
	song_list[i]=IMP(explode(song_list[i] + "@", "@"), "'");
	write(((i+1) + ".  ")[0..3]);
	write((song_list[i] + "                        ")[0..21]);
	if(i%3==2)
	    write("\n");
    }
    if(j%3)
	write("\n");
}

void init() {
    add_action("select", "press");
    add_action("select", "push");
    add_action("select", "select");
}

status select(string str) {
    int number;
    string *song_list;
    if(!(sscanf(str, "%d", number))) {
	notify_fail("Select which crystalized song?\n");
	return 0;
    }
    if(playing) {
	write("The crystal and stone box is already vibrating.\n");
	return 1;
    }
    song_list=filter_array(get_dir(SONGDIR + "*"), "dot_filter", this_object());
    if(number<1 || number>sizeof(song_list)) {
	write("There is neither a crystal nor a stone for that song.\n");
	return 1;
    }
    say((string)this_player()->query_name()
      + " touches some crystals and stones on the box.\n");
    number--;
    lyrics=explode(read_file(SONGDIR + song_list[number]) + "\n", "\n");
    ly_size=sizeof(lyrics);
    line=-3;
    playing=1;
    set_heart_beat(1);
    return 1;
}

void heart_beat() {
    line++;
    if(line==-2) {
	TR("Numerous crystals and stones begin vibrating, emitting light and sound!");   
    }
    else if(line==ly_size+1) {
	TR("Silenced, some crystals and stones stop radiating hues of light.");
	playing=0;
	set_heart_beat(0);
    }
    else if(line>=0 && line<ly_size) {
	if(lyrics[line]!="")
	    TR("Crystals sing: " + lyrics[line]);
    }
}

int dot_filter(string str) {
    return str[0..0]!=".";
}
