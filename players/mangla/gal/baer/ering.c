/* #######################################################################

                            Engagementring (c) Whisky 
                            
   ####################################################################### */
   
   string name1, name2;
   
   int id(string arg) 
   { 
      return arg=="ring" || arg=="engagement-ring" || arg=="engagementring"; 
   }
   
   string short() 
   { 
          return "A white gold engagement ring (happily worn)"; 
   }
   
   void long() 
   {
   
      write(
      "You see a beautiful white gold engagement ring with a saphire in it.\n"+
      "You see the inscription:  "+capitalize(name1)+" in love with "+
       capitalize(name2)+".\n"+
       "Special commands: 'ering <msg>' 'fiddle'.\n");
    }
  
int drop() 
{
   return  1;
}
      
int get() 
{ 
  write("Your engagement ring slips onto your finger.\n");     
  return 1; 
}
   
string query_auto_load() 
{
    return "players/whisky/genobj/ering:"+name1+"#"+name2;
}

   
void init_arg(string str) 
{
    sscanf(str,"%s#%s",name1,name2);
}
      
void set_name1(string n1) 
{ 
    name1=n1; 
}

void set_name2(string n2) 
{ 
     name2=n2; 
}
  
void init()
{
     add_action("do_fiddle","fiddle");
     add_action("do_ering","ering");
}

int do_fiddle(string arg)
{   
    if (!id(arg)) 
         return 0;
    write("You fiddle with your engagement ring.\n");
    say(this_player()->query_name()+" fiddles with "+
        this_player()->query_possessive()+" engagement ring.\n",this_player());
    return 1;
}

int do_ering(string arg)
{
   object mob;

    if (!arg) 
    {
        notify_fail("Ering what ?\n"); 
        return 0;
    }
    if (this_player()->query_real_name()==name1)
        mob = find_living(name2);
    else 
        mob = find_living(name1);

    if (!mob)
    {
       notify_fail("But your sweety is not logged on!\n");
       return 0;
    }
    tell_object(mob,"[*"+capitalize(this_player()->query_real_name())+ 
                    "*]+"+arg+"\n");
    write("Ok.\n");
    return 1;
}

         
        
