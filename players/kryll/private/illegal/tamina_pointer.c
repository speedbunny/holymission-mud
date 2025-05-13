#include "/players/tamina/defs.h"

#define INTO     TP->query_intoxination()
#define WIZ      TP->query_wizard() 
#define NEW      TP->query_newwiz() 
#define APPR     TP->query_immortal()
#define FILE     "/players/tamina/pointer:"

/* prototyping */ 
int write_inv_ob(object obj);

int count,lighted,hide; 
string my_id;
object normal,obj,finder,mark;

mixed query_auto_load() 
{ 
  return FILE+hide+"#"+lighted; 
}

void init_arg(mixed arg)
{
  sscanf(arg,"%d#%d", hide, lighted);
}

int drop() 
{ 
  return 1; 
}

int id(string str) 
{ 
  return str == "pointer" || str == my_id; 
}

mixed ladjust(string str,int n) 
{ 
  return extract(str+"                              ",0,n-1);
}

mixed short() 
{
  if (hide) 
    return 0;
  if (lighted) 
    return "A Pointer (lighted)";
  else
   return "A Pointer";
}

void long() 
{
  write(
  "               COMMANDS [Appr]:\n"+
  "             -=-=-=-=-=-=-=-=-=-=-=-=-=-\n"+
  "plight [num] :          The Pointer becomes a lightsource, \n"+
  "man or man [filename] : Help-dirs, \n"+
  "pinv [name] \n"+
  "  or pinv [env] :       Shows the items of name or your environment,\n"+
  "pitem [obj] in [name] : Gives info about an item in a living,\n"+
  "pmail :                 Clones you a mailbox and gives you all commands \n"+
  "                        like in the post,\n"+
  "pmore [obj] :           Filename of room or present object,\n"+
  "ploc [name] :           Location of a living, \n"+
  "pdebug :                Your errorlogfile,\n"+
  "prep :                  Your players' bug file,\n"+
  "plerr :                 Reads the last lined in the lpmud.log, \n"+
  "pwho :                  Revised version of < who >,\n"+
  "pinto [num] :           Sets your intoxination,\n"+
  "phide :                 Hide the Pointer,\n"+
  "pshow :                 Make the Pointer visible, \n"+
  "pguild [guild] :        Change your guild,\n"+
  "pnet or pnet [player] : The ip_number of users\n\n");
  if (NEW)
  {
  write(
  "                 COMMANDS [New]:\n"+
  "             -=-=-=-=-=-=-=-=-=-=-=-=-=-\n"+
  "orc [level] :           Clones a testmonster, \n"+
  "weap [class] :          Clones a testweapon\n"+
  "arm [class] :           Cloning a testarmour, \n"+
  "shad [living] [time] :  Shadowing a living when using /obj/std_shadow, \n"+
  "clean :                 Clears the inventory of your environment,\n"+
  "loaddir :               Loads your current directory, \n"+
  "updir :                 Updates your current directory, \n"+
  "uphere :                Updates your environment, but keeps all players\n"+ 
  "                        in the same room.\n");
  }
   if (hide)
       write("The pointer is currently hidden in your inventory.\n");
   if (lighted)
       write("The lightlevel of your pointer is "+to_string(lighted)+".\n");
}

int get() {  return 1;  }

void init() 
{
  add_action("help","help");
  if (APPR) 
  {
    add_action("plight",   "plight"); 
    add_action("pinto",    "pinto");
    add_action("pmail",    "pmail"); 
    add_action("pitem",    "pitem");
    add_action("pinv",     "pinv"); 
    add_action("pnet",     "pnet");
    add_action("pdebug",   "pdebug");
    add_action("prep",     "prep");
    add_action("pwho",     "pwho");
    add_action("ploc",     "ploc"); 
    add_action("set_count","count");
    add_action("plerr",    "plerr"); 
    add_action("man",      "pman");
    add_action("phide",    "phide"); 
    add_action("pshow",    "pshow");
    add_action("pguild",   "pguild"); 
    add_action("pname",    "pname");
    add_action("pmore",    "pmore");
  }                 
  if (NEW)
  {
    add_action("weap",   "weap");
    add_action("orc",    "orc"); 
    add_action("arm",    "arm"); 
    add_action("do_shad","shad");
    add_action("clean",  "clean");
    add_action("_ld",    "loaddir");
    add_action("_upd",   "updir");
    add_action("uphere", "uphere");
  }
}

/*------------------ Network Connections -----------------------*/

int pnet(string arg)
{
   object *who, mob;
   int i, sz;

   who = users();

   if (!arg)
   {
     for (sz = sizeof(who), i = 0; i < sz; i++)
     {
        write(ladjust(who[i]->RNAME,12)+" "+
                      query_ip_number(who[i])+"\n");
     }
     return 1;
   }
   mob = find_living(arg);
   if (objectp(mob))
   {
     write(mob->RNAME+"\t\t"+query_ip_number(mob)+"\n");
     return 1;
   }
   write("No such player found.\n");
   return 1;
}

