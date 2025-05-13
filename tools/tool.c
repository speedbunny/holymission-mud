/*-------------------------------------------------------------------------*/
/* FILE : tool.c                                                           */
/*                                                                         */
/* Description : This is the dynion, a useful tool for wizards. It is      */
/*               kept in the tools directory and can be cloned from there. */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 13 1997  Kryll        Cleaned up this file. Fixed a bit of security.
 
*/

#include "/obj/obj_defs.h"

int lighted;         /* brightness */
object player;       /* affected player */
string description;  /* fixes extra_look */
object mark, spare, last, got;

// Prototypes:
int id(string str);
string short();
void long();
void help_dynion();
string query_auto_load();
void init_arg(string str);
string extra_look();
int get();
int drop();
void init();
int do_invent();
int do_scan();
int ih();
int ir(string arg);
int il(string arg);
int idl();
int ii();
int ime();
int valid(string str);
int clear_room(string str);
int clear_object(object room);
int destroy_tool(string str);
int do_align(string str);
int do_desc(string str);
int do_don();
int do_doff();
int do_dwho();
int do_emote(string str);
int do_frog(string str);
int do_human(string str);
int do_man(string str);
int do_net();
int do_objects(string str);
int do_show(string str);
int do_where(string str);
int shout_curse(string str);
int do_snooptrace(string str);
int do_i_who(string arg);
int do_i_clone(string str);
int do_i_show();
int do_i_stat();
int do_i_swap();
int do_i_clear();
int do_i_more(string str);
int do_i_move(string str);
int do_i_dump(string str);
int do_i_mark(string str);
int do_i_destruct();
int do_i_call(string str);
void prt_mapping(mapping x);
object query_me();

int id(string str) {
  return (str == "tool" || str == "dynion");
}

string short() {
  if(TP == ENV(TO))
    if(lighted > 0)
      return "Cyhoeddus dynion (maes)";
    else return "Cyhoeddus dynion";
  else return 0;
}

void long() {
  write("This is Mllynwrlch's cyhoeddus dynion.\n");
  if(!TP->query_wizard()) {
    write("Unfortunately only Wizards can use it...\n");
    return;
  }
  help_dynion();
}

void help_dynion() {
  write(
    "align <al_string>    Changes your alignment string.\n" +
    "clear <file_name>    Removes all objects in the specified object\n" +
    "                     Default is the room you are in.\n" +
//    "desc <description>   Changes your extra_look.\n" +
    "destroy              Destroy this tool.\n" +
//    "doff                 Makes the built in light shine dimmer.\n" +
//    "don                  Makes the built in light brighter.\n" +
//    "dwho                 Displays extended user info.\n" +
//    "man <topic>          Extended help command.\n" +
//    "net                  Net connections.\n" +
    "objects <player>     List all objects of a player.\n" +
    "noshout <player>     Gives shout_curse to named player.\n" +
    "show <obj_name>      Show information about an object.\n" +
    "where <item/player>  Prints location of item/player.\n" +
    "scan                 Advanced look.\n" +
    "I                    Advanced inventory.\n" +
    "All standard marker actions\n" +
    "  i_dump, i_mark [im], i_clone, i_swap [isw], i_destruct [id]\n"+ 
    "  i_call [ic], i_move [imo], i_show [ish], i_mark here [ih], i_who\n"+
    "  i_call reset [ir], i_mark living [il], i_dump list [idl]\n" +
    "  i_call init [ii], i_mark <this_player> [ime], i_clear [icl]\n" + 
    "  i_mark last  (you can use last with i_call. last=result of the\n"+
    "                last i_call.), i_more, i_stat [is]\n"+
    "  i_call efun, i_call code\n"+
    "The built-in light now has level " + lighted + ".\n"
  );
}

string query_auto_load() {
  return "tools/tool:" + description;
}

