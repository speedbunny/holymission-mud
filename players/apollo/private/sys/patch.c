
/* mistletoe 

   This a a combination between the dyneon (markertool) and the pointer.
   It uses both advantages and is levelsecured.  
                                                    */
 
#define TP       this_player()
#define INTO     TP->query_intoxination()
#define TO       this_object()
#define E        environment
#define WIZ      TP->query_level() > 32
#define NEW      TP->query_newwiz() 
#define APPR     TP->query_immortal()
#define FILE     "/players/whisky/obj/mistletoe:"

inherit "/tools/tool";
/* prototyping */ 
int write_inv_ob(object obj);
int mcall2(string str);

int count, lighted, hide, i;
string my_id;
object normal, obj, finder;
mixed ob;

mixed query_auto_load() 
{ 
       return FILE+hide+"#"+lighted; 
}

void init_arg(mixed arg)
{
     sscanf(arg,"%d#%d",hide,lighted);
}

int drop() 
{ 
    return 1; 
}

int id(string str) 
{ 
     return str=="mistletoe" || str == my_id; 
}

mixed ladjust(string str,int n) 
{ 
      return extract(str+"                              ",0,n-1);
}

mixed short() 
{
  if (hide) return;
  if (lighted) return "mistletoe (lighted)";
  else
   return "mistletoe";
 }

void long() 
{
   write("This is just a combination between the markertool\n"+
         "and the utilitytool pointer. To get the marker commands\n"+
         "just type: help marker. To get the utility commands, just\n"+
         "type: help utility.\n");
   if (hide)
       write("The mistletoe is currently hidden in your inventory.\n");
   if (lighted)
       write("The lightlevel of your mistletoe is "+to_string(lighted)+".\n");
}

int get() 
{ 
     return 1; 
}
 

void init() 
{
      ::init();   /* the marker functions: secured */
  add_action("help","help");

  if (APPR) 
  {
    add_action("mlight","mlight"); 
    add_action("minto","minto");
    add_action("mmail","mmail"); 
    add_action("mitem","mitem");
    add_action("minv","minv"); 
    add_action("mnet","mnet");
    add_action("mdebug","mdebug");
    add_action("mwho","mwho");
    add_action("mloc","mloc"); 
    add_action("set_count","count");
    add_action("mlerr","mlerr"); 
    add_action("man","man");
    add_action("mhide","mhide"); 
    add_action("mshow","mshow");
    add_action("mguild","mguild"); 
    add_action("mname","mname");
    add_action("mmore","mmore");
    add_action("mcall","mcall");
    add_action("clean","clean");
  }                 
  if (NEW)
  {
    add_action("weap","weap");
    add_action("orc","orc"); 
    add_action("arm","arm"); 
    add_action("do_shad","shad");
    add_action("clean","clean");
    add_action("_ld","loaddir");
    add_action("dir_upd","updir");
    add_action("uphere","uphere");
  }
  if (WIZ)
  {
    add_action("do_prison","prison");
    add_action("do_unprison","unprison");
  }
}

int do_prison(string arg)
{
    object ob, curse;

    if (!arg || !interactive(this_player()))
    {
         write("Prison whom ?\n");
         return 1;
    }
    ob = find_living(arg);
    if (!ob || !ob->query_player())
    {
        write("Noone here by that name !\n");
        return 1;
    }
    else if (ob->query_level() >= this_player()->query_level())
    {
        write("You can only prison lower levels !\n");
        return 1;
    }
    else if (present("prison_curse",ob))
    {
        write(capitalize(arg)+" is already prisoned.\n");
        return 1;
    }
    curse = clone_object("/players/whisky/obj/pcurse");
    curse->set_prisoner(this_player());
    move_object(curse,ob);
    write("Ok, "+capitalize(arg)+" is prisoned.\n");
    log_file("PRISON",this_player()->query_real_name()+" Prisoned "+
             ob->query_real_name()+" at "+ctime(time())+"\n");
    return 1;
}