/* ------------------- Hide your Pointer ------------------------- */

int phide() 
{ 
  write("You hide your pointer in your inventory.\n"+
        "Just type <pshow> to make it visible again.\n");
  hide = 1;
  return 1;
}

/* ------------------ Show your Pointer -------------------------- */

int pshow() 
{
  write("You make your pointer visible again.\n");
  hide = 0;
  return 1;
}

/* ------------------------- Help Screen -------------------------- */

int help(string str) 
{
  if (str != "pointer")
     return 0;
  else if (!APPR) 
  {
     write("This pointer gives only help for Wizards.\n");
     return 1;
  }
  return 1;
}

/* --------------- Read the file of your environment --------------- */

pmore(arg)
{
    string *ploder;
    string file;
    object mob;

    if (!arg)
    {
        file = file_name(environment(TP))+".c";
        write("Trying to read "+file+"\n");
        TP->more("/"+file);
        return 1;
    }
    else if (mob = present(arg,TP) )
    {
      ploder = explode(file_name(mob),"#");
      file = ploder[0]+".c";
      write("Trying to read "+file+"\n");
      TP->more("/"+file);
      return 1;
    }
    else if (mob = present(arg, E(TP)) )
    {
      ploder = explode(file_name(mob),"#");
      file = ploder[0]+".c";
      write("Trying to read "+file+"\n");
      TP->more("/"+file);
      return 1;
    }
    else
    {
     write("Usage: pmore to get your environment-file, or \n"+
           "       pmore <string> to get an item in your environment.\n");
     return 1;
    }
}

/* ------------------- Update your environment -------------------- */

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
           TOBJ(env[i],"Your environment was updated.\n");
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

   write("Successful update.\n");
   return 1;
}

/* ------------------ Give your Pointer a second id ----------------- */

int pname(string arg)
{
    if (!arg)
    {
        notify_fail("Usage: pname <name>\n");
        return 0;
    }
    my_id = arg;
    write("The second id of your pointer is "+arg+"\n");
    return 1;
}
 
/* ---------------- Setting a light around you ---------------------- */

