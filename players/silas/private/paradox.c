/*  LAST EDIT: Wed Oct 16 16:33:27 1991 by Michael Schmidt (michael)  */
/*  LAST CHNG: Wed Mrz 08 02:01:00 1992 by Herbert Rosmanith (herp)   */
inherit "obj/player";
object pob, rem_obj, old_rem_obj, fob, fob_, last_arg;
int count, toggle;
 
#define FILENAME "players/silas/private/paradox:"
#define Name(XXX) call_other(XXX,"query_name")
 
Ok() { write("Ok.\n"); return 1; }
 
Fail(str) { write("Couldn't find '" + str + "'.\n"); return 1; }
 
query_auto_load() { return FILENAME; }
 
can_put_and_get() { return 1; }
 
add_weight(w) { return 0; }
 
short() { return "The Book of Paradox"; }
 
long() {
  write("This is a crisp, new volume.  It appears to be magically maintained\n"+
    "that way.  You could open it to read the instructions...\n");
}
 
id(str) { return str=="book" || str=="paradox" || str=="book of paradox"; }
 
get() { return 1; }
 
drop() { return 1; }
 
init() {
  if (!environment()) return;
  if (this_player() != environment(this_object())) return;
  if (!this_player()->query_wizard()) return;
  toggle = 1;
  fob = this_player();
  tell_object(fob,"The Book of Paradox magically appears in your hands.\n");
  add_action("set_count","count");
  add_action("Get","Get");
  add_action("reset_room","reset");
  add_action("s_rm","rm");
  add_action("mailbox","mailbox");
  add_action("faint","faint");
  add_action("shake_head","no");
  add_action("roll_eyes","roll");
  add_action("carry","carry");
  add_action("peer_at","peer");
  add_action("xmn","xmn");
  add_action("scratch","scratch");
  add_action("toggle_echo","toggle");
  add_action("gods","gods");
  add_action("archs","archs");
  add_action("rep2","rep");
  add_action("log2","log");
  add_action("setmdest","setmdest");
  add_action("setmclone","setmclone");
  add_action("des","Dest");
  add_action("guffaw","guffaw");
  add_action("stifle","stifle");
  add_action("pat","pat");
  add_action("nudge","nudge");
  add_action("work","work");
  add_action("incred","incred");
  add_action("thunderbolt","bolt");
  add_action("disappointed","dis");
  add_action("efunction3","efun3");
  add_action("efunction","efun");
  add_action("lfunction","lfun");
  add_action("lpc_function","lpc");
  add_action("build_function","build");
  add_action("cmd_function","cmd");
  add_action("snooptrace","sn");
  add_action("docs_help","docs");
  add_action("example_help","example");
  add_action("open_book","open");
  add_action("open_book","read");
  add_action("help_book","help");
  add_action("Goto","Goto");
  add_action("List","List");
  add_action("set_light_strength","light");
  add_action("remember","rem");
  add_action("here","here");
  add_action("trace","trace");
  add_action("goin","Goin");
  add_action("kig","Look");
  add_action("Flyt","Move");
  add_action("CLONE","Clone");
  add_action("Trans","Trans");
  add_action("snooptrace","snooptrace");
  add_action("destr","dest");
  add_action("des","Destruct");
  add_action("patch","patch");
  add_action("clean1","clean");
  add_action("here","I");
}
 
write_ob_and_desc(obj) {
  string str;
  if(!obj) return 0;
  write(obj);write(" <-> ");
  str = call_other(obj,"short",0);
  if (!str) str = obj->query_name();
  if(!str) str = "Invisible object.";
  write(str + "\n");
  return 1;
}
 
s_cat(str) {
  string name;
  if(str) return 0;
  name = call_other(fob,"query_real_name",0);
  write("Error log:\n");
  cat("/log/" + name);
  return 1;
}
 
s_rm(str) {
 
  string name;
  if(str) return 0;
  name = call_other(fob,"query_real_name",0);
  write("Error log cleared.\n");
  rm("/log/" + name); return 1;
}
 