int do_unprison(string arg)
{
    object ob, curse, mail;

    if (!arg || !interactive(this_player()))
    {
         write("Unprison whom ?\n");
         return 1;
    }
    
    ob = find_living(arg);
    if (!ob || !ob->query_player())
    {
        write("Noone here by that name !\n");
        return 1;
    }
    curse = present("prison_curse",ob);
    mail = present("mailread",ob);
    write("You unprisoned "+ob->query_real_name()+" and it's loged.\n");
    if (curse)
        destruct(curse);
    tell_object(ob,"You are unprisoned by "+this_player()->query_real_name()+
                   " !\n");
    move_object(ob,"/room/church");
    command("look",ob);
    log_file("PRISON",this_player()->query_real_name()+" Unprisoned "+
             ob->query_real_name()+" at "+ctime(time())+"\n");
    ob->set_title("");
    if (mail)
        destruct(mail);
    return 1;
}

int mnet(string arg)
{
   object *who, mob;
   int i, sz;

   who = users();

   if (!arg)
   {
     for (sz = sizeof(who), i = 0; i < sz; i++)
     {
        write(ladjust(who[i]->query_real_name(),12)+" "+
                      query_ip_number(who[i])+"\n");
     }
     return 1;
   }
   mob = find_living(arg);
   if (objectp(mob))
   {
        write(mob->query_real_name()+"\t\t"+query_ip_number(mob)+"\n");
        return 1;
   }
   write("No such player found.\n");
   return 1;
}
       
   

int mhide() 
{ 
  write("You hide your mistletoe in your inventory.\n"+
        "Just type <mshow> to make it visible again.\n");
  hide=1;
  return 1;
}

int mshow() 
{
  write("You make your mistletoe visible again.\n");
  hide=0;
  return 1;
}
 
int help(string str) 
{
  if (str!="marker" && str!="utility")
     return 0;
  else if (!APPR) 
  {
     write("This mistletoe gives only help for Wizards.\n");
     return 1;
  }

  if (str=="utility") 
  {
  write( 
  "COMMANDS APPRENTICE:\n"+
  "mlight [num] : lights your tool, man or man [filename] : helpdir, \n"+
  "minv [name] or minv [env] : shows the items of name or your environment,\n"+
  "mitem [object] in [name] : gives you info about an item in a living,\n"+
  "mmail : clones you a mailbox and gives you all commands like in the post,\n"+
  "mmore or mmore [objectname] : filereading of room or present object,\n"+
  "mloc [name] : location of a living, mdebug : your errorlogfile,\n"+
  "mlerr : reading the last lined in the lpmud.log, mwho : better than who,\n"+
  "minto [num] : setting your intoxination, mhide : hide your tool,\n"+
  "mcall : prints out the call out info of all objects in the game,\n"+
  "mshow : make your tool visible, mnet or mnet [player] : the ip number\n\n"+ 
  "COMMANDS NEWWIZ:\n"+
  "orc [level] : cloning a testmonster, weap [class] : cloning a testweapon\n"+
  "arm [class] : cloning a testarmour, shad [living] [time] : shadowing a \n"+
  "living when using /obj/std_shadow, clean : cleaning your environment,\n"+
  "updir : updating your directory, loaddir : loading your directory, \n"+
  "uphere: updating your environment and moving all players back.\n\n"+
  "COMMNDS WIZ:\n"+
  "prison [name] puting a player into prison, must be lower level\n"+
  "unprison [name] removing a player from prison, only if you prisoned her\n"); 
  return 1;
  }
  else 
  {
   write("WIZARD COMMANDS:\n"+
   "align [string] : changing the alignment, clear [file] : itemsdestruct\n"+
   "noshout [player] : shoutcurse, where [item] or [player] : filename\n"+
   "scan : advanced look, I : advanced inventory, il [living] : marking\n"+
   "a living, idl : getting the inventory of a marked object, im [object]\n"+
   "marking an object (number or file), ic [function] [mixed] : calling\n"+
   "a function in an object, ic efun [efun] : calling an efun in an object\n"+
   "ic code [code] : writing a code into a marked object, ime : marking \n"+
   "yourself, i_clone [file] : marking and cloning an object, im last : \n"+
   "marking the last marked object (variables mark && last), isw : swaping\n"+
   "the last with the marked object, ic init : calling the init of a marked\n"+
   "object, im object [file]: marking the masterobject, i_who or i_who [num]\n"+
   "getting the userlist as marked, imo [where] : moving a marked object\n"+
   "ih : marking your environment, ish : advanced look of a marked object\n"+
   "ir or ir [num] : reseting a marked object, icl : clearing marked object\n"+
   "id : destructing a marked object, i_more : read file of marked object\n\n"+
   "EXAMPLES:\n"+
   "1.) ime, idl, im1, i_more. 2.) i_who, i_who 2, ic query_real_name.\n"+
   "3.) il whisky, ic code mark->run_away(). 4.) i_clone /obj/armour, \n"+
   "ic set_ac 4, ic set_name mail, ic code move_object(mark,last) [last ==\n"+
   "whisky. 5.) im object /players/whisky/workroom, icl.\n"); 
    return 1;
  }
  return 1;
}

