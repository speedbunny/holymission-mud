object stn;

int get(string arg)
  {return 0;}

int id(string str)
  {return str=="cloak_statue";}

void set_p(object arg)
  {stn=arg;}

void long();

void undo()
  {transfer(stn,environment(this_object()));
  destruct(this_object());}

void reset(int arg)
  {if(!arg)
    {enable_commands();}}

void catch_tell(string str)
  {tell_object(stn,str);}