mail(str) {
  object post;
  if(!str) return 0;
  call_other("room/post","mail",str);
  return 1;
}
 
snooptrace(str) {
  object players;
  string name;
  int i;
  object victim,snooper;
  if (fob->query_level() < 21) {
    write ("Only ArchWizards may use the Snoop Backtrace.\n");
    return 1;
  }
  if (!str) {
    players=users();
    while (i<sizeof(players)) {
      snooper=query_snoop(players[i]);
      name=players[i]->query_real_name();
      name=capitalize(name);
      name=name+extract("                     ",0,20-strlen(name));
      if (!snooper)
        write (name+" : Not snooped.\n");
      else
        write (name+" : Snooped by "+
               capitalize(snooper->query_real_name())+".\n");
      i=i+1;
    }
    return 1;
  }
  victim=find_ob(str);
  if (!victim) return 0;
  snooper=query_snoop(victim);
  if (!snooper) {
    write (capitalize(str)+" is *NOT* snooped.\n");
    return 1;
  }
  write (capitalize(victim->query_real_name())+
         " is snooped by "+
         capitalize(snooper->query_real_name())+".\n");
 
  return 1;
}
 
read(str) {
  if(!str) { call_other("room/post","query_mail",0); return 1; }
  if(str == "mail") call_other("room/post","read_mail",0);
  return 1;
}
 
Trans(str) {
  if(!str) { write("Usage: Trans [object]\n"); return 1; }
  pob = find_ob(str);
  if(!pob) pob = clone_object(str);
  if(!pob) { Fail(str); return 1; }
  move_object(pob, environment(fob));
  Ok();
  return 1;
}
 
CLONE(str) {
  object ob;
  string s;
  if(sscanf(str,"/%s",s) == 1) ob = clone_object(s);
  else ob = clone_object("players/"+ call_other(fob,"query_real_name") +"/"+ str);
  if(!ob) { Fail(str); return 1; }
  if(call_other(ob,"get",0)) move_object(ob,fob);
  else move_object(ob,environment(fob));
  Ok();
  return 1;
}
 
Flyt(str) {
  object ob1, ob2;
  string what1, what2;
  if(!str) {
    write("Usage : Move <object1> into <object2>\n");
    write("WARNING: Don't make object1 = pathname; can be fatal!\n");
    return 1;
  }
  if(sscanf(str,"%s into %s",what1, what2) !=2)
    if(sscanf(str,"%s %s",what1, what2) !=2) { Flyt(); return 1; }
  ob1 = find_ob(what1);
  if(!ob1) ob1 = clone_object(what1);
  if(!ob1) { Fail(what1); return 1; }
  ob2 = find_ob(what2);
  if(!ob2) ob2 = clone_object(what2);
  if(!ob2) { Fail(what2); return 1; }
  move_object(ob1, ob2);
  Ok();
  return 1;
}
 
Goto(str) {
  object ob;
  if(!str) {
    write("Goto moves you to the environment of living objects,\n");
    write("and inside non-living objects.\n");
    return 1;
  }
  ob = find_ob(str);
  if(!ob) {
    move_object(fob, str);
    call_other(fob, "look", 0);
    return 1;
  }
  if(!ob) { Fail(str); return 1; }
  if(living(ob)) move_object(fob, environment(ob));
  else move_object(fob, ob);
  call_other(fob, "look", 0);
  return 1;
}
 
des(str) {
  object dob;
  if(!str) { write("Destruct what ?\n"); return 1; }
  if(str == "rem") {
    dob = environment(rem_obj);
    write("Destructing\n   ");write_ob_and_desc(rem_obj);
    destruct(rem_obj);
    rem_obj = dob;
    if(rem_obj) {
      write("New rem_obj :\n   ");
      write_ob_and_desc(rem_obj);
    }
    write("Ok.\n");;
    return 1;
  }
  dob = find_ob(str);
  if(!dob) { Fail(str); return 1; }
  write("Destructing\n   ");write_ob_and_desc(dob);
  destruct(dob);
  Ok();
  return 1;
}
 