/* pmore */

void mmore(string arg)
{
    string *ploder;
    string file;
    object mob;

    if (!arg)
    {
        file = file_name(environment(TP))+".c";
        write("Trying to read "+file+"\n");
        TP->more("/"+file);
    }
    else if (mob = present(arg,TP) )
    {
      ploder = explode(file_name(mob),"#");
      file = ploder[0]+".c";
      write("Trying to read "+file+"\n");
      TP->more("/"+file);
    }
    else if (mob = present(arg,environment(TP)) )
    {
      ploder = explode(file_name(mob),"#");
      file = ploder[0]+".c";
      write("Trying to read "+file+"\n");
      TP->more("/"+file);
    }
    else
    {
     write("Usage: pmore to get your environment or pmore string\n"+
           "to get a present item or an item in your environment.\n");
     return;
    }
}

/* updating the environment */
int uphere()     
{
   object *env, *pl, mob;
   int i, sz;
   string *ploder;

   pl = ({});
   mob = environment(TP);
   env = all_inventory(mob);

   for (sz = sizeof(env), i = 0; i < sz ; i++)
   {
       if (interactive(env[i]))
       {
         if (env[i]!=TP)
           tell_object(env[i],"Your environment was updated.\n");
           pl = pl + ({env[i]});
       }
       else 
           destruct(env[i]);
   }
   for (sz = sizeof(pl), i = 0; i < sz; i++)
        move_object(pl[i],"/room/church");

   ploder = explode(file_name(mob),"#");
   destruct(mob);

   for (sz = sizeof(pl), i = 0; i < sz; i++)
        move_object(pl[i],ploder[0]);

   write("Done.\n");
   return 1;
}


/* name */

int mname(string arg)
{
    if (!arg)
    {
        notify_fail("Usage: mname <name>\n");
        return 0;
    }
    my_id = arg;
    write("The second id of your mistletoe is "+arg+"\n");
    return 1;
}

/* light */
 
int mlight(string arg) 
{
 int n;

 if (!arg) 
 {
    write("lightlevel of your environment = " + set_light(0) + "\n");
    return 1;
  }
  if (sscanf(arg , "%d" , n) == 1) 
  {
     if (n>0) 
     {
        write("Your mistletoe lights up the dark place !\n");
        set_light(n);
        lighted=n;
     }
     else 
     {
     write("Suddenly everything gets darker !\n");
     lighted=0;
     set_light(n);
   }
  }
  return 1;
}

int set_count(mixed n) 
{
   if (sscanf(n, "%d", count) == 1) 
       write("Ok.\n"); 
   else 
     return 0;
   count -=n;
   return 1;
}


/* the intoxination */

int minto(string arg) 
{
     int i;

    if (!arg) 
    {
       notify_fail("Syntax: mintro <num>     Current intoxication="+INTO+"\n");
     return 0;
     }
     if (sscanf(arg, "%d", i) == 1) 
     {
        if (i<INTO) 
        {
           write("Your current intoxication is "+INTO+"\n"+
                 "give an argument <= your intoxication !\n");
        }
        else  
          TP->drink_alcohol(i);
          write("Your current intoxication is now "+INTO+"\n");
         return 1;
    }
    return 1;
  }
    
/* help on docs */

int man(string arg) 
{
    int i, sz;
    string *topics;

    topics = ({ "/doc", "/doc/efun", "/doc/lfun", "/doc/helpdir",
                "/doc/build", "/doc/w", "/doc/LPC", "/doc/local",
                "/open", "/doc/guild", });
    
     sz = sizeof(topics);
 
     if (!arg) {
        write("Topics:\n");
        for (i=0;i<sz;i++)
        write(topics[i]+ " ");
        write("\n");
      return 1;
      }
      arg= "/"+arg;
      i=0;
      while(i<sz) 
      {
      if (file_size(topics[i]+arg) == -2) {
         write("Subtopics "+topics[i]+arg+":\n");
         ls(topics[i]+arg+"/.");
         return 1;
         }
      if (file_size(topics[i]+arg) > 0) {
         write(topics[i]+arg+":\n");
         TP->more(topics[i]+arg);
       return 1;
      }
      i++;
     }
    write("Not found !\n");
    return 1;
 }
         

