int bar, ore, boy;

int id(string str)
  {return str=="kq1-list";}

int get(string str)
  {return 1;}

int query_weight()
  {return 0;}

void init() 
  {add_action("deb","debuglist");}

status deb()
  {write("Boy:"+boy+"\nOre:"+ore+"\nBar:"+bar+"\n");
  return 1;}

void reset(int arg)
  {if(!arg)
    {boy=ore=bar=0;}}

int query_boy() 
  {return boy;}

int query_ore()
  {return ore;}

int query_bar()
  {return bar;}

void set_boy(int arg)
  {boy=arg;}

void set_ore(int arg)
  {ore=arg;}

void set_bar(int arg)
  {bar=arg;}