Get(str) {
  object ob;
  string what, item;
  if(!str) { write("Get what ?\n"); return 1; }
  if(sscanf(str,"%s from %s", item, what) == 2) {
    ob = find_ob(what);
    if(!ob) { Fail(what); return 1; }
    ob = present(item, ob);
    if(!ob) { Fail(what); return 1; }
    move_object(ob, fob);
    Ok(); return 1;
  }
  ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  move_object(ob, fob); Ok(); return 1;
}

clean1(str) {
  object tob, ob;
  if(!str) { write("Usage : clean [obj]\n"); return 1; }
  ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  write("Cleaning :\n   "); write_ob_and_desc(ob);
  clean2(ob);
  Ok(); return 1;
}
 
clean2(env) {
  object tob,ob;
  int check;
  int n;
 
  ob = first_inventory(env);
  while(ob) {
    tob = next_inventory(ob);
    check = sscanf(file_name(ob),"obj/player#%d",n) ||
      ob->id("soul") ||	ob->id("exsoul") || ob->id("paradox") ||
      ob->id("mage") || ob->id("tool") || ob->id("wand") ||
      ob->id("quicktyper") || ob->id("nutshell") || ob->id("mailread");
    if (!check) {
      if (first_inventory(ob)) clean2(ob);
      destruct(ob);
    }
    check = 0;
    ob = tob;
  }
  return 1;
}
 
reset_room(str) {
    object ob;
    if (!str) ob = environment(fob);
    else ob = find_ob(str);
    if (!ob) { write("No such object: '" + str + "'.\n"); return 1; }
    ob->reset(1);
    say(fob->query_name()+" utters an ancient spell of unknown origin.\n");
    say("The room reverts to its original condition!\n");
    write("You reset :\n   "); write_ob_and_desc(ob);
    return 1;
}
 
goin(str) {
  object ob;
  if(!str) { write("Usage : Goin [object]\n"); return 1; }
  ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  move_object(fob,ob);
  Ok();
  return 1;
}
 
trace(str) {
    object ob;
    if(!str) { write("Usage : trace [object]\n"); return 1; }
    ob = find_ob(str);
    if (!ob) { Fail(str); return 1; }
    write("Object   : ");write_ob_and_desc(ob);
    write("Location : ");
    if(environment(ob)) write_ob_and_desc(environment(ob));
    else write("None !\n");
    return 1;
}
 
kig(str) {
  object ob;
  if(!str) ob = environment(fob);
  else ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  call_other(ob, "long",0);
  if(!str) here("env"); else here(str);
  return 1;
}
 
reset(arg) {
 ::reset(arg);
 if(arg)
   return;
}
 
set_light_strength(str) {
  int n;
  string what;
  if(!str) {
    write("Current light-strength = " + set_light(0) + "\n");
    return 1;
  }
  if(sscanf(str, "%d", n) == 1) {
     set_light(n);
     if(n > 0) {
       say(fob->query_name() + "'s book glows brightly !!\n");
       write("Your book lights up this dark place > :-)\n");
     }
     else
       tell_room(environment(fob),"Everything suddenly gets darker.\n");
     return 1;
  }
}
 
set_count(n)
{ if(sscanf(n,"%d",count) == 1) Ok(); else return 0; count -= 1; return 1; }
 