/* debug log */
      
int mdebug(string arg) 
{
    if (!arg) 
        arg = TP->query_real_name();
   TP->more("/log/"+arg);
   return 1;
} 

 
/* lplog */
 
int mlerr() 
{
     tail("/lpmud.log");
    return 1;
}

/* mailrader */

int mmail() 
{
   object box;
   if (present("mailread",TP)) 
   {
      write("You have already your invisible mailreader !\n");
   return 1;
   }
   box = clone_object("obj/mail_reader");
   transfer(box,TP);
   write("Now, you can read your mail like in the post !\n");
   return 1;
 }

/* finding an object */
  
mixed findob(mixed arg,mixed where) 
{
  object ob;
  ob = first_inventory(where);

  while(ob) 
  {
    if ((ob->id(arg)) || (ob->short()==arg) || (ob->query_name()==arg)) 
        return ob;
    ob = next_inventory(ob);
  }
}

/* an item in the player */

int mitem(string arg) 
{
   object obj;
   string arg1,arg2;

   if (!arg) 
   {
      notify_fail("Usage: mitem <obj> in <player> !\n");
      return 0;
    }
    if (sscanf(arg,"%s in %s",arg1,arg2) == 2) 
    {
       if (!find_living(arg2)) 
       {
          notify_fail("Couldn't find "+arg2+".\n");
        return 0;
       }
     obj = findob(arg1,find_living(arg2));
     }
     else 
     {
       obj = find_object(arg);
     if (!obj) 
         obj=findob(arg,TP);
     if (!obj) 
         obj=findob(arg,E(TP));
     }
     if (!obj) 
     {
      notify_fail(arg+" cannot be found !\n");
      return 0;
     }
     write("\nItem:\t"+obj->short()+"\n\n");
     if (creator(obj)) 
         write("Creator:\t"+capitalize(creator(obj)));
     write("\nFilename:\t"+file_name(obj));
     if (obj->query_id())       
         write("\nId:\t"+obj->query_id());
     if (obj->query_name())     
         write("\nName:\t"+obj->query_name());
                                write("\nWeight:\t"+obj->query_weight());
     if (!living(obj))          
         write("\nValue:\t"+obj->query_value());
     if (obj->query_armour())   
         write("\nArmour Class:\t"+obj->armour_class());
     if (obj->query_weapon())   
         write("\nWeapon Class:\t"+obj->weapon_class());
     write("\n\nLong Desc.:\n");
     obj->long();
     write("\n");
    return 1;
 }
  

/* inventory of a living */
int minv(string arg) 
{
   object ob, where;
   int n;
   if (!arg) 
   {
      write("Usage pinv <living> !\n");
      return 1;
   }
   if (arg)  
       where = find_living(arg);
   if (!where)
     where = find_object(arg);
   if (!where) 
   {
      write("Didn't find "+arg+"\n");
   return 1;
   }
   write_inv_ob(where);
   return 1;
}

int write_ob_and_desc(object obj) 
{
   string str;

   if (!obj) 
        return 0;
   write(obj); write("-->");
   str=obj->short();
   if (!str) str = obj->query_name();
   if (!str) str = "(Invisible Object)";
   write(str+"\n");
   return 1;
}

int write_inv_ob(object obj) 
{
    object ob;
    int n;
    ob= first_inventory(obj);
    write("Inventory of: "); write_ob_and_desc(obj);
    while(ob) {
     write(" "+n+": "); write_ob_and_desc(ob); 
     n++;
     ob = next_inventory(ob);
   }
   write("That's all !\n");
   return 1;
 }
  
mixed nr_in_ob(int n, object obj) 
{
   object ob;
   int nr;
   nr=n;

   if (nr < 0) 
       return 0;
   if (!obj) 
       return 0;
   ob=first_inventory(obj);

   while(ob && nr) 
   {
    ob=next_inventory(ob);
    nr-=1;
   }
   return ob;
}
   