int plight(string arg) 
{
 int n;

 if (!arg) 
 {
    write("Lightlevel of your environment = " + set_light(0) + "\n");
    return 1;
  }
  if (sscanf(arg , "%d" , n) == 1) 
  {
     if (n > 0) 
     {
        write("Your pointer lights up the dark place !\n");
        set_light(n);
        lighted = n;
     }
     else 
     {
     write("Suddenly everything gets darker !\n");
     lighted = 0;
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

/* ---------------------- Set Intoxication levels ------------------- */

int pinto(string arg) 
{
     int i;

    if (!arg) 
    {
      NFAIL("Syntax: pinto <num>     Current intoxication = "+INTO+"\n");
      return 0;
    }
    if (sscanf(arg, "%d", i) == 1) 
    {
      TP->drink_alcohol(i);
      write("Your current intoxication is now "+INTO+"\n");
      return 1;
    }
    return 1;
}

/* -------------------------- Read the Docs -------------------------- */

int man(string arg) 
{
  int i, sz;
  string *topics;

  topics = ({ 
	      "/doc",     "/doc/efun",  "/doc/lfun",  "/doc/helpdir", 
              "/open",    "/doc/magik", "/doc/local", "/doc/w", 
	      "/doc/build",   "/doc/races", "/doc/rules", "/doc/coding",
              "/doc/LPC", "/doc/guild",    "/doc/abilities",
           });
    
  sz = sizeof(topics);
 
  if (!arg) 
  {
    write("Topics:\n");
    for (i = 0; i < sz; i++)
    write(topics[i]+", ");
    write("\n");
    return 1;
  }
  arg = "/"+arg;
  i = 0;
  while (i < sz) 
  {
    if (file_size(topics[i]+arg) == -2) 
    {
      write ("Subtopics "+topics[i]+arg+":\n");
      ls (topics[i]+arg+"/.");
      return 1;
    }
    if (file_size(topics[i]+arg) > 0) 
    {
      write(topics[i]+arg+":\n");
      TP->more(topics[i]+arg);
      return 1;
    }
    i++;
  }
  write("Manual documents not available on that topic !\n");
  return 1;
}

/* ----------------------- Read your Bugs Log -------------------------- */

int pdebug(string arg) 
{
    if (!arg) 
        arg = TPRN;
   TP->more("/log/"+arg);
   return 1;
} 

/* ---------------------- Read your Typos Log -------------------------- */

int prep(string arg) 
{
  if (!arg)
    arg = TPRN;
  TP->more("/log/"+arg+".rep");
  return 1;
}

/* ---------------------- Read the Mud_Bugs Log ------------------------ */

int plerr() 
{
  tail("/lpmud.log");
  return 1;
}

/* ----------------------- Get a mail-reader --------------------------- */

int pmail() 
{
   object box;
   if (present("mailread", TP)) 
   {
     write("You have already your invisible mailreader !\n");
     return 1;
   }
   box = CLO("obj/mail_reader");
   TR(box, TP);
   write("Now, you can read your mail like in the post !\n");
   return 1;
}
  
mixed findob(mixed arg,mixed where) 
{
  object ob;
  ob = first_inventory(where);

  while(ob) 
  {
    if ((ob->id(arg)) || (ob->SHT == arg) || (ob->NAME == arg)) 
        return ob;
    ob = next_inventory(ob);
  }
}

/* -------------------- Read about item in Player ---------------------- */

int pitem(string arg) 
{
   object obj;
   string arg1,arg2;

   if (!arg) 
   {
     NFAIL("Usage: pitem <obj> in <player> !\n");
     return 0;
   }
   if (sscanf(arg,"%s in %s",arg1,arg2) == 2) 
   {
     if (!find_living(arg2)) 
     {
       write("Couldn't find "+CAP(arg2)+".\n");
       return 1;
     }
     obj = findob(arg1,find_living(arg2));
   }
   else 
   {
     obj = find_object(arg);
   if (!obj) 
     obj = findob(arg, TP);
   if (!obj) 
     obj = findob(arg, E(TP));
   }
   if (!obj) 
   {
     write(CAP(arg)+" cannot be found !\n");
     return 1;
   }
   write("\nItem:\t"+obj->SHT+"\n\n");
                            write("\nFilename:\t"+file_name(obj));
   if (creator(obj))        write("Creator:\t"+CAP(creator(obj)));
   if (obj->query_id())     write("\nId:\t"+obj->query_id());
   if (obj->query_name())   write("\nName:\t"+obj->NAME);
                            write("\nWeight:\t"+obj->query_weight());
   if (!living(obj))        write("\nValue:\t"+obj->query_value());
   if (obj->query_armour()) write("\nArmour Class:\t"+obj->armour_class());
   if (obj->query_weapon()) write("\nWeapon Class:\t"+obj->weapon_class());
                            write("\n\nLong Desc.:\n");
   obj->long();
   write("\n");
   return 1;
}

/* ----------------------- See inventory of Player ---------------------- */

int pinv(string arg) 
{
   object ob, where;
   int n;
   if (!arg) 
   {
      write("Usage pinv <living> !\n");
      return 1;
   }
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
   str = obj->SHT;
   if (!str) str = obj->NAME;
   if (!str) str = "(Invisible Object)";
   write(str+"\n");
   return 1;
}

int write_inv_ob(object obj) 
{
    object ob;
    int n;
    ob = first_inventory(obj);
    write("Inventory of: "); write_ob_and_desc(obj);
    while(ob) 
    {
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
   nr = n;

   if (nr < 0) 
       return 0;
   if (!obj) 
       return 0;
   ob = first_inventory(obj);

   while(ob && nr) 
   {
    ob = next_inventory(ob);
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
   if (str == "env") 
       ob = E(TP);
   if (!ob) 
       ob = present(str, TP);
   if (!ob) 
       ob = present(str, E(TP));
   if (!ob) 
       ob = find_object(str);
   if (!ob) 
       ob = find_living(str);
   if (!ob) 
       ob = find_living("ghost of "+str);
  return ob;
}
   
mixed find_ob(string str) 
{
    object ob;
    string s1, s2, tmp;
    int nr;

    if (!str) 
    {
      NFAIL("ERROR: No argument given to find object.\n");
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
   ob = search_all(str);
   while (s2 && ob) {
   tmp = 0;
   if (sscanf(s2, "%s,%s", s1, tmp) !=2) 
      s1 = s2;
   s2 = tmp;
   }
   return ob;
}
 
/* ----------------------- Cloning Testmonster ----------------------- */

int orc(string arg) 
{
    int i;
    object ob;

   if (!arg) 
   {
     NFAIL("Usage: porc <num> !\n"); 
     return 0;
  }
  if (sscanf(arg , "%d" , i) == 1) 
  {
     if (i > 100) 
     {
        write("The level of the testmonster was too high !\n"+
              "Try again !\n");
     }
     else if (i <= 0) 
     {
        write("You should give an argument > 0 !\n");
     }
     else {
     ob = CLO("obj/monster");
     ob->set_name("orc");
     ob->set_short("An Orc (Tester)");
     ob->set_long("The Testmonster of "+CAP(TPRN)+"\n");
     ob->set_level(i);
     TR(ob, E(TP));
     write("Ok.\n");
    }
     return 1;
  }
  return 1;
}

/* ----------------------- Cloning Testweapon ----------------------- */

int weap(string arg) 
{
    int i;
    object ob;

 if (!arg) 
 {
   NFAIL("Usage: pweap <num> !\n");
   return 0;
 }
 if (sscanf(arg , "%d" , i) == 1) 
 {
   if (i > 20) 
   {
     write("The class of the weapon was > 20 !\n"+
           "Try again !\n");
   }
   else 
   if (i <= 0) 
   {
     write("You should give your weapon a class > 0 !\n");
   }
   else 
   {
     ob = CLO("obj/weapon");
     ob->set_name("sword");
     ob->set_alias("testsword");
     ob->set_short("A testsword");
     ob->set_long("The Testweapon of "+CAP(TPRN)+"\n");
     ob->set_class(i);
     ob->set_weight(1+i/5);
     TR(ob, TP);
     write("Ok.\n");
    }
     return 1;
  }
  return 1;
}

/* ----------------------- Cloning Testarmour ------------------------ */

int arm(string arg) 
{
    int i;
    object ob;

 if (!arg) 
 {
   NFAIL("Usage: parm <num> !\n");
   return 0;
 }
 if (sscanf(arg, "%d " ,i) == 1) 
 {
   if (i > 4) 
   {
     write("The class of the armour was too high !\n"+
           "Try again !\n");
   }
   else 
   if (i <= 0) 
   {
     write("You should give your armour a class > 0 !\n");
   }
   else 
   {
     ob = CLO("obj/armour");
     ob->set_name("mail");
     ob->set_alias("testmail");
     ob->set_short("A testmail");
     ob->set_long("The Testmail of "+CAP(TPRN)+"\n");
     ob->set_ac(i);
     ob->set_weight(1+i);
     TR(ob, TP);
     write("Ok.\n");
     }
     return 1;
  }
  return 1;
}

/* ---------------------- Alternative < who > --------------------------- */

int pwho() 
{
  object *who;
  int i, sz;

  who = users();
  write(
  "Name:           Level Gender str dex int con wis chr WC AC   Money\n");
  for(sz = sizeof(who),i = 0; i < sz; i++) 
  {
  if (who[i]->SHT)
  write(ladjust(who[i]->RNAME, 16)+" ");
  else write(ladjust("("+who[i]->RNAME+")",16)+" ");
  write(ladjust(who[i]->LVL ,5)+" "+
        ladjust(who[i]->query_gender_string(),5)+" "+
        ladjust(who[i]->STR, 3)+" "+
        ladjust(who[i]->DEX, 3)+" "+
        ladjust(who[i]->INT, 3)+" "+
        ladjust(who[i]->CON, 3)+" "+
        ladjust(who[i]->WIS, 3)+" "+
        ladjust(who[i]->CHR, 3)+" "+
        ladjust(who[i]->query_wc(), 3)+" "+
        ladjust(who[i]->query_ac(), 3)+" "+
        ladjust(who[i]->query_money(), 11)+"\n");
   }
  return 1;
}

int ploc(string arg) 
{
   object ob,env;

   ob = find_living(arg);

   if (!arg) 
   {
      NFAIL("Usage: mloc <name> !\n");
      return 0;
   }
   if (!ob) 
   {
     write("No "+CAP(arg)+" found !\n");
     return 1;
   }
   env = E(ob);
   env->long();
   if (interactive(ob))
       write(CAP(ob->RNAME)+"\n");
   else 
       write(ob->NAME+"\n");
   return 1;
} 

/* ----------------------- Change your Guild ------------------------- */

int pguild(string str) 
{
  int gnr;
    if (!str) return 0;
       gnr = "/guild/master"->query_number(str);
    if (gnr == -1) 
    {
      NFAIL("No such guild exists.\n");
      return 0;
    }
    if (this_player()->query_guild() == gnr) 
    {
      NFAIL("But you already belong to " + CAP(str) + " guild.\n");
      return 0;
    }
    this_player()->set_guild(gnr);
    write("You join the " + CAP(str) + " guild.\n");
   return 1;
}

/* ------------------- Clean up your environment ----------------------- */

int clean() 
{
  object *ob;
  int i, sz;

  ob = all_inventory(E(TP));

  for (sz = sizeof(ob), i = 0; i < sz; i++) 
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

/* -------------------- Load your current directory -------------------- */
        
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

/* ------------------ Update your current directory -------------------- */

int _upd()
{
    string path;
    string *files;
    object master;
    int i, sz;

    path = "/"+this_player()->query_path()+"/";
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