void init_arg(string str) {
  if(str == "0")
    description = 0;
  else
    description = str;
  TELL(TP,"Your dynion activates itself.\n");
}

string extra_look() {
  return description;
}

int get() { return 1; }

int drop() { return 1; }

void init() {
  if(TP->query_wizard()) {
    add_action("do_align","align");
    add_action("clear_room","clear");
//    add_action("do_desc","desc");
    add_action("destroy_tool","destroy");
//    add_action("do_don","don");
//    add_action("do_doff","doff");
//    add_action("do_dwho","dwho");
//    add_action("do_net","net");
//    add_action("do_man","man");
    add_action("shout_curse","noshout");
    add_action("do_objects","objects");
    add_action("do_show","show");
    add_action("do_where","where");
    add_action("do_scan","scan");
    add_action("do_i_dump","i_dump");
    add_action("do_i_mark","i_mark");
    add_action("do_i_mark","im");
    add_action("do_i_clone","i_clone");
    add_action("do_i_swap","i_swap");
    add_action("do_i_swap","isw");
    add_action("do_i_destruct","i_destruct");
    add_action("do_i_destruct","id");
    add_action("do_i_call","i_call");
    add_action("do_i_call","ic");
    add_action("do_i_more","i_more");
    add_action("do_i_move","i_move");
    add_action("do_i_move","imo");
    add_action("do_i_show","i_show");
    add_action("do_i_show","ish");
    add_action("do_snooptrace","snooptrace");
    add_action("do_snooptrace","sn");
    add_action("ih","ih");
    add_action("ir","ir");
    add_action("il","il");
    add_action("idl","idl");
    add_action("do_invent","I");
    add_action("ii","ii");
    add_action("ime","ime");
    add_action("do_i_clear","i_clear");
    add_action("do_i_clear","icl");
    add_action("do_i_who","i_who");
    add_action("do_i_stat","i_stat");
    add_action("do_i_stat","is");
  }
}

int do_invent() {
  object *inv;
  int i;

  inv = deep_inventory(TP);
  for(i=0; i<sizeof(inv); i++) {
    write(inv[i]);
    if(ENV(inv[i]) != TP) {
      write(" in ");
      write(ENV(inv[i]));
    }
    write(" \t");
    if(!inv[i]->short()) {
      if(inv[i]->NAME)
        write("("+inv[i]->NAME+")");
      else
        write("(unknown)");
    }
    else
      write(inv[i]->short());
    write("\n");
  }
  return 1;
}

int do_scan() {
  object old;

  old = mark;
  ih();
  mark->long();
  idl();
  mark = old;
  return 1;
}

/* Marker abbreviations built in here ! Llort */
int ih() {
  return do_i_mark("here");
}

int ir(string arg) {
  return do_i_call("reset "+arg);
}

int il(string arg) {
  return do_i_mark("living "+arg);
}

int idl() {
  return do_i_dump("list");
}

int ii() {
  return do_i_call("init");
}

int ime() {
  mark = TP;
  write(mark);
  write("\n");
  return 1;
}

int valid(string str) {
   string who;

   if(!str) {
     write("No argument given - guess you meant yourself...\n");
     player = TP;
     return 1;
   }
   if(sscanf(str,"this %s",who) == 1)
     if((player = present(who,ENV(TP))) && living(player)) {
       write("Found " + who + " in your environment.\n");
       if(player->query_npc())
         write(who + " is a npc!\n");
         return 1;
     }
     else {
       write("Could not found " + who + " in your environment!\n");
       return 0;
     }
   else if(player = find_player(str))
     return 1;
   else if(player = find_living(str)) {
     write(str + " is a npc!\n");
     return 1;
   }
   else
     write("Could not find player " + str + "!\n");
   return 0;
}

