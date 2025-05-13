object obj;
int light;

id(str) { return str == "wand"; }

short() { return "A wand"; }

init() {
  add_action("call","call");
  add_action("fi","fi");
  add_action("create","create");
  add_action("move","move");
  add_action("copy","copy");
  add_action("wand_examples","examples<<wand");
  add_action("help","help<<wand");
  add_action("stat","sstat");
  add_action("dest","sdest");
  add_action("stone","stone");
  add_action("light","light");
  add_action("dark","dark");
  add_action("fire","burn");
  add_action("post","post");
  add_action("set","set");
}

drop() { return 1; }

long() {
  write("This is a small black wand. Try help<<wand for help.\n");
  if (light > 0) { write("This is a light source strength "+light+".\n"); }
  if (light < 0) { write("This is a light absorber strength "+(-light)+".\n"); }
}

help() {
  write("It can do all these things:\n");
  write("fi <objec>           Gives full inventory of that object.\n");
  write("call <objec> <funs>  Calls any function in object.\n");
  write("create t|w|m|a       Creates a treasure/weapon/monster/armor.\n");
  write("move <objec> <objec> Moves an object somewhere.\n");
  write("copy <objec>         Copies an object and puts it you your inventory.\n");
  write("                     Note: dont copy things that need to be customized by\n");
  write("                     setting things, e.g. armor, weapons etc.\n");
  write("copy <objec> <objec> As above, but puts the copy in the 2nd argument.\n");
  write("sstat <objec>        Superstats an object.\n");
  write("sdest <objec>        Super(internally recursive)destructs an object.\n");
  write("                     i.e. the object and everything in everything in.. etc.\n");
  write("stone <objec>        Turns an object to stone.\n");
  write("burn  <objec>        Burns an object and eventually destructs it.\n");
  write("light [+|-]<num>     Alters [+|-] or sets wand as a light source.\n");
  write("dark [+|-]<num>      Alters [+|-] or sets wand as a light absorber.\n");
  write("post on|off          Switches mailing capablities on/off.\n");
  write("set                  Shows what object th wand is pointing at.\n");
  write("set @<objec>         Points the wand at an object.\n");
  write("set <funs>           calls set_<funs> in object that wand is pointing at.\n");
  write("\nMore?");
  input_to("help2");
  return 1;
}

help2(str) {
  if (str == "q" || str == "n") return 1;
  write("\n Where <objec> is the id of any object in you, in you environment,\n");
  write("the name of any living object (anywhere).\n");
  write("With special operators << means in and >> means environ.\n");
  write("Also ! means the nth object here. And with # the object no. can\n");
  write("be specified.\n");
  write("me and here are used for this_player(), and environment(this_player()).\n");
  write("and it is used for the object that the wand is pointing at (by set).\n");
  write("\n And where <funs> is a function name or a function name followed by\n");
  write("either (arg) where arg is a string or ($arg) where arg is a integer.\n");
  write("type examples<<wand for examples of use.\n");
  return 1;
}

wand_examples() {
  write("Example:                        What is does:\n");
  write("move bag<<box<<fred here        Moves the bag in the box in fred to my environ.\n");
  write("move me >>fred                  Equivelent to goto fred.\n");
  write("call gem<<bag<<fred query_value Querys the value of the gem in the bag of fred.\n");
  write("call me id(fred)                Is my name fred?\n");
  write("fi bag!3<<fred                  Shows full inv of 3rd bag of fred.\n");
  write("copy #675<<bag                  Makes a copy of object #675 thats in my bag.\n");
  write("copy blob!3<<fred box<<>>eep    Makes a copy of the 3rd blob in fred, and puts\n");
  write("                                the copy in the box next to the eep.\n");
  write("sstat rabbit<<here              superstats the rabbit next to you.\n");
  write("sdest bag                       superdestructs the bag and everything in it.\n");
  write("light -4                        Decreases the wands light source by 4.\n");
  write("dark 2                          Sets the light source as -2.\n");
  write("set @elephant                   Points the wand at the elephant.\n");
  write("set hp($100)                    Sets the hit point as 100 in what the wand is");
  write("                                   pointing at.\n");
  write("\nIf you don't understand any of this please tell me. Caspian.\n");
  return 1;
}

get() { return 1; }

reset(arg) {
  if (arg) return;
  set_light(1);
  light = 1;
}

