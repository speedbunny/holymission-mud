#pragma strict_types

void reset(int arg) {
  if(arg) return;
  move_object(this_object(),"room/church");
  enable_commands();
}

string get_spouse(string str) {
  string *list;
  string sp,junk;
  int i,l;
  list=explode(read_file("/players/moonchild/wedding/WEDDINGS")+"\n","\n");
  l=sizeof(list);
  for(i=0;i<l;i++) {
    if(sscanf(list[i],"%s: " + str + " & %s: %s",junk,sp,junk)==3) return sp;
    if(sscanf(list[i],"%s: %s & " + str + ": %s",junk,sp,junk)==3) return sp;
  }
}

void catch_tell(string str) {

  string me,them,junk;
  string hold_title;
  string *list;
  status f;
  int    l;
  object ob;

  if(!this_player())
    return;
  hold_title = (string)this_player()->query_pretitle();
  this_player()->set_pretitle(0, 1);
  if(!sscanf(str, "%s enters the game.", me)) {
    this_player()->set_pretitle(hold_title, 1);
    return;
  }
  this_player()->set_pretitle(hold_title, 1);
  ob = present(me, environment());
  if(!ob || !interactive(ob))
    return;
  if(present("wedding_ring", ob))
    return;
  if(get_spouse(me)) {
    object ring;
    move_object(ring = clone_object("players/moonchild/wedding/ring"),
                                    this_player());
    ring->add_names();
  }
}
