/*
  Janeen's ring
  #include "/include/lw.h" 
  */
#define FILENAME "/players/louie/test/ringa"
#define TP this_player()
#define ENV environment
inherit "obj/armour";
string name1,name2;

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("ankh");
  set_alias("ankh");
  set_short("A small golden ankh");
  set_type("wedding_ring");
}

init() {
  ::init();
    if(TP->query_real_name()=="louie")
      {
	add_action("ring", "kk");
	add_action("whisperit","jj");
	add_action("ring", "rem");
	add_action("ringhelp", "ankhhelp");
	set_name1();
	set_name2();
	start();
      }
  }

whisperit(string str)
{
  object ob;
  if(!str)
    return;
  ob=find_player(name1);
  if (!ob)
    {
      write("Mike isn't logged in right now.\n");
      return 1;
    }
  if(present(ob, ENV(TP)))
    {
      tell_object(ob,"Janeen whispers to you: "+str+"\n");
      write("You whisper to Mike: "+str+"\n");
      return 1;
    }
  else
    {
      tell_object(ob,"Janeen whispers in your head: "+str+"\n");
      write("You whisper to Mike: "+str+"\n");
      return 1;
    }
}


set_name1() {
  name1="paris";
}

set_name2() {
  name2="louie";
}

notify(p,str) { 
  tell_object(p,str); 
  write(str); 
}

ringhelp() {
  write("Use \"kk <message>\" to say a message to your spouse.\n"
	+ "Use \"rem <message>\" to send an emote message to them.\n");
	
  return 1;
}

ring(str) {
  object p;
  if(!str) return;
  p=find_player(name1);
  if(!p) {
    write(capitalize(name1) + " is not logged on.\n");
    return 1;
  }
  if(!interactive(p)) {
    write(name1 + " is linkdead.\n");
    return 1;
  }
  if(query_verb()=="kk") 
    notify(p,"[*] Janeen says: " + str + "\n");
  else 
    notify(p,"[*] Janeen " + str + "\n");
  return 1;
}


start() {
  object p;
  write("Type \"ankhhelp\" for use of your ankh.\n");
  wear("ankh");
  p=find_player(name1);
  if(p) {
    tell_object(p, "[*]  Janeen enters the game.\n");
    write("[*] Mike is currently logged on.\n");
  }
  if(this_player()->query_level() <20 ) 
    title_set();
}


remove() {
  write("Why would you want to remove your ankh?\n");
  return 1;
}

long() {
  write("A beautiful golden, in the shape of two roses entertwined.\n"
	+ "The inscription reads: Mike and Janeen - In love forever.\n");
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


dest() { 
  destruct(this_object()); 
}

drop() {
  if(query_verb()=="sell") {
    write("Sell your ankh? Never!\n");
    return 1;
  }
  else if(query_verb()=="give") {
    write("Give your ankh away? Never!\n");
    return 1;
  }
  else if(query_verb()=="quit") {
    object ob;
    if(ob=find_player(name1))
      tell_object(ob, "[*]  Janeen leaves you till another time. *smile*\n");
  }
  else write("Drop your ankh? Never!\n");
  return 1;
}