mixed search_all(string str) 
{
   object ob;

   if (!str) 
   {
    notify_fail("ERROR: No argument to search_all() !\n");
    return 0;
   }
   if (str=="env") 
       ob=E(TP);
   if (!ob) 
       ob=present(str, TP);
   if (!ob) 
       ob=present(str, E(TP));
   if (!ob) 
       ob=find_object(str);
   if (!ob) 
       ob=find_living(str);
   if (!ob) 
       ob=find_living("ghost of "+str);
  return ob;
}
  
   
mixed find_ob(string str) 
{
    object ob;
    string s1, s2, tmp;
    int nr;

    if (!str) 
    {
      notify_fail("ERROR: No argument given to find object.\n");
      return 0;
    }
    if (sscanf(str, "%s,%s", s1, s2) !=2) 
    {
       if (sscanf(str, "%d", nr) ==1) 
       {
       return nr_in_ob(nr, E(TP));
       }
       else 
       {
         search_all(str);
       }
   }
   ob=search_all(str);
   while (s2 && ob) {
   tmp = 0;
   if (sscanf(s2, "%s,%s", s1, tmp) !=2) 
      s1=s2;
   s2 = tmp;
   }
   return ob;
 }


/* testmonster */
 
int orc(string arg) 
{
    int i;
    object ob;

   if (!arg) 
   {
     notify_fail("Usage: porc <num> !\n"); 
     return 0;
  }
  if (sscanf(arg , "%d" , i) == 1) 
  {
     if (i>100) 
     {
        write("The level of the testmonster was too high !\n"+
              "Try again !\n");
     }
     else if (i<=0) 
     {
        write("You shell give an argument > 0 !\n");
     }
     else {
     ob=clone_object("obj/monster");
     ob->set_name("orc");
     ob->set_short("An Orc (Tester)");
     ob->set_long("The Testmonster of "+capitalize(TP->query_real_name())+"\n");
     ob->set_level(i);
     transfer(ob,E(TP));
     write("Ok.\n");
    }
     return 1;
  }
  return 1;
}


/* weapon */

int weap(string arg) 
{
    int i;
    object ob;

 if (!arg) 
 {
    notify_fail("Usage: pweap <num> !\n");
    return 0;
  }
  if (sscanf(arg , "%d" , i) == 1) 
  {
     if (i>20) {
        write("The class of the weapon was > 20 !\n"+
              "Try again !\n");
     }
     else if (i<=0) 
     {
        write("You shell give an argument > 0 !\n");
     }
     else {
     write("Ok.\n");
     ob=clone_object("obj/weapon");
     ob->set_name("sword");
     ob->set_alias("testsword");
     ob->set_short("A testsword");
     ob->set_long("The Testweapon of "+capitalize(TP->query_real_name())+"\n");
     ob->set_class(i);
     ob->set_weight(1+i/5);
     transfer(ob,TP);
    }
     return 1;
  }
  return 1;
}

/* the armour */

int arm(string arg) 
{
    int i;
    object ob;

 if (!arg) 
 {
    notify_fail("Usage: parm <num> !\n");
    return 0;
  }
  if (sscanf(arg, "%d " ,i) == 1) 
  {
     if (i>4) 
     {
        write("The class of the armour was too high !\n"+
              "Try again !\n");
     }
     else if (i<=0) 
     {
        write("You shell give an argument > 0 !\n");
     }
     else 
     {
     write("Ok.\n");
     ob=clone_object("obj/armour");
     ob->set_name("mail");
     ob->set_alias("testmail");
     ob->set_short("A testmail");
     ob->set_long("The Testmail of "+capitalize(TP->query_real_name())+"\n");
     ob->set_ac(i);
     ob->set_weight(1+i);
     transfer(ob,TP);
     }
     return 1;
  }
  return 1;
 }

/* who is here */

int mwho() 
{
  object *who;
  int i, sz;

  who = users();
  write(
  "Name:            level gender str dex int con wis chr wc ac money\n");
  for(sz=sizeof(who),i=0;i<sz;i++) 
  {
  if (who[i]->short())
  write(ladjust(who[i]->query_real_name(),16)+" ");
  else write(ladjust("("+who[i]->query_real_name()+")",16)+" ");
  write(ladjust(who[i]->query_level(),5)+" "+
        ladjust(who[i]->query_gender_string(),5)+" "+
        ladjust(who[i]->query_str(),3)+" "+
        ladjust(who[i]->query_dex(),3)+" "+
        ladjust(who[i]->query_int(),3)+" "+
        ladjust(who[i]->query_con(),3)+" "+
        ladjust(who[i]->query_wis(),3)+" "+
        ladjust(who[i]->query_chr(),3)+" "+
        ladjust(who[i]->query_wc(),3)+" "+
        ladjust(who[i]->query_ac(),3)+" "+
        ladjust(who[i]->query_money(),11)+"\n");
   }
  return 1;
 }