int clear_room(string str) {
  object room;

  if(!str) {
    str = file_name(ENV(TP));
    if(!str) {
      write("Cannot locate your position.\n");
      return 1;
    }
    write("You are in room " + str + ".\n");
  }
  room = find_object(str);
  if(!room) {
    write(str + " is not loaded or does not exist.\n");
    return 1;
  }
  write("Room marked for destruction.\n");
  TELLR(room, TP->NAME + " disintegrates all items in this room.\n");
  return clear_object(room);
}

int clear_object(object room) {
  object obj;
  string s1;
  int count;

  obj = first_inventory(room);
  count = 0;
  while(obj) {
    if(obj->query_npc() || (!living(obj) &&
          !(sscanf(file_name(obj), "%scastle%s", s1, s1) == 2))) {
      write("Destructing " + obj->short() + " (" + creator(obj) + ")\n");
      destruct(obj);
      count++;
      obj = first_inventory(room);
    }
    else
      obj = next_inventory(obj);
  }
  if(count)
    write(count + " items destructed.\n");
  else
    write("No items found in " + room->short() + "\n");
  return 1;
}

int destroy_tool(string str) {
    write("Ok.\n");
    destruct(TO);
  return 1;
}

int do_align(string str) {
  if(str) {
    TP->set_alignment(str);
    write("Alignment changed.\n");
    return 1;
  }
  write("Invalid alignment!\n");
  return 1;
}

int do_desc(string str) {
  if(str && str != "")
    description = str;
  else
    description = 0;
  write("Description changed.\n");
  return 1;
}

int do_don() {
  ++lighted;
  set_light(1);
  write("Light level " + lighted + ".\n");
  return 1;
}

int do_doff() {
  --lighted;
  set_light(-1);
  write("Light level " + lighted + ".\n");
  return 1;
}

int do_dwho() {
  object *who;
  int i, sz;

  who = users();
  sz = sizeof(who);
  printf("%-14s %3s %6s %3s %3s %3s %3s %3s %3s %2s %2s %11s\n",
         "Name", "level", "gender", "str", "dex", "int", "con",
         "wis", "chr", "wc", "ac", "money");
  for(i=0; i<sz; i++) {
    if(who[i]->short())
      printf("%-14s ",who[i]->RNAME);
    else
      printf("(%-12s) ",who[i]->RNAME);
    printf("%3d %6s %3d %3d %3d %3d %3d %3d %3d %3d %11d\n",
           who[i]->LVL, who[i]->query_gender_string(),
           who[i]->query_str(), who[i]->query_dex(),
           who[i]->query_int(), who[i]->query_con(),
           who[i]->query_wis(), who[i]->query_chr(),
           who[i]->query_wc(), who[i]->query_ac(),
           who[i]->query_money());
  }
  return 1;
}

int do_emote(string str) {
  tell_room(ENV(TP), TP->NAME + " " + str + ".\n");
  return 1;
}

int do_frog(string str) {
  if(valid(str)) {
    player->frog_curse("frog");
    write("Ok.\n");
  }
  return 1;
}

int do_human(string str) {
  if(valid(str)) {
    player->frog_curse(0);
    write("Ok.\n");
  }
  return 1;
}

int do_man(string str) {
  int i, sz;
  string *manuals;

  manuals = ({ "/doc", "/doc/efun", "/doc/lfun", "/doc/helpdir",
               "/doc/build", "/doc/w", "/doc/LPC", "/doc/local",
               "/doc/rules", "/doc/guild", "/open",
               "/doc/examples", "/doc/efun/NEWPARSER" });
  sz = sizeof(manuals);
  if(!str) {
    write("Topics:\n");
    for(i=0; i<sz; i++) {
      printf("%-25s ", manuals[i]);
      if(!(i%3) && i!=0)
        write("\n");
    }
    write("\n");
    return 1;
  }
  str = "/" + str;
  i = 0;
  while(i < sz) {
    if(file_size(manuals[i] + str) == -2) {
      write("Sub topics " + manuals[i] + str + ":\n");
      printf("%-*#s\n",79,implode(get_dir(manuals[i] + str + "/."),"\n"));
      return 1;
    }
    if(file_size(manuals[i] + str) > 0) {
      write(manuals[i] + str + ":\n");
      TP->more(manuals[i] + str);
      return 1;
    }
    i++;
  }
  write("Not found.\n");
  return 1;
}

