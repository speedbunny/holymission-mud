inherit "/players/sauron/inherit/virtual_room";

static string patrol_clone_file;
static string patrol_walk_limit;
static int patrol_walk_chance;
static int patrol_size;
static object patrol_leader;
static object *patrol_members;

void set_patrol_clone_file(string str) {
  if(str && str!="" && file_size(str+".c")>0)
    patrol_clone_file=str;
}

void set_patrol_walk_limit(string str) {
  if(str && str!="")
    patrol_walk_limit=str;
}

void set_patrol_walk_chance(int i) {
  if(i)
    patrol_walk_chance=i;
}

void set_patrol_size(int i) {
  if(i>=2)
    patrol_size=i;
}

void set_patrol_leader(object ob) {
  patrol_leader=ob;
}

void clone_patrol() {
  int i;
  object ob;

  if(!patrol_clone_file || !patrol_walk_limit ||
     !patrol_walk_chance || !patrol_size)
    return;

  if(patrol_leader)
    return;

  patrol_members=allocate(patrol_size-1);
  while(i<patrol_size) {
    if(!i) {
      patrol_leader=clone_object(patrol_clone_file);
      patrol_leader->set_walk_chance(patrol_walk_chance);
      patrol_leader->set_walk_limit(patrol_walk_limit);
      patrol_leader->set_clone_room(this_object());
      move_object(patrol_leader,this_object());
    }
    else {
      ob=clone_object(patrol_clone_file);
      ob->set_patrol_leader(patrol_leader);
      ob->set_clone_room(this_object());
      patrol_leader->add_patrol_member(ob);
      patrol_members[i-1]=ob;
      move_object(ob,this_object());
    }
    i++;
  }
}

int _patrol(string str) {
  if(!str || str!="reset") {
    if(!patrol_leader)
      write("There is no patrol right now.\n");
    else
      printf("The patrol lead by /%O, with %d followers, is in /%O.\n",
             patrol_leader,sizeof(patrol_members),
             environment(patrol_leader));
    return 1;
  }
  else {
    if(patrol_leader)
      write("There is already a patrol.\n");
    else {
      clone_patrol();
      write("New patrol cloned.\n");
    }
    return 1;
  }
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    property=({
      "no_clean_up"
    });
  }
}

void init() {
  ::init();
  add_action("_patrol","patrol");
}
