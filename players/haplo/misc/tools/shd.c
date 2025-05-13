id (str) { return str=="show" || str=="spy"; }
short () { return "Shadow Spy"; }
long() {write("This item shows who is using shadows.\n"); return 1;}
init() {
 add_action("view");                add_verb("sview");
 add_action("show_shadows");        add_verb("sv");
 add_action("dest_shadows");        add_verb("Sdest");
 add_action("alert_sdest");         add_verb("sdest");
 add_action("prev_shadow");         add_verb("prev");
 add_action("dest_guild_shadows");  add_verb("sclean");
 add_action("dest_spec_shadow");    add_verb("rms");
 add_action("help");                add_verb("help");
}
 
help(str) {
 if (str!="show" && str!="spy" && str!="shadow") return;
 
write("Shadow Spy (TM) - v1.1\n");
write("sv             :  Show all shadows on all users logged in.\n");
write("sview <user>   :  See shadows on a specific user.\n");
write("sdest <user>   :  Destruct all shadows on a specific user.\n");
write("Sdest <user>   :  Silent sdest.\n");
write("rms <user> <#> :  Remove shadow <#> from specified user.\n");
write("sclean         :  Rid all players of excess guild shadows.\n");
if (this_player()->query_level() > 10000)
write("prev <user>    :  Activate prevention shadow to prohibit shadowing.\n");
return 1;
}
 
show_shadows() {
  object u;
  string name;
int i;
write("Shadow Spy (TM)  - by Tarod (To keep you guys in line.) :-)\n");
    u=users();
    i=0;
        while(i<sizeof(u)){
          name=u[i]->query_real_name();
          if(!name)name="logon";
          show(name,u[i]);
	     i+=1;
	     }
	write("\n");
    return 1;
	}
 
get () { return 1; }
 
show(str,u_obj) {
object obj;
 
string fn;
write(capitalize(str)+":    \t");
 obj=shadow(u_obj,0);
  if (!obj) {write("Not Shadowed\n"); return 1;}
  fn = file_name(obj);
  write("Shadowed by:  "+fn+"\n");
   obj=shadow(obj,0);
  while (obj) {
	write("Muliple Shadows:   **  \t"+file_name(obj)+"\n");
	obj=shadow(obj,0);
    }
 return 1;
}
 
view(str) {
object obj;
string fn;
if (find_shadowed_player(str)) {
write(capitalize(str)+":     \t");
  obj=shadow(find_shadowed_player(str),0);
  if (!obj) {write("Not Shadowed\n"); return 1;}
  fn = file_name(obj);
  write("Shadowed by:  "+fn+"\n");
 obj=shadow(obj,0);
  while (obj) {
	write("Multiple Shadows:   **  \t"+file_name(obj)+"\n");
	obj=shadow(obj,0);
    }
	return 1;
}
write("Find shadows on who?\n");
return 1;
}
 
alert_sdest(str) {
object target;
 
    target=find_shadowed_player(str);
    if (!target) { write("sdest:  target not found\n"); return 1; }
    if (environment(target)==environment(this_player())) {
        write("You tear the shadows from "+
            capitalize(target->query_real_name())+".\n");
        say(capitalize(this_player()->query_real_name())+
            "tears the shadows from "+
            capitalize(target->query_real_name())+".\n");
        }
     else {
        write("You tear the shadows from "+
              capitalize(target->query_real_name())+".\n");
        tell_object(target,capitalize(this_player()->query_real_name())+
              " tears your shadows from you.\n");
        }
     dest_shadows(str);
return 1;
}
 
dest_shadows(str) {
object obj, n_obj;
string fn;
if (find_shadowed_player(str)) {
write(capitalize(str)+":\t");
  obj=shadow(find_shadowed_player(str),0);
  if (!obj) {write("Not Shadowed\n"); return 1;}
  fn = file_name(obj);
  write("Shadowed by:  "+fn);
  n_obj=obj;
  obj=shadow(obj,0);
  destruct(n_obj);
  write(" <- Destructed!\n");
  while (obj) {
    write("Multiple Shadows:   **  \t"+file_name(obj));
      n_obj=obj;
      obj=shadow(obj,0);
    destruct(n_obj);
write(" <- Destructed!\n");
}
	return 1;
}
write("Dest shadows on who?\n");
return 1;
}
 
prev_shadow(str) {
 
if (this_player()->query_level() < 10000) return 0;
if (find_living(str)) {
  write("Preventing shadows on "+capitalize(str)+".\n");
  find_living(str)->disable_shadow();
    return 1;
 }
 write(capitalize(str)+" not found.\n");
 return 1;
}
 
find_shadowed_player(str) {
object u;
int i;
string name;
    u=users();
    i=0;
        while(i<sizeof(u)){
          name=u[i]->query_real_name();
          if(!name)name="logon";
          if (name==str) return u[i];
	     i+=1;
	     }
 return 0;
}
 
dest_guild_shadows() {
object u;
int i;
string name;
u=users();
    i=0;
        while(i<sizeof(u)){
          name=u[i]->query_real_name();
          if(!name)name="logon";
          clean_shadows(u[i]);
	     i+=1;
	     }
 return 1;
}
 
clean_shadows(player) {
object obj, n_obj;
string fn;
  write(capitalize(player->query_real_name())+" is ");
   obj=shadow(player,0);
  if (!obj) {write("not shadowed.\n"); return 1;}
  fn = file_name(obj);
  write("shadowed by:  "+fn);
  n_obj=obj;
  obj=shadow(obj,0);
  if ((player->query_level() < 31) && (player->query_class_name() !=
       n_obj->query_shadow_name()) && (n_obj->query_shadow_name()) ){
            destruct(n_obj);
            write(" <- Destructed!\n");
  }
  else write(" <- Valid Shadow\n");
  while (obj) {
    write("Multiple Shadows:   **  \t"+file_name(obj));
      n_obj=obj;
      obj=shadow(obj,0);
      if ((player->query_level() < 31) && (player->query_class_name() !=
           n_obj->query_shadow_name()) && (n_obj->query_shadow_name())){
            destruct(n_obj);
            write(" <- Destructed!\n");
      }
      else write(" <- Valid Shadow\n");
    }
  return 1;
}
 
dest_spec_shadow(str) {
object obj, n_obj;
string fn, who;
int snum, count;
if (sscanf(str,"%s %d",who,snum)!=2) {
        write("Shadow Spy:  Invalid Paramaters\n");
        return 1;
    }
if (find_shadowed_player(who)) {
write(capitalize(who)+":\t");
  obj=shadow(find_shadowed_player(who),0);
  if (!obj) { write("Not Shadowed\n"); return 1; }
  fn = file_name(obj);
  count=1;
  write("Shadowed by:  "+fn);
  n_obj=obj;
  obj=shadow(obj,0);
  if (count==snum) {
    destruct(n_obj);
    write(" <- Destructed!\n");
    }
  else write(" <- Ignored.\n");
  while (obj) {
    write("Multiple Shadows:   **  \t"+file_name(obj));
      n_obj=obj;
      obj=shadow(obj,0);
      count++;
      if (count==snum) {
            destruct(n_obj);
            write(" <- Destructed!\n");
        }
       else write(" <- Ignored.\n");
}
	return 1;
}
write("Dest shadow on who?\n");
return 1;
}
 