int do_net() {
  int i, sz;
  string name, desc;
  object *who;

  who = users();
  printf("%-12s %-16s\n", "Name", "Host");
  write("------------ ----------------\n");
  sz = sizeof(who);
  for(i=0; i<sz; i++) {
    name = CAP(who[i]->RNAME);
    if(!(desc = who[i]->query_remotehost()))
      desc = query_ip_name(who[i]);
    printf("%-12s %-16s\n", name, desc);
  }
  return 1;
}

int do_objects(string str) {
  object *obj;
  string tmp, sh, spec, cr;
  int val, wt, i, sz;

  if(valid(str)) {
    tmp = sprintf("%-30s %-11s %6s %3s %-25s\n","Name","Creator",
                  "Value","Wt","Special");
    tmp += "------------------------------ ----------- "+
           "------ --- -------------------------\n";
    obj = all_inventory(player);
    sz = sizeof(obj);
    for(i=0; i<sz; i++) {
      sh = obj[i]->short();
      if(!sh)
        sh = "/" + file_name(obj[i]);
      if(strlen(sh) >= 30)
        sh = extract(sh,0,29);
      cr = creator(obj[i]);
      if(!cr)
        cr = "NONE";
      val = obj[i]->query_value();
      wt = obj[i]->query_weight();
      if(obj[i]->query_weapon())
        spec = sprintf("wc: %d",obj[i]->weapon_class());
      else if(obj[i]->query_armour())
        spec = sprintf("ac: %d type: %s",obj[i]->armour_class(),
                       obj[i]->query_type());
      else
        spec = "Nothing";
      if(strlen(spec) >= 30)
        spec = extract(spec,0,29);

      tmp += sprintf("%-30s %-11s %6d %3d %-25s\n",sh,cr,val,wt,spec); 
    }
    tmp += "------------------------------ ----------- "+
           "------ --- -------------------------\n";
    TP->more_string(tmp);
  }
  return 1;
}

int do_show(string str) {
  object obj;
  string *types, tmp;
  int i, sz;

  if(str) {
    if(!(obj = (present(str)) || present(str,ENV(TP)))) {
      write("This object doesn't exist here.\n");
      return 1;
    }
    printf("%-10s", "short :");
    if(tmp = obj->short()) {
      sz = 0;
      types = explode(tmp, " ");
      for(i=0; i<sizeof(types); i++) {
        if(sz>59) {
          write("\n");
          sz = 0;
          write("          ");
        }
        sz += strlen(types[i]) + 1;
        write(types[i]); write(" ");
      }
    }
    else
      write("NO SHORT!\n");
    printf("\n%-10s", "long: ");
    obj->long();
    write("creator: " + creator(obj) + "\n");
    if(obj->query_value())
      write("value: " + obj->query_value() + "\n");
    if(obj->query_weight())
      write("weight: " + obj->query_weight() + "\n");
    if(obj->query_info())
      write("info: " + obj->query_info() + "\n");
    if(obj->weapon_class())
      write("wc: " + obj->weapon_class() + "\n");
    if(obj->armour_class())
      write("ac: " + obj->armour_class() + "\n");
    if(obj->get_type()) {
      write("armour type: ");
      types = obj->get_type();
      write(types[0]);
      for(i=1; i<sizeof(types); i++)
        write("/"+types[i]);
      write("\n");
    }
    return 1;
  }
  write("Missing an argument!\n");
  return 1;
}

