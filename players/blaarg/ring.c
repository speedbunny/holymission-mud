
#include "lw.h"

inherit "/obj/armour";

#define TP this_player()
#define TO this_object()
#define CAP capitalize

string name1="Karisma", name2="Blaarg";
object wearer, spouse;

object query_spouse() {
  return spouse;
}

object query_wearer() {


  return wearer;
}

object set_spouse(string str) {
  spouse = find_player(str);
  return spouse;
}

object set_wearer(string str) {
  wearer = find_player(str);
  return wearer;
}

object set_spouse_object(object ob) {
  spouse = ob;
  return spouse;
}

object set_wearer_object(object ob) {
  wearer = ob;
  return wearer;
}

int find_spouse() {
  object p;

  if(!wearer)
    wearer = environment();
  if(!spouse) {
    p = find_player(lower_case(name1));
    if(p) {
      spouse = p;
      p = present("wedding ring", spouse);
      if(!p) {
        p = clone_object("/players/moonchild/wedding/ring");
        move_object(p, spouse);
        p->add_names(spouse->query_real_name(1));
      }
//      write("Setting wearer: "); write(wearer); write("\n");
//      write("Setting spouse: "); write(p); write("\n");
      p->set_spouse_object(wearer);
      write("Spouse found and set.\n");
    }
    else
      write("Spouse not found.\n");
    return 1;
  }
  write("Spouse already set.\n");
return 1;
}

void add_names(string str) {
  string *list,sp,junk;
  int i, sz;

  list = explode(read_file("/players/moonchild/wedding/WEDDINGS"), "\n");
  for(i=0, sz=sizeof(list); i<sz; i++) {
    if(sscanf(list[i], "%s: " + str + " & %s: %s", junk, sp, junk) == 3)
      break;
    if(sscanf(list[i], "%s: %s & " + str + ": %s", junk, sp, junk) == 3)
      break;
  }
  name1 = sp;
  name2 = str;
}

void notify(object p, string str) { 
  if(objectp(p) && stringp(str)) {
    tell_object(p, lw(str)); 
    write(lw(str)); 
  }
}

int ringhelp() {
  write("Use \"ring <message>\" to say a message to your spouse.\n" +
        "Use \"ringem <message>\" or just \"rem\" to send an emote " +
        "message to them.\n" +
        "Use \"fiddle ring\" to fiddle with your wedding ring.\n" +
        "If you want to correct your title, use \"correct title\".\n");
  return 1;
}

int ring(string str) {
  object ring;

  if(!stringp(str)) 
    return 0;

/*
  if(environment()->ring(str))
    return 1; 
*/

  if(!spouse) {
    if(!name1 || !stringp(name1) || name1==""
              || !name2          || !stringp(name2)
             || name2=="")
      add_names(wearer->query_real_name(1));
    if(stringp(name1))
      spouse = find_player(lower_case(name1));
    if(!spouse) {
      notify_fail("Your spouse is not logged in or there is an error.\n");
      return 0;
    }
  }

  if(!interactive(spouse)) {
    write(name1 + " is linkdead.\n");
    return 1;
  }

  ring=present("wedding ring",spouse);
if(ring && !ring->query_spouse())
    ring->set_spouse_object(wearer);

  if(query_verb() == "ring")
    notify(spouse, "[*] " + name2 + " says: " + str + "\n");
  else
    notify(spouse, "[*] " + name2 + " " + str + "\n");
  return 1;
}

int fiddle(string str) {

  if(!id(str)) 
    return 0;
  write("You fiddle with your wedding ring.\n");
  say(TP->query_real_name(1) + " fiddles with " +
      TP->query_possessive() + " wedding ring.\n",0,TP,
      "Someone fiddles with their wedding ring.\n");
  return 1;
}

void title_set() {

  if(!objectp(wearer)) 
    return;
  wearer->set_title("loves " + name1 + " very much");
}

void start() {
  object p, f;

  wearer = environment();
  write("Type \"ringhelp\" for use of your wedding ring.\n");
  wear("wedding ring");
  if(!name1 || !stringp(name1) || name1==""
            || !name2          || !stringp(name2)
            || name2=="")
    add_names(wearer->query_real_name(1));
  if(stringp(name1))
    p = find_player(lower_case(name1));
  if(objectp(p)) {
    spouse = p;
    f = present("wedding ring", spouse);
//    write(f); write("\n");
    if(objectp(f)) {
      f->set_spouse_object(wearer);
      tell_object(p, "[*]\a " + name2 + " enters the game.\n");
      write("[*]\a " + name1 + " is currently logged on.\n");
    }
  }
/*
  else if(wearer->query_immortal())
    write("Spouse not set! Try 'findspouse' if they are visible to you.\n");
*/
  if(!wearer->query_immortal())
    title_set();
}

int correct(string str) {

  if(str!="title") 
    return 0;
  title_set();
  write("Your title has been corrected.\n");
   return 1;
}

int remove(string arg) {

  if(id(arg)) {
    write("Why would you want to remove your wedding ring?\n");
    return 1;
  }
  return 0;
}

void long(string str) {

  write("A beautiful white gold wedding ring, in the shape of " +
        "two roses intertwined.\n" +
         "The inscription reads: " + name1 + " and " + name2 +
        " - In love forever.\n");
  return;
}

void extra_look() { 
  write(name2 + " is very happily married to " + name1 + ".\n"); 
  return;
}

int query_weight() { 
  return 0; 
}

void name1(string str) { 
  name1=str; 
  return;
}

void name2(string str) { 
  name2=str; 
  return;
}

string query_auto_load() { 
  return "players/moonchild/wedding/ring:"+name1+" "+name2; 
}

void init_arg(string str) {
  sscanf(str,"%s %s",name1,name2);
  call_out("start",2,this_object());
  return;
}

void dest() { 
  destruct(this_object()); 
  return;
}

int drop(string arg) {
  if(query_verb()=="sell") {
    write("Sell your wedding ring? Never!\n");
    return 1;
  }
  else if(query_verb()=="give") {
    write("Give your wedding ring away? Never!\n");
    return 1;
  }
  else if(query_verb()=="quit") {
    if(spouse)
      tell_object(spouse, "[*]\a " + name2 + " leaves you all alone.\n");
  }
  else write("Drop your wedding ring? Never!\n");
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("ring");
  set_alias("wedding ring");
  set_short("A white gold wedding ring");
  set_type("wedding_ring");
return;
}

void init() {

  ::init();
  add_action("ring", "ring");
  add_action("ring", "ringem");
  add_action("ring", "rem");
  add_action("fiddle", "fiddle");
  add_action("correct", "correct");
  add_action("ringhelp", "ringhelp");
  add_action("find_spouse", "findspouse");
}