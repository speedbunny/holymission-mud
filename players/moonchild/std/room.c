inherit "players/moonchild/std/property";

status id(string str) {
  return query("items") && query("items")[str]!=0;
}

void init() {
  mapping map;
  int i,j;
  string *tmp;
  if(map=query("exits")) {
    tmp=m_indices(map);
    j=sizeof(tmp);
    for(i=0;i<j;i++)
      add_action("move", tmp[i]);
  }
  if(map=query("funcs")) {
    tmp=m_indices(map);
    j=sizeof(tmp);
    for(i=0;i<j;i++)
      add_action(map[tmp[i]], tmp[i]);
  }
}

string short() {
  return (string)query("short");
}

void long(string str) {
  if(!set_light(0)) {
    write("It is too dark.\n");
    return;
  }
  if(str) {
    mapping tmp;
    if((tmp=(mapping)query("items")) && tmp[str]) {
      write(process_string(tmp[str]) + "\n");
    }
    return;
  }
  write(query("long"));
  if(!query("exits"))
    write("    No obvious exits.\n");
  else {
    int i,j;
    string *xits;
    xits=m_indices(query("exits"));
    j=sizeof(xits);
    if(j==1)
      write("    The only obvious exit is " + xits[0] + ".\n");
    else {
      write("    There are " + ({ 0, "two", "three", "four",
	"five", "six", "seven", "eight" })[--j] + " obvious exits: ");
      for(i=0;i<j;i++) {
	write(xits[i] + ", ");
      }
      write("and " + xits[j] + ".\n");
    }
  }
}

status move() {
  this_player()->move_player(query_verb() + "#" + query("exits")[query_verb()]);
  return 1;
}

status clean_up(status ref_count) {
  if(ref_count || environment() || first_inventory()) return 1;
  destruct(this_object());
}

/* ---- Backwards compatibility functions ---- */

string *query_dest_dir() {
  int i,j;
  string *xits,*dirs,*dest_dir;
  xits=m_indices(query("exits"));
  dirs=m_values(query("exits"));
  j=sizeof(xits);
  dest_dir=allocate(j*2);
  for(i=0;i<j;i+=2) {
    dest_dir[i]=xits[i];
    dest_dir[i+1]=dirs[i];
  }
  return dest_dir;
}

string query_realm() {
  return (string)query("realm");
}

string realm() {
  return (string)query("realm");
}

mixed query_property(string str) {
  mixed tmp;
  if(!(tmp=query("property")) || !mappingp(tmp))return 0;
  if(!str) return m_indices(tmp);
  return tmp[str];
}