patch(str) {
  object ob;
  string who, do_str, arg, cap_name;
  int iarg, check;
  if(!str) { write("Usage : patch [object] [function] [argument]\n"); return 1; }
  if(sscanf(str,"%s %s %s",who, do_str, arg) == 3)
    { if(sscanf(arg,"%d",iarg) == 1) check = 1; }
  else if(sscanf(str,"%s %s", who, do_str) == 2) check = 1;
  else { write("Wrong arguments!!\n"); return 1; }
  ob = find_ob(who);
  if(!ob) {
Fail(who); return 1; }
  if(check) last_arg = call_other(ob,do_str,iarg);
  else {
   string x1,x2,x3,x4,x5;
   if(sscanf(arg,"%s,%s",x1,x2) != 2)
     last_arg = call_other(ob,do_str,arg);
   else if(sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5) == 5)
     last_arg = call_other(ob,do_str,x1,x2,x3,x4,x5);
   else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4) == 4)
     last_arg = call_other(ob,do_str,x1,x2,x3,x4);
   else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3) == 3)
     last_arg = call_other(ob,do_str,x1,x2,x3);
   else if(sscanf(arg,"%s,%s,%s,%s",x1,x2) == 2)
     last_arg = call_other(ob,do_str,x1,x2);
   else { write("Too many arguments.\n"); return 1; }
  }
  write("Result : "); write(last_arg); write("\n");
  while(count) {
    if(check) call_other(ob,do_str,iarg);
    else call_other(ob,do_str,arg);
    count -= 1;
  }
  return 1;
}
 
search_next(str, obj) {
  int nr;
  if(sscanf(str, "%d", nr) == 1)
    return nr_in_ob(nr, obj);
  else if(str == "env")
    return environment(obj);
  return present(str, obj);
}
 
 find_ob(str) {
  object ob;
  string s1, s2, tmp;
  int nr;
  if(!str) { Error("No arg to find_ob."); return 1; }
  if(sscanf(str, "%s,%s", s1, s2) != 2) {
    if(sscanf(str, "%d", nr) == 1) {
      return nr_in_ob(nr, environment(fob));
    }
    else {
      return search_all(str);
    }
  }
  ob = search_all(s1);
  while(s2 && ob) {
    tmp = 0;
    if(sscanf(s2, "%s,%s", s1, tmp) != 2) s1 = s2;
    ob = search_next(s1, ob);
    s2 = tmp;
  }
  return ob;
}
 
search_all(str) {
  object ob;
  if(!str) { Error("No arg to search_all()."); return 1; }
  if(str == "rem") ob = rem_obj;
  else if(str == "arg") ob = last_arg;
  else if(str == "old") ob = old_rem_obj;
  else if(str == "me") ob = fob;
  else if(str == "env") ob = environment(fob);
  if(!ob) ob = present(str, fob);
  if(!ob) ob = present(str, environment(fob));
  if(!ob) ob = find_object(str);
  if(!ob) ob = find_living(str);
  if(!ob) ob = find_living("ghost of " + str);
  return ob;
}
 
remember(str) {
  object ob;
  int nr;
  string who, what;
  if(!str) {
    if(rem_obj) {
      write("Current rem_obj is :\n");write("   ");
      write_ob_and_desc(rem_obj);
      return 1;
    }
    write("There is currently no rem_obj.\n");
    return 1;
  }
  if(str == "env") {
    if(rem_obj) ob = environment(rem_obj);
    else ob = environment(fob);
  }
  else if(str == "old") ob = old_rem_obj;
  else if(str == "del") { rem_obj = 0; Ok(); return 1; }
  else ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  write("  ");write_ob_and_desc(ob);
  old_rem_obj = rem_obj;
  rem_obj = ob;
  return 1;
}
 
here(str) {
  object ob, where;
  int n;
  if(str) where = find_ob(str);
  else where = fob;
  if(!where) { Fail(str); return 1; }
  write_inv_ob(where);
  return 1;
}
 
write_inv_ob(obj) {
  object ob;
  int n;
  ob = first_inventory(obj);
  write("Inventory of ");write_ob_and_desc(obj);
  while(ob) {
    write(" " + n + ": ");write_ob_and_desc(ob);
    n += 1;
    ob = next_inventory(ob);
  }
  write("That's all.\n");
  return 1;
}
 
Error(str) {
  write("*** Error");
  if(!str) write(".\n");
  else write(": " + str + "\n");
  return 1;
}
 
