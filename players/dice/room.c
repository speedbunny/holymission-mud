#define Room "/players/klara/room"
#define Print "/players/klara/niceprint"

public inherit "/players/klara/prop";

string short_desc,long_desc,longex,shortex;
mapping exits,exit_funcs,items,obs;

private varargs string process(string s, string r)
{
  return sprintf("%-=*s\n",78,process_string(r?implode(explode(s[0]=='@'?
	(string)call_other(this_object(),s[1..99]):s,"{}"),r):s));
}

public void create()
{ prop::create(); exits=([]); exit_funcs=([]); items=([]); obs=([]); }

public void reset(int a)
{ prop::reset(a); if(a) map_mapping(obs,"make",this_object()); }

// Short & long descs, + items handling.

private string get_short_exits()
{
  return shortex||(shortex=(string)Print->truncprint(m_indices(exits))||
	"no obvious exits");
}

private string get_long_exits()
{
  return longex||(longex=sprintf("Obvious exits are: %s\n",
	(string)Print->niceprint(m_indices(exits))||""));
}

public string short()
/*
{ return sprintf("%s (%s)",short_desc,get_short_exits()); }
*/
{ return short_desc; }

public varargs void long(string s)
{ write(s?process(items[s],s):process(long_desc)+get_long_exits()); }

public void set_short(string s) { short_desc=s; }
public void set_long(string s)  { long_desc=s; }
public void add_long(string s)  { long_desc=sprintf("%s %s",long_desc,s); }

public void add_item(mixed s, string d)
{ if(pointerp(s)) map_array(s,"add_item",this_object(),d); else items[s]=d; }

public void remove_item(string s)        { items=m_delete(items, s); }
public int id(string s)                  { return member(items, s); }

// we should use replace_program() as much as possible.

public void replace_room() { replace_program(Room); }

#define res_ex() longex=shortex=0

public varargs void add_exit(string s, string d, string m)
{
  exits[s]=d[0]=='~'?sprintf("/players/%s/%s",creator(this_object()),d[2..]):d;
  m&&exit_funcs[s]=m;
  res_ex();
}

public void remove_exit(string s)
{ exits=m_delete(exits, s); exit_funcs=m_delete(exit_funcs, s); res_ex(); }

public int move()
{
  string v;
  if(!exits[v=query_verb()]) return 0; // exit has been deleted
  if(exit_funcs[v])
  {
    switch(exit_funcs[v][0])
    {
      case '@': if(call_other(this_object(), exit_funcs[v][1..])) return 1;
      case '#':
      {
	string *s;
	s=explode(exit_funcs[v][1..],"#");
	if(present(s[0])) return write(process(s[1],v)), 1;
	if(sizeof(s)>2) write(process(s[2],v));
	break;
      }
      default: write(process(exit_funcs[v],v));
    }
  }
  return this_player()->move_player(v, exits[v]), 1;
}

public void init()
{ map_mapping(exits, lambda(({'x}), ({#'add_action,"move",'x}))); }

public void make(string s)
{
  int i;
  for(;i<obs[s][0];i++)
  {
    obs[s][2][i]&&(obs[s][1]=="exists"||present(obs[s][2][i]))||
	move_object(obs[s][2][i]=s[0]=='!'?
	(object)"players/klara/obmaker"->make_object(s[1..]):clone_object(s),
	this_object());
  }
}

public void add_obj(string s, int n, string t)
{ obs[s]=({n,t,allocate(n)}); make(s); }

public void remove_obj(string s) { obs=m_delete(obs,s); }

// Disgustingly icky stuff for back compatibility now follows. Fear it.

public varargs mixed query_room(string s, mixed x)
{
  switch(s)
  {
    case "items":
    case "dest_dir":
    {
      string *foo,*bar,*res;
      mapping m;
      int i;
      m=s=="items"?items:exits;
      foo=m_indices(m);
      bar=m_values(m);
      i=sizeof(foo);
      res=allocate(i*2);
      while(i-->0) { res[i*2]=bar[i]; res[i*2+1]=foo[i]; }
      return bar;
    }
    case "short_desc": return short();
    case "long_desc":  return process(long_desc)+x?"":get_long_exits();
    case "property":   return query_property(x);
    case "smell":      return query_property("smell");
  }
}
