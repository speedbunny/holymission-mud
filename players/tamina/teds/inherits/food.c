string short_desc, name, mess, alias, long_desc, info;
int value, heal, weight;

void reset(int arg)
{
  if (arg) return 0;
}


int id(string str) 
{
 return str == name || str == alias;
}

string short() 
{
  return short_desc;
}

void long() 
{
  write(long_desc);
}

void init() 
{
  add_action("eat", "eat");
}

set_name(n)   { name = n; }
set_alias(a)  { alias = a; }
set_short(s)  { short_desc = s; long_desc = s+".\n"; }
set_long(l)   { long_desc = l; }
set_mess(m)   { mess = m; }
set_weight(w) { weight = w; }
set_value(v)  { value = v; }
set_heal(h)   { heal = h; }
set_info(i) 
{
  if (i)
    info = i;
  else
    info = "This is edible. Type 'eat "+alias+"' to consume.\n";
}

string query_info() { return info; }
string query_name() { return name; }
int query_weight()  { return weight; }
int query_value()   { return value; }

int eat(string str) 
{
  if (id(str))
  {
    write("You start eating a "+str+".\n");
    if (mess)
      write(mess);
    this_player()->heal_self(heal);
    this_player()->add_weight(-weight);
    destruct(this_object());
    return 1;
  }
}

int drop() { return 0; }
int get()  { return 1; }