/* location of a player */

int mloc(string arg) 
{
   object ob,env;

   ob=find_living(arg);

   if (!arg) {
      notify_fail("Usage: mloc <name> !\n");
    return 0;
   }
   if (!ob) 
   {
     notify_fail("No "+arg+" found !\n");
    return 0;
   }
   env=E(ob);
   env->long();
   if (interactive(ob))
       write(capitalize(ob->query_real_name())+"\n");
   else 
       write(ob->query_name()+"\n");
   return 1;
 } 

/* guild setting */

int mguild(string str) 
{
  int gnr;
    if(!str) return 0;
       gnr = "/guild/master"->query_number(str);
    if(gnr == -1) 
    {
      notify_fail("No such guild exists.\n");
      return 0;
    }
    if(this_player()->query_guild() == gnr) 
    {
      notify_fail("But you already belong to " + str + " guild.\n");
      return 0;
    }
    this_player()->set_guild(gnr);
    write("You join the " + str + " guild.\n");
   return 1;
 }
   

int clean() 
{
  object *ob;
  int i, sz;

  ob=all_inventory(environment(TP));

  for (sz = sizeof(ob), i=0;i< sz;i++) 
  {
    if (!ob[i]->id("castle") && !ob[i]->id("door") &&
        !ob[i]->query_player() && !ob[i]->id("board") ) 
    {
       write(file_name(ob[i])+" (destructed) \n");
       destruct(ob[i]);
    }
  } /* endfor */
  return 1;
}

int dir_upd(string p)
{
    string path;
    string *files;
    object master;
    int i, sz;

    path = "/"+this_player()->query_path()+"/";
    if(p && stringp(p))
    {
        if(p[0]=='/') path = p+"/";
        else          path += p+"/";

	if(file_size(path)!= -2) 
	{
	    write("No such directory! ("+path+")\n");
	    return 1;
	}
    }

    files = get_dir(path+".");

    for (sz = sizeof(files),i=0;i<sz;i++)
    {
        if (master = find_object(path+files[i]))
        {
            write(files[i]+"\n");
            destruct(master);
         }
    }
    write("Ok, "+path+" updated.\n");
    return 1;
}

        
int _ld()
{
    string path;
    string *files;
    int i, sz;

    path = "/"+this_player()->query_path()+"/";
    files = get_dir(path+".");

    for (sz = sizeof(files),i=0;i<sz;i++)
    {
       if (!catch(call_other(path+files[i],"???")))
       {
        write(files[i]+"\n");
       }
    }
    write("Ok, "+path+" loaded.\n");
    return 1;
}

int do_shad(string arg)
{
 string *plod, f;
 string who, file;
 int time;
 string t;
 object mob;
 object shad;

   if (!arg) return 0;
   sscanf(arg,"%s %s %s",who,t,file);
  time = to_int(t);
  if (stringp(who) && intp(time) && stringp(file) )
  {
     plod = explode(file,"/");
    f =plod[sizeof(plod)-1];
     mob = find_living(who);
     if (mob && living(mob))
     {               
        shad = clone_object(file);
        shad->start_shadow(mob,time,f);
        write("Ok shadowed.\n");
        return 1;
    }
 }
 return 0;
}
/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* List call out */

object *ob,u;
int i;


int mcall()
{
  write("Call out info display.\n\n");
  ob=call_out_info();
  i=0;
           
  mcall2("");
  return 1;
}

int mcall2(string str)
{
   mixed u;


  if (str=="q") return 1;
  ob=call_out_info();
  while(i<sizeof(ob)) {
    u=ob[i];
    if (u) {
    write(u[1]);
    write(" ");
    write(u[0]);
    write(" ");
    write(u[2]);
    } else {
    write("N/A ?");
    }
    write("\n");
    i++;
    if (i%18==0) {
      write("<q> to quit, <enter> for more.");
      input_to("mcall2");
      return 1;
    }
  }
  write(sizeof(ob)+" call_out(s) in total.\n");
  return 1;
}
do_scan() { return 0; }