nr_in_ob(n, obj) {
  object ob;
  int nr;
  nr = n;
  if((nr < 0) || !obj) return 0;
  ob = first_inventory(obj);
  while(ob && nr) {
    ob = next_inventory(ob);
    nr -= 1;
  }
  return ob;
}
 
List() {
  write("Currently remembered objects :\n");
  if(rem_obj)
  write("rem: ");write_ob_and_desc(rem_obj);
  if(old_rem_obj)
  write("old: ");write_ob_and_desc(old_rem_obj);
  if(last_arg)
  write("arg: ");write(last_arg);
  return 1;
}
 
query_rem() { return rem_obj; }
query_old_rem() { return old_rem_obj; }
query_arg() { return last_arg; }
 
efunction(str) {
         if (!str) {
		write("\nAvailable topics in /doc/efun are:\n\n");
                 list_files("/doc/efun");
                 return 1;
         } else {
                 if (!more("/doc/efun/" + str))
                         write("Unknown topic.\n");
                 return 1;
         }
}
 
efunction3(str) {
         if (!str) {
		write("\nAvailable topics in /doc/efun3.0 are:\n\n");
                 list_files("/doc/efun3.0");
                 return 1;
         } else {
                 if (!more("/doc/efun3.0/" + str))
                         write("Unknown topic.\n");
                 return 1;
         }
}
 
lfunction(str) {
         if (!str) {
                 write("\nAvailable topics in /doc/lfun are:\n\n");
                 list_files("/doc/lfun");
                 return 1;
         } else {
                 if (!more("/doc/lfun/" + str))
                         write("Unknown topic.\n");
                 return 1;
         }
}
 
lpc_function(str) {
         if (!str) {
                 write("\nAvailable topics in /doc/LPC are:\n\n");
                 list_files("/doc/LPC");
                 return 1;
         } else {
                 if (!more("/doc/LPC/" + str))
                         write("Unknown topic.\n");
                 return 1;
         }
}
build_function(str) {
         if (!str) {
                 write("\nAvailable topics in /doc/build are:\n\n");
                 list_files("/doc/build");
                 return 1;
         } else {
                 if (!more("/doc/build/" + str))
                         write("Unknown topic.\n");
                 return 1;
         }
}
 
cmd_function(str) {
         if (!str) {
                 write("\nAvailable topics in /doc/w are:\n\n");
                 list_files("/doc/w");
                 return 1;
         } else {
                 if (!more("/doc/w/" + str))
                         write("Unknown topic.\n");
                 return 1;
         }
}
 
docs_help() {
   write("\nThe Book of Paradox contains documentation on the following:\n\n");
   write("lpc\t\tVarious constructs of the LPC language\n");
   write("cmd\t\tWizard commands\n");
   write("build\t\tInfo on creating objects\n");
   write("lfun\t\tLocal functions you can call\n");
   write("efun\t\tExternal functions you can call\n");
   write("example\t\tSome coding examples for different things\n\n");
   write("These topics can be called by themselves for a listing of topics\n");
   write("under them, or with an argument to look at the individual help\n");
   write("file.  For example:  \"build ed0\" will show you the help file\n");
   write("/doc/build/ed0 which explains a little about the line editor, ed.");
   write("\n\n");
   return 1;
}
 
example_help(str) {
         if (!str) {
                 write("\nAvailable topics in /open/examples are:\n\n");
                 list_files("/open/examples");
                 return 1;
         } else {
                 if (!more("/open/examples/" + str))
                         write("Unknown topic.\n");
                 return 1;
         }
}
 