call(str) {
  string what,func,arg;
  int argd;
  object thing;
  if (!str) { write("Syntax: call <objec> [<objec>]\n"); return 1; }
  if (sscanf(str,"%s %s",what,func)!=2) { return 1; }
  thing = objize(what);
  say(this_player()->query_name()+" waves the wand.\n");
  if (!thing) { write("No such item.\n"); return 1; }
  write("Calling object "+file_name(thing)+"\n");
  if (sscanf(func,"%s(%s)",func,arg)==2) {
    if (sscanf(arg,"$%d",argd)==1) {
      write("Function returns value:"+call_other(thing,func,argd)+"\n");
      return 1;
    }
    write("Function returns value:"+call_other(thing,func,arg)+"\n");
    return 1;
  }
  write("Function returns value:"+call_other(thing,func)+"\n");
  return 1;
}

fi(str) {
  object ob,where;
  string func,arg;
  if (!str) { write("Syntax: fi <objec>\n"); return 1; }
  where = objize(str);
  if (!where) { write("No such object.\n"); return 1; }
  write("Full inventory for "+where->short()+" --- "+file_name(where)+"\n");
  ob = first_inventory(where);
  while (ob) {
    arg = ob->short()+"........................................";
    arg = extract(arg,0,40);
    write(arg+" "+file_name(ob)+"\n");
    ob = next_inventory(ob);
  }
  return 1;
  say(this_player()->query_name()+" waves the wand.\n");
}

create(str) {
  if (!str) { write("Syntax: create treas|armor|monst|weapon\n");
    return 1;
  }
  str = extract(str,0,1);
  if (str == "t") obj = clone_object("obj/treasure");
  if (str == "a") obj = clone_object("obj/armor");
  if (str == "w") obj = clone_object("obj/weapon");
  if (str == "m") obj = clone_object("obj/monster");
  if (!obj) return;
  write("Name: ");
  input_to("create"+str);
  return 1;
}
createt(str) {
  if (!str) { write("You must give an argument for the object's id.\n");
    input_to("createt");
  }     
  obj->set_id(str);
  write("short:");
  input_to("create2t");
  return 1;
}

create2t(str) {
  write("long:");
  obj->set_short(str);
  input_to("create3t");
}

create3t(str) {
  write("Object created.\n");
  if (!str || str == "") str = "You see nothing special.\n";
  say(this_player()->query_name()+" waves his wand.\n");
  obj->set_long(str+"\n");
  move_object(obj,this_player());
}

createa(str) {
  if (!str) { write("You must give an argument for the object's id.\n");
    input_to("createa");
  }     
  obj->set_name(str);
  obj->set_id(str);
  write("short:");
  input_to("create2a");
  return 1;
}

create2a(str) {
  write("long:");
  obj->set_short(str);
  input_to("create3a");
}

create3a(str) {
  write("armour class:");
  if (!str || str == "") str = "You see nothing special.\n";
  obj->set_long(str);
  input_to("create4a");
}
  
create4a(str) {
  int i;
  sscanf(str,"%d",i);
  write("Object created.\n");
  say(this_player()->query_name()+" waves his wand.\n");
  obj->set_ac(i);
  move_object(obj,this_player());
}

createw(str) {
  if (!str) { write("You must give an argument for the object's id.\n");
    input_to("createw");
  }     
  obj->set_name(str);
  obj->set_id(str);
  write("short:");
  input_to("create2w");
  return 1;
}

create2w(str) {
  write("long:");
  obj->set_short(str);
  input_to("create3w");
}

create3w(str) {
  write("weapon class:");
  if (!str || str == "") str = "You see nothing special.\n";
  obj->set_long(str);
  input_to("create4w");
}
  
create4w(str) {
  int i;
  sscanf(str,"%d",i);
  write("Object created.\n");
  say(this_player()->query_name()+" waves his wand.\n");
  obj->set_class(i);
  move_object(obj,this_player());
}

createm(str) {
  if (!str) { write("You must give an argument for the object's id.\n");
    input_to("createm");
  }     
  obj->set_name(str);
  obj->set_id(str);
  write("short:");
  input_to("create2m");
  return 1;
}

create2m(str) {
  write("long:");
  obj->set_short(str);
  input_to("create3m");
}

create3m(str) {
  write("level:");
  if (!str || str == "") str = "You see nothing special.\n";
  obj->set_long(str);
  input_to("create4m");
}
  
create4m(str) {
  int i;
  sscanf(str,"%d",i);
  write("Object created.\n");
  say(this_player()->query_name()+" waves his wand.\n");
  obj->set_level(i);
  move_object(obj,environment(this_player()));
}

move(str) {
  object what,to;
  string whats,tos;
  if (!str) { write("Syntax: move <what> <where>\n"); return 1; }
  if (sscanf(str,"%s %s",whats,tos)!=2) {
    write("Syntax: move <what> <where>\n");
    return 1;
  }
  what = objize(whats);
  to = objize(tos);
  if (!to) { write("Syntax error.\n"); return 1; }
  if (!what) { write("Its not there.\n"); return 1; }
  move_object(what,to);
  say(this_player()->query_name()+" waves the wand.\n");
  write("Object "+what->short()+" moved to "+to->short()+".\n");
  return 1;
}