int do_where(string str) {
  object obj;
  string s;

  if(valid(str)) {
    if(player->query_npc())
      write(player->NAME);
    else
      write(player->RNAME);
    if(!player->short())
      write(" (invis)");
    if(obj = ENV(player))
      write(" is in room " + file_name(obj) + ".\n");
    else
      write(" has no ENV - maybe it's only the master file.\n");
  }
  else if(obj = find_object(str)) {
    if(s = obj->short())
      write(s);
    else
      write(str);
    if(obj = ENV(obj))
      if(living(obj))
        write(" is carried by " + player->NAME + ".\n");
      else
        write(" lies in room " + file_name(obj) + ".\n");
    else
      write(" has no ENV - maybe it's only the master file.\n");
  }
  else
    write("Nothing with this name exists.\n");
  return 1;
}

int shout_curse(string str) {
  object curse;

  if(valid(str)) {
    curse = clone_object("obj/shout_curse");
    curse->start(player, 0, this_interactive());
    write("Ok.\n");
    return 1;
  }
  return 0;
}

int do_snooptrace(string str) {
  object *players, victim, snooper;
  string name;
  int i, sz;

  if(!TP->query_lord())
    return 0;
  if(!str) {
    players = users();
    sz = sizeof(players);
    for(i=0; i<sz; i++) {
      if((snooper = query_snoop(players[i])) && 
         snooper->query_wiz_level() <= TP->query_wiz_level())
        printf("%-12s : Snooped by %-12s\n", CAP(players[i]->RNAME),
               CAP(snooper->RNAME));
      else
        printf("%-12s : Not snooped.\n", CAP(players[i]->RNAME));
    }
  }
  else if((victim = (object)find_player(str))) {
    if(snooper = (object)query_snoop(victim) && 
       snooper->query_wiz_level() <= TP->query_wiz_level())
      write(CAP(str) + " is snooped by " + CAP(snooper->RNAME) + ".\n");
    else
      write(CAP(str) + " is *NOT* snooped.\n");
  }
  else
    write("Could not find player " + str + "!\n");
  return 1;
}

int do_i_who(string arg) {
  object *who;
  int i, x, sz;

  who = users();
  sz = sizeof(who);
  if(!arg) {
    printf("Nm: %-16s %5s %6s %3s %3s %3s %3s %3s %3s %3s %3s %11s\n",
           "Name", "level", "gender", "str", "dex", "int", "con",
           "wis", "chr", "wc", "ac", "money");
    for(i=0; i<sz; i++) {
      if(i<9)
        write(" ");
      write((i+1)+": ");
      if(who[i]->short())
        printf("%-16s ",who[i]->RNAME);
      else
        printf("(%-16s) ",who[i]->RNAME);
      printf("%5d %6s %3d %3d %3d %3d %3d %3d %3d %3d %11d\n",
             who[i]->LVL, who[i]->query_gender_string(),
             who[i]->query_str(), who[i]->query_dex(),
             who[i]->query_int(), who[i]->query_con(),
             who[i]->query_wis(), who[i]->query_chr(),
             who[i]->query_wc(), who[i]->query_ac(),
             who[i]->query_money());
    }
    write("i_who <number> to mark that player.\n");
    return 1;
  }
  if(sscanf(arg,"%d",x)!=1) {
    write("Usage: i_who [number]\n");
    return 1;
  }
  x--;
  if(x<0 || x>=sz) {
    write("Error: no player with that number\n");
    return 1;
  }
  mark = who[x];
  write(mark); write("\n");
  return 1;
}

int do_i_clone(string str) {
  if(str) {
    if(!(str = TP->valid_read(str,1)))
      write("Invalid file name.\n");
    else if(!(mark = clone_object(str)))
      write("Could not clone object.\n");
    else {
      MOVE(mark,TP);
      write(mark); write("\n");
    }
    return 1;
  }
  return 1;
}