open_book(arg) {
   if (!arg) {
	return 0;
   }
   if (arg=="book" || arg=="paradox" || arg=="book of paradox") {
     write("You open the magical tome and begin to read its contents:\n\n");
     write("This is an upgrade for /open/fizban.staff.  I hope you all\n");
     write("find that this book makes your wizardhood a little bit easier\n");
     write("and more convenient.  Typing \"help book\" will explain the\n");
     write("features of this tool and how to use it.  The help file is\n");
     write("unfortunately a little out of date, but still useful. \n");
     write("\nMore importantly, the Book contains documentation for just\n");
     write("about everything you might want to know.  This is a VERY\n");
     write("useful feature.\n\nType \"docs\" for more information.\n\n");
     write("\t\t\t\t\t\t--Cynic\n\n");
     write("Hit return to see page two...");
     input_to("docs_help");
     return 1;
   }
   return 0;
}
 
help_book(arg) {
   if (arg=="book") {
     more("/local/book.help");
     return 1;
   }
   return 0;
}
 
shake_head(arg) {
   object who;
 
   if (!arg) {
     write("You shake your head no.\n");
     say(fob->query_name()+" shakes "+poss(fob)+" head no.\n");
     return 1;
   }
   who = present(lower_case(arg),environment(fob));
   if (!who || !living(who)) return 0;
   if (who == fob) {
     write("You shake your head to yourself.\n");
     say(fob->query_name()+" shakes "+poss(fob)+" head knowingly.\n");
     return 1;
   }
   write("You shake your head no to "+arg+".\n");
   tell_object(who,fob->query_name()+" shakes "+poss(fob)+
	" head no to you.\n");
   say(fob->query_name()+" shakes "+poss(fob)+" head no to "+arg+".\n",who);
   return 1;
}
 
poss(arg) {
   object actor;
   if (!arg) return 0;
   actor = arg;
   if (actor->query_gender_string()=="male") return "his";
   if (actor->query_gender_string()=="female") return "her";
   return "its";
}
 
roll_eyes(arg) {
   if (arg) return 0;
   write("You roll your eyes to the ceiling.\n");
   say(fob->query_name()+" rolls "+poss(fob)+" eyes to the ceiling.\n");
   return 1;
}
 
faint(arg) {
	write("Your knees buckle and you faint to the floor.\n");
	say(fob->query_name()+" faints and falls to the floor.\n");
	return 1;
}
 
nudge(arg) {
   object who;
 
   if (!arg) {
	write("nudge who?\n");
	return 1;
   }
   who = present(lower_case(arg),environment(fob));
   if (!who || !living(who) || who == fob) return 0;
   write("You nudge "+arg+" provocatively.\n");
   tell_object(who,fob->query_name()+" nudges you provocatively.\n");
   say(fob->query_name()+" nudges "+arg+" provocatively.\n",who);
   return 1;
}
 
peer_at(arg) {
   object who;
   if (!arg) return 0;
 
   who = present(lower_case(arg),environment(fob));
   if (!who || !living(who) || who == fob) return 0;
   write("You peer at "+arg+" quizzically.\n");
   tell_object(who,fob->query_name()+" peers at you quizzically.\n");
   say(fob->query_name()+" peers at "+arg+" quizzically.\n",who);
   return 1;
}
 
scratch(arg) {
   write("You scratch your head and consider the problem.\n");
   say(fob->query_name()+" scratches "+poss(fob)+" head in "+
	"consideration of the problem at hand.\n");
   return 1;
}
 
work(arg) {
   if (!arg) {
     write("You sit down to do some serious work.\n");
     say(fob->query_name()+" sits down to do some serious work.\n");
     return 1;
   }
   write("You sit down to do some serious work on "+arg+".\n");
   say(fob->query_name()+" sits down to do some serious work on "+arg+".\n");
   return 1;
}
 
incred() {
   write("You are incredulous!\n");
   say(fob->query_name()+" is incredulous!\n");
   return 1;
}
 
thunderbolt(arg) {
     write("A bolt of thunder splinters through the room!  The Gods "+
	"are getting angry!!\n");
     say(fob->query_name()+" calls upon the forces of Nature...\n"+
	"A bolt of thunder splinters through the room!\nThe Gods are angered "+
	"at your foolishness, mortals!\n");
     return 1;
}
 