objize(str) {
  int i,r;
  string a,b;
  if (sscanf(str,"%s!%d",a,i)==2) {
    r = npres(a,i,this_player());
    if (r) return r;
  }
  if (sscanf(str,"%s!%d<<%s",a,i,b)==3) {
    r = npres(a,i,objize(b));
    if (r) return r;
  }
  if (sscanf(str,"#%d",i)==1) {
    r = find_num(i,this_player());
    if (r) return r;
  }
  if (sscanf(str,"#%d<<%s",i,a)==2) {
    r = find_num(i,objize(a));
    if (r) return r;
  }
  if (sscanf(str,">>%s",a)==1) return environment(objize(a));
  if (sscanf(str,"%s<<%s",a,b)==2) return present(a,objize(b));
  if (present(str)) return present(str);
  if (find_living(str)) return find_living(str);
  if (str == "here") return environment(this_player());
  if (str == "me") return this_player();
  if (str == "it") return obj;
  return present(str,environment(this_player()));
}

copy(str) {
  object ob,where;
  string a,b,c,d;
  if (!str) { write("Syntax: copy <objec> [<where>]\n"); return 1; }
  where = this_player();
  if (sscanf(str,"%s %s",c,d)==2) {
    where = objize(d);
    str = c;
  }
  if (!objize(str)) { write("No such object.\n"); return 1; }
  if (sscanf(file_name(objize(str)),"%s#%s",a,b)!=2) {
    write("Syntax copy <object>\n"); return 1; }
  ob = clone_object(a);
  move_object(ob,where);
  say(this_player()->query_name()+" waves the wand.\n");
  write("Object "+ob->short()+" copied and put in "+where->short()+".\n");
  return 1;
}

stat(str) {
  object ee;
  string a,b;
  if (!str) { write("Syntax: sstat <objec>\n"); return 1; }
  obj = objize(str);
  if (!obj) { write("No such object.\n"); return 1; }
  do_stat("long");
  do_stat("short");
  do_stat("query_value");
  do_stat("query_weight");
  do_stat("query_name");
  do_stat("query_read");
  do_stat("armor_class");
  do_stat("weapon_class");
  do_stat("query_money");
  do_stat("query_npc");
  do_stat("can_put_and_get");
  do_stat("get");
  do_stat("query_gender");
  do_stat("query_level");
  do_stat("query_hp");
  do_stat("query_sp");
  do_stat("query_max_hp");
  do_stat("query_max_sp");
  do_statlet("query_str");
  do_statlet("query_int");
  do_statlet("query_wis");
  do_statlet("query_con");
  do_statlet("query_dex");
  do_statlet("query_cha");
  if (obj->query_dex()) write("\n");
  ee = environment(obj);
  if (ee) { write("environment: "+file_name(ee)+" ("+ee->short()+")\n"); }
  if (sscanf(file_name(obj),"%s#%s",a,b)==2) {
    write("Cloned from file: "+a+"\n");
    write("Object number: #"+b+"\n");
    return 1;
  }
  write("An original object (e.g. room). file: "+file_name(obj)+"\n");
  return 1;
}

do_stat(str) {
  if (call_other(obj,str)) { write(str+": "+call_other(obj,str)+"\n"); }
}

do_statlet(str) {
  if (call_other(obj,str)) { write(extract(str,6)+": "+call_other(obj,str)+"  "); }
}
npres(str,i,ob) {
  object thing;
  thing = first_inventory(ob);
  while (thing) {
    if (thing->id(str)) {
       i --;
      if (i == 0) return thing;
    }
  thing = next_inventory(thing);
  }
  return;
}

find_num(i,ob) {
  object thing;
  string a;
  int j;
  thing = first_inventory(ob);
  while (thing) {
    if (sscanf(file_name(thing),"%s#%d",a,j)==2) {
      if (i == j) { return thing; }
    }
    thing = next_inventory(thing);
  }
}

dest(str) {
  object thing;
  if (!str) { write("Syntax: sdest <objec>\n"); return 1; }
  thing = objize(str);
  if (!thing) { write("No such object.\n"); return 1; }
  rdest(thing);
  return 1;
}

rdest(obj) {
  object in,next;
  in = first_inventory(obj);
  if (!in) {
    write("You superdestruct "+lower(obj->short())+".\n");
    destruct(obj);
    return;
  }
  while (in) {
    next = next_inventory(in);
    rdest(in);
    in = next;
  }
  write("You superdestruct "+lower(obj->short())+".\n");
  destruct(obj);
}

