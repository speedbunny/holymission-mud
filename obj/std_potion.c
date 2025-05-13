/* ------------------------------------------------------------------------
   Filename: std_potion
   Functions:
   add_name(string || array);
   set_long(string)
   set_shadow(filename,time)      please use my std_shadow
   add_function(which,value)      example "heal_self",20
  ------------------------------------------------------------------------ */

#define TP    this_player()
#define TPN   this_player()->query_name()


string *names, long, drink_msg, shad;
mapping functions;
int value;
int time;				/* the active time */

void reset(int flag)
{
     if (flag == 0)
     {
        names = ({"potion"});
        drink_msg = "You quaff a potion.\n";
        functions = ([]);
        value = 10;
        shad = "";
     }
}

void long()
{
     if (stringp(long))        
        write(long);
     else
     write("You see nothing special.\n");
}
  
int id(string arg)
{
    return (member_array(arg,names)+1);
}

string query_name()
{
   return names[sizeof(names) -1];
}

int query_weight()
{
    return 1;
}

int get()
{
    return 1;
}

int drop()
{
    return 0;
}

string short()
{
    return query_name();
}


void set_long(string l)
{
     if (stringp(l))
         long = l;
}

void set_value(int v)
{
     if (intp(v))
         value = v;
}

int query_value()
{
    return value;
}
void add_name(mixed n)
{
    if (stringp(n))
        names = names + ({n});
    else if (sizeof(n))
        names = names + n;
}

void set_shadow(string s,int t)
{
	//write("SIZE2: "+file_size(s)+" "+s+"\n");
     if ( (file_size(s+".c") > 0) && intp(t))
     {
        shad = s+".c";
        time = t;
     }
}

void add_function(string f,mixed v)
{
      if (stringp(f) )
      {
         functions = functions + ([f:v]);
      }
}

void set_read_msg(string m)
{
     if (stringp(m))
         drink_msg = m;
}

void init()
{
   if (this_player() && environment() == this_player())
   {
   add_action("do_drink","drink");
   add_action("do_drink","quaff");
   }
}

int do_drink(string arg)
{

  object sh;
  int i, sz;
  mixed *vals;

    if (!arg || member_array(arg,names)==-1) 
       return 0;
    else 
    {
        write(drink_msg);
        say(TPN+" quaffs a potion.\n");

        vals = m_indices(functions);
        sz = sizeof(vals);

        if (sz > 0)
		  {
           for(i = 0; i < sz; i++)
               call_other(TP,vals[i],functions[vals[i]]);
			  destruct(this_object());
			}
        if (file_size(shad) > 0)
        {
            sh= clone_object(shad);

            if(sh->start_shadow(TP,time)) 
            {
                 TP->check_shad();
					destruct(this_object());
             }
        }
    }
  return 1;
}

    
           
            
        
         
            
          
    

              
int no_clear()
{
    return 1;
}