disappointed(arg) {
   object who;
   string him;
 
   if (!arg) {
     write("You look disappointed...\n");
     say(fob->query_name()+" looks disappointed.\n");
     return 1;
   }
   who = present(lower_case(arg),environment(fob));
   him = poss(fob);
   if (him=="his") him = "him";
   if (him=="its") him = "it";
 
   if (!who || !living(who)) return 0;
   if (who == fob) {
     write("You look disappointed in yourself.\n");
     say(fob->query_name()+" looks disappointed in "+him+"self.\n");
     return 1;
   }
   write("You look disappointed in "+arg+".\n");
   tell_object(who,fob->query_name()+" looks at you with disappointment.\n");
   say(fob->query_name()+" looks at "+arg+" with disappointment.\n",who);
   return 1;
}
 
stifle() {
   write("You stifle a laugh.\n");
   say(fob->query_name()+" stifles a laugh.\n");
   return 1;
}
 
guffaw() {
   write("You guffaw at the concept.\n");
   say(fob->query_name()+" guffaws at the very concept!\n");
   return 1;
}
 
pat(arg) {
   object who;
 
   if (!arg) return 0;
   who = present(lower_case(arg),environment(fob));
   if (!who || !living(who) || who == fob) return 0;
   write("You pat "+arg+" on the head.\n");
   tell_object(who,fob->query_name()+" pats you on the head.\n");
   say(fob->query_name()+" pats "+arg+" on the head.\n",who);
   return 1;
}
 
destr(str) {
    object ob;
    if (!str) {
        write("Destruct what ?\n");
        return 1;
    }
    str = lower_case(str);
    ob = present(str, fob);
    if (!ob)
        ob = present(str, environment(fob));
    if (!ob) {
        write("No " + str + " here.\n");
        return 1;
    }
    say(fob->query_name()+" destructs "+ob->short()+".\n");
    destruct(ob);
    write("Ok.\n");
    return 1;
}
 
setmdest(arg) {fob->setmdest(arg); return;}
setmclone(arg) {return;}
 
rep2(arg) {
   string rep;
   rep = arg;
   if (!rep) rep = fob->query_real_name();
   rep = "/log/"+rep+".rep";
   more(rep);
   return 1;
}
 
log2(arg) {
   string log;
   log = arg;
   if (!log) log = fob->query_real_name();
   log = "/log/"+log;
   more(log);
   return 1;
}
 
gods() {
   if (fob->query_level() < 100) {
      tell_object(fob,"You are not allowed to enter the room.\n");
      return 1;
   }
   tell_object(fob,"You enter the room of the Gods.\n");
   fob->move_player("to the Gods' playroom#room/adv_gods");
   return 1;
}
 
archs() {
   if (fob->query_level() < 25) {
      tell_object(fob,"You are not allowed to enter the room.\n");
      return 1;
   }
   tell_object(fob,"You enter the room of the Archwizards.\n");
   fob->move_player("to the Archwizards' playroom#room/adv_gods");
   return 1;
}
 
carry() {
   set_weight(-100);
   return 1;
}
 
mailbox() {
   object box;
   box = clone_object("obj/port_mailbox");
   transfer(box,fob);
   tell_object(fob,"You now have your very own portable mailbox.\n");
   return 1;
}
shout_to_all(str) {
    if (!str) {
        write("Shout what ?\n");
        return 1;
    }
    if (ghost) {
        write("You fail.\n");
        return 1;
    }
    shout(fob->query_name() + " shouts: " + str + "\n");
    if (toggle) write("You shout: "+str+"\n");
    else write("Ok.\n");
    return 1;
}
 