light(str) {
  int i;
  if (!str) { write("Syntax: light [+|-]<num>\n"); return 1; }
  if (sscanf(str,"+%d",i)==1) { make_light(light+i); return 1; }
  if (sscanf(str,"-%d",i)==1) { make_light(light-i); return 1; }
  if (sscanf(str,"%d",i)==1) { make_light(i); return 1; }
  write("Syntax: light [+|-]<num>\n");
  return 1;
}

make_light(i) {
  if (i<0) i=0;
  set_light(i-light);
  light = i;
  write("Wand is now a light source strength "+i+".\n");
}

dark(str) {
  int i;
  if (!str) { write("Syntax:dark [+|-]<num>\n"); return 1; }
  if (sscanf(str,"+%d",i)==1) { make_dark(light+i); return 1; }
  if (sscanf(str,"-%d",i)==1) { make_dark(light-i); return 1; }
  if (sscanf(str,"%d",i)==1) { make_dark(i); return 1; }
  write("Syntax: dark [+|-]<num>\n");
  return 1;
}

make_dark(i) {
  if (i<0) i=0;
  set_light(-i-light);
  light = -i;
  write("Wand is now a light absorber strength "+i+".\n");
}

stone(str) {
  object ob,statue;
  string a;
  if (!str) { write("Syntax: stone <objec>\n"); return 1; }
  ob = objize(str);
  if (!ob) { write("No such object.\n"); return 1; }
  a = ob->query_name();
  if (!a) a = lower(ob->short());
  statue = clone_object("obj/treasure");
  statue->set_id("statue");
  statue->set_name("A statue of "+a);
  statue->set_alias(a);
  statue->set_short("A statue of "+a);
  statue->set_long("This was once a living being, but now it is but a petrifed image of its former self.\n");
  statue->set_weight(ob->query_weight());
  tell_env(ob,ob->short()+" turns to stone.\n");
  write("You turn "+lower(ob->short())+" to stone.\n");
  move_object(statue,environment(ob));
  move_object(ob,statue);
  say(this_player()->query_name()+" waves the wand.\n");
  return 1;
  destruct(ob);
}

fire(str) {
  object env,ob,fire;
  string a;
  if (!str) { write("Syntax: fire <objec>\n"); return 1; }
  ob = objize(str);
  if (!ob) { write("No such object.\n"); return 1; }
  say(this_player()->query_name()+" waves the wand.\n");
  write("You burn "+lower(ob->short())+".\n");
  a = "A ball of flames flies out of nowhere and hits "+lower(ob->short())
    + "\nwhich promptly bursts into flames.\n";
  tell_env(ob,a);
  fire = clone_object("players/whisky/garden/obj/flames");
  move_object(fire,ob);
  fire->start_burn();
  return 1;
}

post(str) {
  if (str != "on" && str != "off") { write("Syntax: post on|off\n"); return 1; }
  if (str == "off") {
    if (present("mailread")) {
      destruct(present("mailread"));
      write("Mailing capabilities now off.\n");
      return 1;
    }
    write("Mailing capabilities are off already.\n");
    return 1; }
  if (present("mailread")) {
    write("Mailing capabilities already on.\n");
    return 1;
  }
  move_object(clone_object("obj/mail_reader"),this_player());
  write("Mailing capabilities are now on.\n");
  return 1;
}

lower(str) {
  if (!str) return "an invisible object";
  return lower_case(str);
}

query_auto_load() { return "players/caspian/wand:"+light; }

init_arg(a) { sscanf(a,"%d",light); }

tell_env(ob,str) {
  object env;
  env = environment(ob);
  tell_room(ob,str);
  if (!env) return;
  tell_room(env,str);
  return 1;
}

set(str) {
  string a,b;
  int bd;
  if (!str) {
    if (!obj) { write("Wand no currently set on any object.\n"); return 1; }
    write("Wand set on "+lower(obj->short())+"\n");
    return 1;
  }
  if (sscanf(str,"@%s",a)==1) {
    obj = objize(a);
    if (!obj) { write("No such object.\n"); return 1; }
    write("Set on "+lower(obj->short())+".\n");
    say(this_player()->query_name()+" points the wand at something.\n");
    return 1;
  }
  if (sscanf(str,"%s(%s)",a,b)!=2) {
    write("Syntax: set <function>[(<argument>)]\n");
    write("        set @<objec>\n"); return 1;
  }
  write("Calling object "+file_name(obj)+"\n");
  if (sscanf(b,"$%d",bd)==1) {
    write("Setting "+a+" to integer "+bd+".\n");
    call_other(obj,"set_"+a,bd);
    return 1;
  }
  write("Setting "+a+" to "+b+".\n");
  call_other(obj,"set_"+a,b);
  return 1;
}
