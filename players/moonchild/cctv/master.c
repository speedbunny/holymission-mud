#define FILE     "/players/moonchild/save/cctv"
#define CHECKME  if((string)this_player()->query_real_name()!="moonchild"\
	 	 || !interactive(this_player())) return 0;
#define DISP     clone_object("players/moonchild/cctv/display")
#define DISPLOCS ({ "players/moonchild/workroom",\
			"players/moonchild/gnome/pub",\
			"players/moonchild/newbie/hut" })

#include "/obj/lw.h"

static object *cameras=({ });
static object *displays;
string *dests;

status add(string str, int silent);

void reset(int arg) {
  int i,j;
  string *tmp;
  if(!arg) {
    restore_object(FILE);
    j=sizeof(DISPLOCS);
    displays=allocate(j);
    for(i=0;i<j;i++)
      move_object(displays[i]=clone_object("players/moonchild/cctv/display"),
	DISPLOCS[i]);
    j=sizeof(dests)/2;
    tmp=dests;
    dests=({ });
    for(i=0;i<j;i++)
      add(tmp[i*2] + " " + tmp[i*2+1], 1);
    save_object(FILE);
  }
  j=sizeof(DISPLOCS);
  for(i=0;i<j;i++)
    if(!displays[i])
      move_object(displays[i]=clone_object("players/moonchild/cctv/display"),
	DISPLOCS[i]);
}

void init() {
  add_action("do_add", "add");
  add_action("remove", "remove");
  add_action("destme", "destme");
}

do_add(string str) {
  CHECKME;
  return add(str, 0);
}

status add(string str, int silent) {
  string loc_name,filename;
  int i,j;
  if(sscanf(str, "%s %s", loc_name, filename)!=2)
    return 0;
  if(member_array(loc_name, dests)!=-1) {
    write("That name is already used.\n");
    return 1;
  }
  i=sizeof(cameras);
  cameras+=({ clone_object("players/moonchild/cctv/camera") });
  if(catch(move_object(cameras[i], filename))
	|| !present(cameras[i], find_object(filename))) {
    write("Error.\n");
    destruct(cameras[i]);
    cameras=del_array(cameras, i);
    return 1;
  }
  cameras[i]->set_number(i);
  dests+=({ loc_name, filename });
  j=sizeof(displays);
  for(i=0;i<j;i++)
    displays[i]->set_dests(dests);
  save_object(FILE);
  if(!silent)
    write("Ok.\n");
  return 1;
}

remove(string str) {
  int m,i,j;
  CHECKME;
  m=member_array(str, dests);
  if(m==-1) {
    write("Not a selection anyway.\n");
    return 1;
  }
  destruct(cameras[m/2]);
  cameras=del_array(cameras, m/2);
  dests=del_array(del_array(dests, m), m);
  write("Ok.\n");
  j=sizeof(displays);
  for(i=0;i<j;i++)
    displays[i]->set_dests(dests);
  save_object(FILE);
  return 1;
}

void notify(string str, int arg) {
  object *ob;
  int i,j;
  ob=filter_array(displays, "showing", this_object(), arg);
  if(ob) {
    string msg;
    j=sizeof(ob);
    msg=lw("Picture shows: " + str);
    for(i=0;i<j;i++)
      tell_room(environment(ob[i]), msg);
  }
}

int showing(object ob, int arg) {
  return ob && (int)ob->query_current()==arg;
}

status destme() {
  int i,j;
  CHECKME;
  j=sizeof(cameras);
  for(i=0;i<j;i++)
    if(cameras[i])
      destruct(cameras[i]);
  j=sizeof(displays);
  for(i=0;i<j;i++)
    if(displays[i])
      destruct(displays[i]);
  destruct(this_object());
  return 1;
}
