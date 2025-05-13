status full;

void reset(int arg) 
{
   if (!arg)
     full = 1;
}

string short() 
{
   if (full)
      return "A small vial containing a thick liquid";
   else
      return "A small vial";
}

void long() 
{
   if (full)
      write ("This is a small vial containing a thick liquid.\n");
   else
      write ("This is a small vial.\n");
}

void init() 
{
   add_action("drink", "drink");
}

int id(string str) 
{
   return str == "liquid" || str == "vial";
}

int drink(string str) 
{
   if (!id(str))
      return 0;

   if (full) 
   {
      write ("You open the vial and drink the thick liquid.\n");
      write ("It has a strange bitter taste, and as you drink it\n");
      write ("your body begins to rejuvenate.  You are completely\n");
      write ("healed.\n");
      say (this_player()->query_name()+" drinks a potion.\n");
      this_player()->heal_self(1000);
      full = 0;
   }
   else
      write ("The vial is empty.\n");
   return 1;
}
      
int get() 
{
   return 1;
}

int query_value() 
{
   if (full)
      return 2500;
   else
      return 25;
}

int query_weight() 
{
  if (full)
    return 1;
  else
    return 0;
}