int do_i_show() {
  if(mark)
    write("Mark:  " + mark + "\n");
  if(spare) 
    write("Spare: " + spare + "\n");
  if(last)
    write("Last:  " + last + "\n");
  return 1;
}

/* this is thefabulous yerobas marker */
/* used with special permission :-)   */

int do_i_stat() {
  if(!mark) {
    write("Nothing marked.\n");
    return 1;
  }
  mark->show_stats();
  return 1;
}

int do_i_swap() {
  object hobj;

  hobj = mark;
  mark = spare;
  spare = hobj;
  do_i_show();
  return 1;
}

int do_i_clear() {
  if(!mark) {
    write("Nothing marked.\n");
    return 1;
  }
  return clear_object(mark);
}

int do_i_more(string str) {
  string fnam, dummy1, dummy2;

  if(mark == 0) {
    write("Nothing marked.\n");
    return 1;
  }
  fnam = file_name(mark);
  if(sscanf(fnam, "%s#%s", dummy1, dummy2) == 2)
    fnam = dummy1;
  fnam = "/"+fnam+".c";
  TP->more(fnam);
  return 1;
}
 
int do_i_move(string str) {
  string tmp;
  object toobj;

  if(str == 0)
    return 0;
  if(mark == 0) {
    write("Nothing marked.\n");
    return 1;
  }
  if(str=="spare") {
    if(spare == 0) {
      write("Spare not set.\n");
      return 1;
    }
    MOVE(mark,spare);
    write("OK.\n");
    return 1;
  }
  if(sscanf(str, "living %s", tmp) == 1) {
    toobj = find_living(tmp);
    if(!toobj) {
      write("No such living object.\n");
      return 1;
    }
    MOVE(mark,toobj);
    write("OK.\n");
    return 1;
  }
  MOVE(mark,str);
  write("OK.\n");
  return 1;
}

int do_i_dump(string str) {
  int tmp;
  string tmp2;

  if(mark == 0) {
    write("Nothing marked.\n");
    return 1;
  }
  if(str == "list") {
    object ob;
    int i;
    ob = first_inventory(mark);
    while(ob) {
      i += 1;
      write(i + ":\t");
      write(ob);
      if(ob->short())
        write("\t" + ob->short() + "\n");
      else if(ob->RNAME)
        write("   " + "(" + ob->RNAME + ")\n");
      else if(ob->NAME)
        write("   " + "(" + ob->NAME + ")\n");
      else if(ob->query_alias())
        write("   " + "(" + ob->query_alias() + ")\n");
      else
        write("   " + "(unknown)\n");
      ob = next_inventory(ob);
    }
    return 1;
  }
  write(call_other(mark, "short"));
  if(living(mark))
    write(" (living)");
  if(call_other(mark, "query_npc"))
    write(" (NPC)");
  write("\n");
  tmp2 = creator(mark);
  if(tmp2)
    write("Creator:\t" + tmp2 + "\n");
  tmp = call_other(mark, "query_value");
  if(tmp)
    write("Value:\t" + tmp + "\n");
  tmp = call_other(mark, "query_weight");
  if(tmp)
    write("Weight:\t" + tmp + "\n");
  return 1;
}

