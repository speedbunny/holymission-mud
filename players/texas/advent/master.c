mapping m;            

reset(a) {
  if(!a) m=([]);
}

short() { return "shieldmaster"; }
long() { return 1; }
get() { return 0; }
drop() { return 1; }
id(s) { return s=="shieldmaster" || s=="shield master"; }
query_name() { return "shieldmaster"; }
init() { add_action("query_shielded","qshield"); }
int add_shielded(string o,string b) { m[o]=m[o]?m[o]+({b}):({b}); return 1; }

int query_shielded() {
  int i,sz;
  int j,si;
  string *b,*c;

  sz=sizeof(m);
  if(sz)
    write("Shielded/Shielding People:\n");
  else {
    write("There are NO shielded people.\n");
    return 1;
  }
 b=keys(m); // Chnaged from b=m_indices(m);
  for(i=0;i<sz;i++) {
    c=m[b[i]];
    write(b[i]+"\t :");
    si=sizeof(c);
      for(j=0;j<si;j++) {
        write(" "+c[j]);
      }
    write("\n");
  }
  return 1;
}

shield(string s) {
  object f;
  string e,*j;
  int i,sz;
  if(f=find_player(s)) {
    if(m) {
      if(mapping_contains(&(m[e=this_player()->query_real_name()]),m,e)) {
	j=m[e];
	sz=sizeof(j);
	e=f->query_real_name();
	for(i=0;i<sz;i++) {
	  if(j[i]==e) {
	    return 0;
	  }
	}
      }
    }
    add_shielded(this_player()->query_real_name(),f->query_real_name());
    return 1;
  }
}




