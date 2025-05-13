#define SONGDIR   "/players/topaz/obj/songs/"
#define TR(x)     tell_room(environment(), x + "\n");
#define IMP(x,y)  sizeof(x) > 2 ? x[0] + y + x[1] : x[0]

#include "/obj/adjust.h"

status playing;
string *lyrics;
int line,ly_size;

status id(string str) {
  return str=="stereo" || str=="topaz's stereo";
}

string short() {
  return "Topaz's stereo";
}

void long() {
  string *song_list;
  int i,j;
  write("This is Topaz's stereo.  Please don't break it.\n");
  if(playing)
    write("There is a CD spinning a single write now.\n");
  write("There is a list of Topaz's singles on the side.\n");
  write("To play a song type, \"select <number>\"\n\n");
  song_list=filter_array(get_dir(SONGDIR + "*"), "dot_filter", this_object());
  j=sizeof(song_list);
  for(i=0;i<j;i++) {
    song_list[i]=implode(explode(song_list[i] + "_", "_"), " ");
    song_list[i]=IMP(explode(song_list[i] + "@", "@"), "'");
    write(((i+1) + ".  ")[0..1]);
    write((song_list[i] + "                        ")[0..50]);
    if(i%1==0)
      write("\n");
  }
  if(j%1)
    write("\n");
}

void init() {
  add_action("select", "select");
}

status select(string str) {
  int number;
  string *song_list;
  if(!(sscanf(str, "%d", number))) {
    notify_fail("Select what?\n");
    return 0;
  }
  if(playing) {
    write("There's already a song playing.\n");
    return 1;
  }
  song_list=filter_array(get_dir(SONGDIR + "*"), "dot_filter", this_object());
  if(number<1 || number>sizeof(song_list)) {
    write("Invalid choice.\n");
    return 1;
  }
  say((string)this_player()->query_name()
  + " puts a CD single on the stereo.\n");
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
    TR("The stereo starts playing the single.");
  }
  else if(line==ly_size+1) {
    TR("The stereo stops as the song ends.");
    playing=0;
    set_heart_beat(0);
  }
  else if(line>=0 && line<ly_size) {
    if(lyrics[line]!="")
      TR("The music says: " + lyrics[line]);
  }
}

int dot_filter(string str) {
  return str[0..0]!=".";
}