static emote(str) {
    string verb;
 
    verb = query_verb();
    if (str == 0) str = "";
    if (verb[0] == ":"[0]) str = extract(verb,1)+" "+str;
    say(fob->query_name() + " " + str + "\n");
    if (toggle) write("You emote: "+fob->query_name()+" "+str+"\n");
    else write("Ok.\n");
    return 1;
}
communicate(str) {
    string verb;
 
    verb = query_verb();
    if (str == 0)
        str = "";
    if (verb[0] == "'"[0])
        str = extract(verb, 1) + " " + str;
    if (ghost) {
        say(short() + " says: " + str + ".\n");
        return 1;
    }
    say(fob->query_name() + " says: " + str + "\n");
    if (toggle) write("You say: "+str+"\n");
    else write("Ok.\n");
    return 1;
}
static tell(str)
{
    object ob;
    string who;
    string msg;
    if (ghost) {
        write("You fail.\n");
        return 1;
    }
/*
    if (spell_points < 0) {
        write("You are low on power.\n");
        return 1;
    }
    if (!is_wizard)
        spell_points -= 5; */
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
        write("Tell what ?\n");
        return 1;
    }
    it = lower_case(who);
    ob = find_living(it);
    if (!ob) {
        write("No player with that name.\n");
        return 1;
    }
    tell_object(ob, fob->query_name() + " tells you: " + msg + "\n");
    if (toggle) write("You tell "+ob->query_name()+": "+msg+"\n");
    else write("Ok.\n");
    return 1;
}
 
whisper(str)
{
    object ob;
    string who;
    string msg;
    if (ghost) {
        write("You fail.\n");
        return 1;
    }
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
        write("Whisper what ?\n");
        return 1;
    }
    it = lower_case(who);
    ob = find_living(it);
    if (!ob || !present(it, environment(fob))) {
        write("No player with that name in this room.\n");
        return 1;
    }
    tell_object(ob,fob->query_name()+" whispers to you: "+msg+"\n");
    if (toggle) write("You whisper to "+ob->query_name()+": "+msg+"\n");
    else write("Ok.\n");
    say(fob->query_name()+" whispers something to "+who+".\n", ob);
    return 1;
}
 
toggle_echo() {
   if (!toggle) {
      toggle = 1;
      write("Your local echo has been toggled on.\n");
   }
   else {
      toggle = 0;
      write("Your local echo has been toggled off.\n");
   }
   return 1;
}
xmn(arg) {
   object obj;
   string arg1,arg2;
 
   if (!fob->query_wizard()) {
      write("This object is not for you to use.  Sorry.\n");
      destruct(this_object());
      return 1;
   }
   if (!arg) {
      write("Usage:  xmn <object> [in <player>]\n");
      return 1;
   }
   if (sscanf(arg,"%s in %s",arg1,arg2) == 2) {
      if (!find_living(arg2)) {
         write("Could not find "+arg2+".\n");
         return 1;
      }
      obj = findob(arg1,find_living(arg2));
   }
   else {
      obj = find_object(arg);
      if (!obj) obj = findob(arg,fob);
      if (!obj) obj = findob(arg,environment(fob));
   }
   if (!obj) {
      write(arg+" cannot be found.\n");
      return 1;
   }
   write("\n        Item:\t"+obj->short());
   if (creator(obj)) write("\n     Creator:\t"+
      capitalize(creator(obj)));
   write("\n   File Name:\t"+file_name(obj));
   if (obj->query_name()) write("\n        Name:\t"+obj->query_name());
   if (!living(obj)) write("\n      Weight:\t"+obj->query_weight());
   if (!living(obj)) write("\n       Value:\t"+obj->query_value());
   if (obj->query_is_armor()) write("\n Armor Class:\t"+obj->query_ac());
   if (obj->query_is_weapon()) write("\nWeapon Class:\t"+obj->weapon_class());
   if (obj->query_info()) write("\n        Info:\t"+obj->query_info());
   write("\nLong Description -------------------------\n");
   obj->long();
   write("\n");
   return 1;
}
 
findob(arg,where) {
   object tobj;
   tobj = first_inventory(where);
   while(tobj) {
      if (tobj->id(arg)) return tobj;
      tobj = next_inventory(tobj);
   }
}
 
tail_file(str) {
   if (!str) str = "/athene.debug.log";
   if (!tail(str)) return 0;
   return 1;
}