int do_i_mark(string str) {
  string tmp;
  int tmp2;

  if(str == 0)
    return 0;
  if(sscanf(str, "living %s", tmp) == 1) {
    mark = find_living(tmp);
    if(!mark) {
      write("No such living object.\n");
      return 1;
    }
    write(mark); write("\n");
    return 1;
  }
  if(str=="last") {
    if(!last) {
      write("No last available.\n");
      return 1;
    }
    if(!objectp(last)) {
      write("Last is not an object,\n"); 
      return 1;
    }
    mark=last;
    write(mark); write("\n");
    return 1;
  }
  if(sscanf(str, "ob %s", tmp) == 1) {
    mark = find_object(tmp);
    if(!mark) {
      write("No such object.\n");
      return 1;
    }
    write(mark); write("\n");
    return 1;
  }
  if(sscanf(str, "this %s", tmp) == 1) {
    mark = present(tmp);
    if(!mark)
      mark=present(tmp,ENV(TP));
    if(!mark) {
      write("This object doesn't exist here.\n");
      return 1;
    }
    write(mark); write("\n");
    return 1;
  }
  if(str == "up") {
    if(mark == 0)
      return 0;
    if(ENV(mark) == 0)
      return 0;
    mark = ENV(mark);
    write(mark); write("\n");
    return 1;
  }
  if(str == "here") {
    mark = ENV(TP);
    write(mark); write("\n");
    return 1;
  }
  if(str == "me") {
    mark = TP;
    write(mark); write("\n");
    return 1;
  }
  if(sscanf(str, "%d", tmp2) == 1) {
    object ob;
    if(mark == 0)
      return 0;
    ob = first_inventory(mark);
    while(tmp2 > 1) {
      tmp2 -= 1;
      if(ob == 0)
        return 0;
      ob = next_inventory(ob);
    }
    if(ob == 0)
      return 0;
    mark = ob;
    write(mark); write("\n");
    return 1;
  }
  return 1;
}

int do_i_destruct() {
  object ob;

  if(!mark)
    return 0;
  ob = ENV(mark);
  destruct(mark);
  write("Ok. New: ");
  write(ob);
  write("\n");
  mark = ob;
  return 1;
}

int do_i_call(string str) {
  string with, who, text, etxt;
  mixed what, res;
  object toobj;

  if(!str)
    return 0;
  if(sscanf(str,"code %s",etxt)==1 && TP->query_wizard()) {
    if(!got) {
      got=clone_object("obj/tool_adv");
      MOVE(got,TO);
    }
    res=got->call_efun(etxt+";",mark,spare,last);
  }
  else if(sscanf(str,"efun %s",etxt)==1) {
    if(!got) {
      got=clone_object("obj/tool_adv");
      MOVE(got,TO);
    }
    res=got->call_efun("res="+etxt+";",mark,spare,last);
  }
  else {
    if(!mark) {
      write("No object marked.\n");
      return 1;
    }
    if(sscanf(str, "%s living %s %s", with, who, what) == 3 ||
          sscanf(str, "%s living %s", with, who) == 2) {
      toobj = find_living(who);
      if(!toobj) {
        write("No such living object.\n");
        return 1;
      }
      if(what=="last")
        what=last;
      res=call_other(mark, with, toobj, what);
    }
    else if(sscanf(str, "%s spare %s", with, what) == 2 || 
            sscanf(str, "%s spare", with, who) == 1) {
      if(!spare) {
        write("Spare not set.\n");
        return 1;
      }
      if(what=="last")
        what=last;
      res=call_other(mark, with, spare , what);
    }
    else if(sscanf(str, "%s %d", with, what) == 2) {
      res=call_other(mark, with, what);
    }
    else if(sscanf(str, "%s %s", with, what) == 2) {
      if(what=="last")
        what=last;
      res=call_other(mark, with, what);
    }
    else if(sscanf(str, "%s", with) == 1)
      res=call_other(mark, with, what);
    else
      return 0;
  }
  if(mappingp(res))
    prt_mapping(res);
  else
    printf("got %O\n",res);
  last=res; 
  return 1;
}

void prt_mapping(mapping x) {
  mixed *a1,*a2;
  int i;

  if(!m_sizeof(x))
    write("([])\n");
  else {
    a1 = m_indices(x)[0..m_sizeof(x)-1];
    a2 = m_values(x)[0..m_sizeof(x)-1];
    write("([ /* sizeof() == "+m_sizeof(x)+" */\n");
    for(i=0; i<sizeof(a1); i++)
      printf("  %O\t: %O,\n",a1[i],a2[i]);
    write("])\n");
  }
}

object query_me() {
  return TO;
}
