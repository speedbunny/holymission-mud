#include "setlight.h"

/* ------------------------------------------------------------------------
   Filename: std_scroll
   Functions:
   add_name(string || array);
   set_long(string)
   set_level(int)                 which int the player needs to read the scroll
   set_shadow(filename,time)      please use my std_shadow
   set_function(which,value)      example "heal_self",20
  ------------------------------------------------------------------------ */
 
#define TP   this_player()     
#define TPN  this_player()->query_name()

string *names, long, read_msg, shad, fcall;
int level, value;
mixed fval;				/* function value */
int time;				/* the active time */

void reset(int flag)
{
     if (flag == 0)
     {
        names = ({"scroll"});
        level = 1;
        read_msg = "As you recite your scroll it falls to ashes.\n";
        fcall = "";
        fval = 0; 
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

void set_level(int l) 
{
     if (intp(l))
         level = l;
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

void set_function(string f,mixed v)
{
      if (stringp(f) )
      {
          fcall = f;
          fval  = v;
      }
}

void set_read_msg(string m)
{
     if (stringp(m))
         read_msg = m;
}

void init()
{
   add_action("do_read","read");
   add_action("do_read","recite");
}

int do_read(string arg)
{

  object sh;

    if (!arg || member_array(arg,names)==-1) 
       return 0;
    else if (TP->query_int() < level)
       write("That kind of language seems too difficult for you.\n");
    else 
    {
        write(read_msg);
        say(TPN+" recites a scroll");

        if (strlen(fcall) )
			{
				say(" which bursts into flames.\n");
            call_other(TP,fcall,fval); 
				destruct(this_object());
			}
        if (file_size(shad) > 0)
        {
            sh= clone_object(shad);
            if(sh->start_shadow(TP,time)) 
				{
					say(" which bursts into flames.\n");
					destruct(this_object());
				}
				else say(".\n");
        }
    }
  return 1;
}

    
           
            
        
         
            
          
    

              
