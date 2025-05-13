#define PATH "/players/kelly/shitbox/songs"
#define DEFAULT "prologue"
#define EXT ".sng"
#define LIST "/players/kelly/shitbox/singer.user.list"
#define OWNER environment()

string text;
string userlist;
string song;
object listener;
int i;
int delay;
status incog;

id(str) { return str=="singer"; }

short() { return "The Singer"; }

long()  { 
  write("You have to the (in?!?)famous Singer\n"+
        "Try 'sing <player>' or 'sing all' .\n"+
        "Use 'setsong <title>' or just 'setsong' to sing something else.\n"+
        "'setdelay' changes the delay between the lines.\n"+
        "'report' gives a stats-report of the Singer.\n"+
        "Try out 'incognito on/off',you'll like it.\n"+
        "Manufactured by Kelly Industries.\n"
       );
}      

get() { return 1; }

init() {
  incog=0;

  add_action("sing","sing");
  add_action("setsong","setsong");
  add_action("stop","stop");
  add_action("setdelay","setdelay");
  add_action("incognito","incognito");
  add_action("report","report");
}

reset(arg) {
  if(arg) return;
  delay=6;
  i=0;

  userlist=read_file(LIST);
  userlist=explode(userlist,"\n");

  song=DEFAULT;
  text=read_file(PATH+"/"+DEFAULT+EXT); 
  text=explode(text,"\n"); 
}

incognito(str) {
  if(member_array(OWNER->query_real_name(),userlist)==-1) {
    write("You cannot use this command.\n");
    return 1;
  }
  switch(str) {
    case "on" : write("You are now incognito, when you are singing.\n");
                incog=1;
                break;
    case "off": write("You are no longer incognito.\n");
                incog=0;
                break;
    default:    write("Wrong argument.(on|off)\n");
  }
  return 1; 
}
  
report() {
  write("Singer is set to sing:"+song+".\n"+
         "Delay is "+delay+" sec.\n");
  write("Currently "+
        (listener?("singing to :"+listener->query_name()):("the Singer doesn't sing"))+ 
        ".\n");
  write("Incognito is "+(incog?"on":"off")+".\n");
  return 1;
}

setdelay(str) {
  int x;
  if(!str) {
    write("Current delay is :"+delay+" sec.\n");
    return 1;
  }
  sscanf(str,"%d",x);
  delay=x;
  write("Delay set to "+delay+" sec.\n");
  return 1;
}

setsong(str) {
  string songs;
  int i;

  if ( str && sizeof( explode( str, "." ) ) > 1 )
     str = explode( str, "." )[0];

  if(file_size(PATH+"/"+str+EXT)==-1) {
    write("No such song! Available are:\n");
    songs=get_dir(PATH+"/*.sng");
    for(i=0;i<sizeof(songs);i++)
      write(songs[i]+"\n");
  } 
  else { 
    write("You will now sing "+str+".\n");
    text=read_file(PATH+"/"+str+EXT);
    text=explode(text,"\n");
    song=str;
  }
  return 1;
}

sing(str) {
  object ob;

  if(!str) {
    write("Whom ?\n");
    return 1;
  }
  if(str=="all") {
    listener="/players/kelly/shitbox/everybody.c";
    i=0;
    write("Singer will sing "+song+" for everybody.\n");
    shout_text();
    return 1;
  }
  if(!(ob=find_player(str))) { 
    write("That is not here.\n");
    return 1;
  }
  if(!living(ob)) {
    write(capitalize(str)+" would not be very impressed.\n");
    return 1;
  }
  if(ob->query_npc()) {
    write(capitalize(str)+" would not be very impressed.\n");
    return 1;
  }
  listener=ob;
  i=0;
  write("Singer will sing "+song+" for "+listener->query_name()+".\n");
  give_text();
  return 1;
} 

give_text() {
  if(i>=sizeof(text)) return;
  if(text[i]!="")
    if(listener)
      tell_object(listener,(incog?"Something":OWNER->query_name())+
                      " sings: "+text[i]+"\n");
  i++;
  call_out("give_text",delay);
}

stop() {
  remove_call_out("give_text");
  remove_call_out("shout_text");
  write("You stopped Singer singing.\n");
  listener=0;
  return 1;
} 

shout_text() {
  if(i>=sizeof(text)) {
    remove_call_out("shout_text");
    return 1;
  }
  if(text[i]!="") {
    shout(((incog||!OWNER)?"Something":OWNER->query_name())+
           " sings : "+text[i]+"\n");
    if(OWNER) 
      tell_object(OWNER,"You sing : "+text[i]+"\n"); 
  } 
  i++;
  call_out("shout_text",delay);
}
