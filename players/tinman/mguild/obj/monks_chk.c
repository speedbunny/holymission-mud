
/* checking if the monk is allowed to advance */

int level;

int get()
{
   return 1;
}

int drop()
{
   return 1;
}

int id(string arg)
{
  return arg == "monks_chk";
}

void init_arg(string arg)
{
     level = to_int(arg);
}

void adv_level(int l)
{
     level = l;
}

   int query_adv_level()
  {
        if (!level)
             return 0;
       return level;
  }
string query_auto_load()
{
    return "/players/whisky/guild/obj/monks_chk:"+level;
}

     
