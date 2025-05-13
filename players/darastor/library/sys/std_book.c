
#include "setlight.h"

/* std_book.c 
  
   USAGE:
 
   inherit "/obj/std_book";

   void reset(int flag)
   {
        ::reset(flag);
        if (flag == 0)
        {
           * the id's of the book : last name = short 
           add_names(({"guide","small guide","small traveller guild"}));
           set_long("A travellers guide through Tortoise.\n");
           * how to call the page : the contense of the page 
           add_contense( 
           (["page1": 
             "The history of Tortoise\n\n"+
             "blabla....ect",
             "page2":
             "How to hunt Kuno\nblablabla ... ect\n"
           ]));
           * you want to call my_explotion when she reads page1 
           add_funs((["page1":"my_explotion"]));
           set_weight(1);
           set_value(1);
         }
    }
    
void my_explotion()
{
     write("Your guide explodes.\n");
     this_player()->hit_player(100);
     destruct(this_object());
     return; 
}
                                                             */
            
mapping contense, exfuns;
string *names, long;
closure call;
int value, weight, is_open;

void reset(int flag)
{
    if (flag==0)
    {
       contense = ([]);     /* the contense */
       names = ({"book"});  /* the names and the short */
       exfuns = ([]);       /* calling a self defined function */
       long = "";           /* the long_desc */
       call = #'call_other; /* direct adressing for better speed */
       value = 1;           /* how much its costs */
       weight = 1;          /* how heavy it is */
       is_open = 0;         /* it is closed just now */
    }
}

string *add_names(mixed arg)
{
   if (sizeof(arg))
       return (names = names + arg);
   else if (stringp(arg)) 
       return (names = names + ({arg}));
   return names; 
}

int id(string arg)
{
    if (member_array(arg,names)!=-1)
        return 1;
     return 0;
}

string short()
{
      return names[sizeof(names)-1];
}
 
mapping add_contense(mapping arg)
{
   if (mappingp(arg))
      return (contense = arg);
   return contense;
}     

mapping add_funs(mapping arg)
{
   if (mappingp(arg))
      return (exfuns = arg);
   return exfuns;
}

string set_long(string arg)
{
    if (stringp(arg))
        return (long = arg);
    return long;
}

void long()
{
    if (!is_open)
        write(long+"It is closed.\n");
    else
        write(long+"It is open.\n");
}

int set_value(int arg)
{
    if (intp(arg))
        return (value = arg);
    return value;
}

int query_value()
{
    return value;
}

int set_weight(int arg)
{
    if (intp(arg))
        return (weight = arg);
    return 0;
}

int query_weight()
{
     return weight;
}

int get()
{
     return 1;
}

int drop()
{
     return 0;
}


void init()
{
       add_action("fcn_open","open");
       add_action("fcn_read","read");
       add_action("fcn_close","close");
}

int fcn_open(string arg)
{
    string sho;

    if (!apply(call,this_object(),"id",arg)) 
         return 0;
    else if (is_open)
    {
         write("But the "+short()+" is already open.\n");
         return 1;
    }
    is_open = 1;
    write("You open the "+short()+" to read the index.\n");
    say(apply(call,this_player(),"query_name")+" opens the "+short()+
        ".\n",this_player());
    return 1;
}

int fcn_close(string arg)
{
    if (!apply(call,this_object(),"id",arg)) 
         return 0;
    else if (!is_open)
    {
         write("But the "+short()+" is already closed.\n");
         return 1;
    }
    is_open = 0;
    write("You close the "+short()+".\n");
    say(apply(call,this_player(),"query_name")+" closes the "+short()+
        ".\n",this_player());
    return 1;
}

int fcn_read(string arg)
{
   mixed *indexes;
   int sz;

    if (!apply(call,this_object(),"id",arg) && 
         arg!="index" && member(contense,arg)!=1)
        return 0;
    if (!is_open)
    {
       write("But, first you have to open the book.\n");
       return 1;
    }
    else if (arg=="index" || id(arg))
    {
       indexes = m_indices(contense);
       if ( !(sz = sizeof(indexes)) )
       {
           write("Looks like the "+short()+" is empty.\n");
           return 1;
       }
       write("You start to read the index of the "+short()+".\n");
       write ("INDEX:\n\n"); 

       while(sz)
       {
            write(" "+indexes[sz-1]+"\n");
            sz--;
       }
       return 1;
     }
     write("You turn the book to "+to_string(arg)+".\n");
     say(apply(call,this_player(),"query_name")+" turns over some pages "+
         "of a book.\n",this_player());
     write(contense[arg]); 

     if (member(exfuns,arg)==1 && function_exists(exfuns[arg],this_object())) 
         apply( call,this_object(),exfuns[arg] );
     return 1;
}
     
        
      
