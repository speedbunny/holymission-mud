/* 
  Mikes Ring
  #include "/include/lw.h" 
  */
#define FILENAME "/players/louie/test/ringb"
#define TP this_player()
#define ENV environment
inherit "obj/armour";

string name1,name2;

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("bracelet");
  set_alias("bracelet");
  set_short("A fine gold bracelet");
  set_type("wedding_ring");
}

init() {
  ::init();
    if(TP->query_real_name()=="paris")
      {
	add_action("ring", "r");
	add_action("ring", "rem");
	add_action("whisperit","jj");
	add_action("ringhelp", "bracehelp");
	set_name1();
	set_name2();
      }
}


whisperit(string str) {
  object ob;	
  if(!str) return;
  ob=find_player(name1);
  if (!ob) {
    write("Janeen isn't logged in right now.\n");
    return 1;
  }
  if(present(ob, ENV(TP))) {
    tell_object(ob,"Mike whispers to you: "+str+"\n");
    write("You whisper to Janeen: "+str+"\n");
    return 1;
  }
  else {
    tell_object(ob,"Mike whispers in your head: "+str+"\n");
    write("You whisper to Janeen: "+str+"\n");
    return 1;
  }
}


set_name1() {
  name1="louie";
}

set_name2() {
  name2="paris";
}

notify(p,str) { 
  tell_object(p,str); 
  write(str); 
}

ringhelp() {
  write("Use \"r <message>\" to say a message to your spouse.\n"
	+ "Use \"rem <message>\" to send an emote message to them.\n");
  return 1;
}

ring(str) {
  object p;
  if(!str) return;
  p=find_player(name1);
  if(!p) {
    write("Janeen is not logged on.\n");
    return 1;
  }
  if(!interactive(p)) {
    write("Janeen is linkdead.\n");
    return 1;
  }
  if(query_verb()=="r") 
    notify(p,"[*] Mike says: " + str + "\n");
  else 
    notify(p,"[*] Mike " + str + "\n");
  return 1;
}


start() {
  object p;
  write("Type \"ringhelp\" for use of your wedding ring.\n");
  wear("bracelet");
  p=find_player(name1);
  if(p) {
    tell_object(p, "[*]  Mike enters the game.\n");
    write("[*]  Janeen is currently logged on.\n");
  }
  if(this_player()->query_level() <20 ) 
    title_set();
}


remove(string str) {
  if(str!="ring")
    return 0;
  write("Why would you want to remove your bracelet?\n");
  return 1;
}

long() {
  write("A fine gold bracelet, in the shape of two roses entertwined.\n"
	+ "The inscription reads: Mike  and Janeen - In love forever.\n");
}


query_weight() { 
  return 0; 
}


query_spouse() { 
  return name1; 
}

query_auto_load() { 
  return FILENAME+":"; 
}


drop() {
  if(query_verb()=="sell") {
    write("Sell your bracelet? Never!\n");
    return 1;
  }
  else if(query_verb()=="give") {
    write("Give your bracelet away? Never!\n");
    return 1;
  }
  else if(query_verb()=="quit") {
    object ob;
    if(ob=find_player(name1))
      tell_object(ob, "[*] Mike leaves you till another time. *smile*\n");
  }
  else write("Drop your bracelet? Never!\n");
  return 1;
}



