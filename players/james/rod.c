clean_up() {
  tell_object(find_player("james"),"CLEAN_UP called on Mystic Rod\n");
  return 1;
}

reset() { garbage_collection(); }

id(string str) {return str=="rod";}
short() {return "Mystic rod";}
long() {write("A Mystic rod\n"); return 1;}
get() { return 1; }
init() {
  add_action("clean_shops","clean_shops");
  add_action("clean_void","clean_void");
  add_action("debug","debug");
  add_action("allwiz","allwiz");
  add_action("mgoto","mgoto");
   add_action("findshadows","findshadows");
  add_action("test","test");
  return 1;
}

test(str) {
  int i;

  garbage_collection();
  return 1;
}

mgoto(str) {
object ob;

ob=find_object(str);
move_object(this_player(),environment(ob));
return 1;
}

is_dir(arg) { return file_size(arg) == -2; }

allwiz() {
string *all, current;
int i,j;

all = get_dir("/players/.");
all = filter_array(all, "is_dir", this_object());
write("number of files = "+sizeof(all)+"\n");
write(all[0]+"\n");
for (i=0; i<sizeof(all); i++) {
  if(file_size(all[i]) == -2) {
    write(all[i]+"\n");
  }
}
return 1;
}

clean_shops() {
object *all;
object ob;
int i;

ob=find_object("/room/store");
all = all_inventory(ob);
write(sizeof(all)+"\n");
for(i=0; i<sizeof(all); i++) {
  if ( (i - (3*(i/3)) ) == 0) destruct(all[i]);
}
return 1;
}

clean_void() {
object *all;
int i;

all = deep_inventory(find_object("/room/void"));
for(i=0; i<sizeof(all); i++) destruct(all[i]);
return 1;
}

debug(str) {
object ob;

ob=find_object(str);
if(!ob) ob=find_player(str);
if(!ob) ob=present(str,this_player());
if(!ob) ob=present(str,environment(this_player()));
if(!ob) return 0;
debug_info(0,ob);
debug_info(1,ob);
return 1;
}

findshadows(arg) {
object *u, ob;
int i;
string str;

u = users();
for(i=0; i<sizeof(u); i++) {
  str = extract(u[i]->query_real_name() + "            ",0,11);
  ob=shadow(u[i],0);
  if (!ob) {
    if(arg == "all") write(str + "\n");
  }
  else {
    while(ob) {
      write(str + file_name(ob) + "\n");
      str = "            ";
      ob = shadow(ob, 0);
    }
  }
}
return 1;
}
