int last;

int id(string str)
  {return str=="gstub";}

void reset(int arg)
  {if(!arg)
    {last=0;}}

void set_last(int arg)
  {last=arg;}

int query_last()
  {return last;}

int get(string str)
  {return 1;}

int drop(string str) 
  {return 0;}
