// This is the file you must inherit if you wish to have a standard
// mud room. If you want a room with relative directions, try 
// rel_room.c

#include <lw.h>
#define NO_SEE 1;
#define HIDDEN 2;

// Basic strings and arrays for the room.
string long_desc;  // long desc for room
string short_desc; // brief desc for room
string *no_see;     // directions you cannot see
string *items;      // any items in the room?
string *dest_dir;  // exits in the room
int no_castle_flag;
string smell;
string *property;

string *exit_list;
string *item_list;

// Mappings used inside the room
mapping properties;
mapping expand_dir;
mapping contract_dir;
mapping exits=([]);     
mapping hidden=([]);
mapping doors_list=([]); //will be ([ , ({}) ]) 
mapping items_list=([]);

// Prototypes.
string dir_opposites(string dir);
string query_numbers(int num);
string resolve_path(string path);
string clean_path(string path);
int examine_room(string arg);
varargs string contract_dir(string s, int i);
varargs string expand_dir(string s, int i);
varargs int move_door(string dir,int type,int caller);
int has_key(string dir);
int query_me(object obj);
string get_room_inv(int type);
string query_contract_exits(string dir);
string query_expand_exits(string dir);
int query_door(string str);
string get_inv();
int long(string str);

void init() {
  int loop,counter;
  string d,path,dummy;
  // stuff that gets done when the room is first loaded
  if (dest_dir && !(sizeof(dest_dir)%2)) {
    loop=sizeof(dest_dir);
    counter=0;
    while (loop) {
      d=dest_dir[loop-1][0..0]=="*" ? dest_dir[loop-1][1..] : dest_dir[loop-1];
      path=resolve_path(dest_dir[loop-2]);
      if (sscanf(path,"/0%s",dummy))
        exits[d]= resolve_path(dest_dir[loop-2])[2..];
      else
        exits[d]= resolve_path(dest_dir[loop-2]);

      loop-=2;
    }
  }
  if (sizeof(no_see)) {
    loop=sizeof(no_see);
    while(loop--) 
      hidden[no_see[loop]]=1;
  }
  if (sizeof(items)) {
    loop=sizeof(items);
    counter=0;
    while (loop) {
      items_list[items[loop-2]]=items[loop-1];
      loop-=2;
    }
  }
  if (sizeof(doors_list)) {
    add_action("door",  "open");
    add_action("door",  "close");
    add_action("door",  "lock");
    add_action("door",  "unlock");
  }

  exit_list= m_indices(exits);
  loop=sizeof(exit_list);
  while (loop--) {
    // add load room stuff here
    add_action("move",exit_list[loop]);
  }
  item_list= m_indices(items_list);
  expand_dir=(["n": "north", "ne":"northeast", "e": "east",
	       "se":"southeast","s": "south","sw":"southwest",
	       "w": "west", "nw":"northwest", "u": "up","d": "down",
	       ]);

  contract_dir=([
		 "north": "n", "northeast":"ne", "east": "e",
		 "southeast":"se", "south":"s", "southwest":"sw",
		 "west": "w", "northwest":"nw", "up": "u", "down": "d"
		 ]);
  add_action("examine_room","examine");
  add_action("examine_room","exa");
  add_action("examine_room","look");
  add_action("examine_room","l");
}

string query_short() { 
  if (short_desc[<1..<1]==".")
    return short_desc[0..<2];
  return short_desc;
}

int query_light() {
  return set_light(0);
}

varargs mixed query_exit(string s) {
  return s ? exits[query_expand_exits(s)] : exits; 
}

int query_can_see(string s) {
  string dir;
  s=query_expand_exits(s);
  if( !member(exits,s) || member(hidden,s) || query_door(s)==2)
    return 0;

  return 1;
}
// ---------------------

int short() {
  int size,i,door,loop;
  string txt,dir;
  mixed *obj_list;

  if (set_light(0)<=0) {
    write("It is too dark for you to see.\n");
    return 1;
  }

  if (this_player()->query_wiz_level())
    write("["+file_name(this_object())+"]\n");
  write(lw(process_string(short_desc)+"\n"));
  size=sizeof(exit_list);
  txt=" "+size+" exit"+(size!=1 ? "s" : "" )+ (size ? " : " : ".\n");
  while(size--) {
    door=query_door(exit_list[size]);
    txt+=( door ? 
	   (door==1 ? "open "+query_contract_exits(exit_list[size])+" door" :
	    "closed "+query_contract_exits(exit_list[size])+" door") : 
	   query_contract_exits(exit_list[size]));
    if (size>1) txt+=", ";
    if (size==1) txt+=" & ";
    if (!size) txt+=".\n";
  }
  write(lw(txt));    
  write(lw(get_inv()));
}

string query_contract_exits(string dir) {
  return contract_dir(dir, 1);
}

string query_expand_exits(string dir) {
  return expand_dir(dir, 1);
}

int long(string str) {
  int size,i,door,loop;
  string txt,dir,desc;
  mixed *obj_list;

  if (set_light(0)<=0) {
    write("It is too dark for you to see.\n");
    return 1;
  }

  if (!long_desc) 
    long_desc=short_desc;

  if (!str || str=="**!!**") {
    write(lw(process_string(long_desc)));

    if (str=="**!!**")
      write(lw(get_room_inv(1)));
//    else
//     write(lw(get_inv()));

    size=sizeof(exit_list);
    txt=" "+capitalize(query_numbers(size))+" visible exit"+(size!=1 ? "s" : "" )+ (size ? " : " : ".\n");
    while(size--) {
      door=query_door(exit_list[size]);
      txt+=( door ? 
	    (door==1 ? "an opened "+exit_list[size]+" door" :
	     "a closed "+exit_list[size]+" door") : exit_list[size]);
      if (size>1) txt+=", ";
      if (size==1) txt+=" and ";
      if (!size) txt+=".\n";
    }
    write(lw(txt));

  }
    
}

string get_inv() {
  string txt, txt1,dir,des,desc;
  int size;
  txt=" ";
  size=sizeof(exit_list);
  while (size--) {
    dir=exit_list[size];
    if (!member(hidden,dir))
      if (!member(doors_list,dir) || 
	  (member(doors_list,dir)&& doors_list[dir][1]=="open") ) {
	desc=exits[dir]->query_short();
	if (dir=="up")
	  txt+="Above you, you see "+desc;
	else if (dir=="down")
	  txt+="Below you,  you see "+desc;
	else 
	  txt+="To the "+dir+" you see "+desc;
	txt1=exits[dir]->get_room_inv(0);
	if (txt1!="" && txt1) 
	  txt+=" and "+txt1+"\n";
	else
	  txt+="\n";
      }
  }
  return txt;
}

int examine_room(string arg) {
  string *str;
  if (!arg || !item_list) return 0;

  str=explode(arg," ");
  if (query_verb()=="look") {
    // Is the user looking at an item?
    if ( sizeof(str)==2 && str[0]=="at")
      if (member(items_list,str[1])) {
	write(lw(process_string(items_list[str[1]]+".\n")));
	return 1;
      }
    // Is the user looking in the direction of an exit?
    str[0]=query_expand_exits(str[0]);

    if(sizeof(str)==1 && member(exits,str[0])) {
      if ((query_door(str[0])!=2) && !member(hidden,str[0])) {
	exits[str[0]]->long("**!!**");
	return 1;
      } else {
	write("Your vision is blocked in that direction.\n");
	return 1;
      }
    }
    return 0;
  }

  // Ok... user is examining
  if (member(items_list,str[0])) {
    write(lw(process_string(items_list[str[0]]+".\n")));
    return 1;
  }
  return 0;
}

string plural_name(object ob,int num) {
  string t;
  if (ob->query_plural() && num>1)
    return ob->query_plural();
  if (t=ob->query_name())
    return t;
  if (t=ob->query_short())
    return t;
  if (t=ob->short())
    return t;
  return "object has a stupid return function";
}

string get_room_inv(int type) {
  mixed *obj_list;
  string txt;
  int loop,size,obj,i,liv;

  obj_list=filter_array(unique_array(all_inventory(this_object()),"short" ),"query_me");

  size=sizeof(obj_list);
  txt="";

  if (!type) {
    if (set_light(0)<=0)
      txt="it is dark.";
    while(size--) {
      i=sizeof(obj_list[size]);
      if (obj_list[size][0]->query_living())
	liv=1;
      else
	obj=1;
      if (liv || obj)
	txt="you see "+(liv ? " creatures moving." : "objects.");
    }
  } else {
    // get inventory list for the room
    while(size--) {
      txt+=query_numbers(sizeof(obj_list[size]))+" "+plural_name(obj_list[size][0], sizeof(obj_list[size]));
      if (size>1) txt+=", ";
      if (size==1) txt+=" and ";
      if (!size) txt+=".\n";
    }
    txt=capitalize(txt);    
  }
  return txt;
}

int query_me(object *obj) {
  if (obj[0]==this_player())
    return 0;
  return 1;
}

int id(string str) {
  if (!items) return 0;
  if (member(items_list,str))
    return 1;
  return 0;
}  

int move() {
  string str;
  str=query_verb();
  if (exits[str]) {
    if (query_door(str)==2) {
      write("You bang your head off the door!\n");
      return 1;
    }
    this_player()->move_player(str+"#"+exits[str]);
    return 1;
  }
  return 0;
}
    
int query_door(string str) {
  string *door;
  door=allocate(3);
  door=doors_list[str];
  if (!member(doors_list,str)) return 0;
  if (door[1]=="open") return 1;
  return 2;
}

string query_key(string str) {
  string *door;
  door=allocate(3);
  door=doors_list[str];
  if (!member(doors_list,str)) return 0;
  return door[2];
}

int door(string arg) {
  string args,cmd,*drs;  
  cmd=query_verb();
  drs=m_indices(doors_list);
  if (arg=="door")
    args=drs[0];
  else
    sscanf(arg,"%s door",args);

  if (!args) return 0;
  
  switch (cmd) {
  case "open":
    return move_door(args,0,1);
  case "close":
    return move_door(args,1,1);
  case "lock":
    return move_door(args,2,1); 
  case "unlock":
    return move_door(args,3,1);
  default:
    return 0;
  }
}

varargs int move_door(string dir,int type,int caller) {
  // type > 0 - open , 1 - closed.
  string *door,fname,dest;
  if (!member(doors_list,dir)) {
    write("No door in that direction!\n");
    return 1;
  }
  door=allocate(3);
  door=doors_list[dir];
  if (sizeof(door)==4)
    dest=door[4];
  else
    dest=dir_opposites(dir);

  if (door[1]=="closed" && !type) {
    if (door[0]=="locked") {
      write("The door is locked.\n");
      return 1;
    }
    doors_list[dir][1]="open";
    if (!caller) say("The door to the "+dir+" opens.\n",this_object());
    if (caller) {
      fname=exits[dir];
      fname->move_door(dest,0,0);
      fname->say("The door to the "+dir+" opens.\n");
      write("You open the "+dir+" door.\n");
    }
    return 1;
  }
  if (door[1]=="open" && type==1) {
    doors_list[dir][1]="closed";
    if (!caller) say("The door to the "+dir+" closes.\n",this_object());
    if (caller) {
      fname=exits[dir];
      fname->move_door(dest,1,0);
      fname->say("The door to the "+dir+" closes.\n",this_object());
      write("You close the "+dir+" door.\n");
    }
    return 1;
  }
  if (door[0]=="unlocked" && type==2) {
    if (!has_key(dir))
      return 1;
    doors_list[dir][0]="locked";
    if (!caller) say("You hear the "+dir+" door locking.\n",this_object());
    if (caller) {
      fname=exits[dir];
      fname->move_door(dest,2,0);
      fname->say("You hear the "+dir+" door locking.\n",this_object());
      write("You lock the "+dir+" door.\n");
    }
    return 1;
  }
  if (door[0]=="locked" && type==3) {
    if (!has_key(dir))
      return 1;
    doors_list[dir][0]="unlocked";
    if (!caller) say("You hear the "+dir+" unlocking.\n",this_object());
    if (caller) {
      fname=exits[dir];
      fname->move_door(dest,3,0);
      fname->say("You hear the "+dir+" door locking.\n",this_object());
      write("You unlock the "+dir+" door.\n");
    }
    return 1;
  }

  if (door[1]=="open" && !type) {
    write("The door is already opened!\n");
    return 1;
  }
  if (door[1]=="closed" && type==1) {
    write("The door is already closed!\n");
    return 1;
  }
  if (door[0]=="locked" && type==2) {
    write("The door is already locked!\n");
    return 1;
  }
  if (door[0]=="unlocked" && type==3) {
    write("The door is already unlocked!\n");
    return 1;
  }
  return 1;
}  

int has_key(string dir) {
  object *ob;
  string *door;
  int size;
  ob=all_inventory(this_player());

  size=sizeof(ob);
  if (!size) {
    write("You need a key.\n");
    return 0;
  }
  
  if (!member(doors_list,dir))
    return 0;
  door=allocate(4);
  door=doors_list[dir];

  if (door[2]=="none") {
    write("The door has no lock.\n");
    return 0;
  }
  while (size--) 
    if (ob[size]->query_key_id()==door[2])
      return 1;
  write("You don't have the right key.\n");
  return 0;
}

string resolve_path(string path) {
  string current_path;
  current_path=previous_object()->query_c_path();
  if (!path)
    path = "/" + current_path;
  if (path==".")
    path=clean_path(current_path+"/");
  if (path[0]=='/') 
    path=clean_path(path)[1..];
  else
    if (path[0]!='~')
      path=clean_path(current_path+"/"+path)[1..];
    else
      path=clean_path(path)[1..];
  path=clean_path(path);
  return path;
}

string clean_path(string path) {
  int i,noget;
  string *res,*hlp;

  if(!path) return "";
  if(path[0]=='~' && strlen(path)>3 && path[1]!='/' ) {
    path="/players/"+path[1..];
  }
  if (path[0]=='~' && strlen(path)<3 )
    path="/players/"+this_player()->query_real_name();
  if (path[0]=='~' && path[1]=='/' )
    path="/players/"+this_player()->query_real_name()+path[1..];

  if(path[0]!='/') path="/"+path;
  if(path=="/") return path;
  if(sizeof(explode(path,"..."))>1) return "";
  if(sizeof(explode(path,"//"))>1) return "";
  if(sizeof(explode(path," "))>1) return "";
  if(!(hlp=explode(path,"/"))) return "";
  res=allocate(0);
  for(i=sizeof(hlp)-1,noget=0;i>=0;i--)
    if(hlp[i]!=".") {
      if(hlp[i]=="..") noget++;
      else if(noget) noget--;
      else res=({ hlp[i] })+res;
    }
  if(noget) return ""; 
  path=implode(res,"/");
  if(path=="") return "/";
  else return path;
}


varargs string expand_dir(string s, int i)
{ return expand_dir[s] || ((contract_dir[s] || i) ? s : 0); }

varargs string contract_dir(string s, int i)
{ return contract_dir[s] || ((expand_dir[s] || i) ? s : 0); }

string query_numbers(int num) {
  string *numbers;
  numbers = ({"no", "one", "two", "three", "four", "five",
              "six", "seven", "eight", "nine" , "ten" , "many"});
  if (num<0)  return "error";
  if (num>10) num=10;
  return numbers[num];
}

string dir_opposites(string dir) {
  mapping d;
  d=([ "north" : "south",
       "northeast" : "southwest",
       "east" : "west",
       "southeast" : "nortwest",
       "south" : "north",
       "southwest" : "norteast",
       "west" : "east",
       "northwest" : "southeast",
       "up" : "down",
       "down" : "up"
       ]);
  return d[dir];
}

int test_darkness()
{
   if(this_player() && this_player()->infravision()) return 1;
   return set_light(0);
}

int test_dark()
{
   return set_light(0);
}

varargs mixed query_room(string arg, mixed param1) {
  switch (arg) {
  case "items" :          return items;
  case "items_list" :     return items_list;
  case "dest_dir" :       return dest_dir;
  case "short_desc" :     return short_desc;
  case "long_desc" :      return lw(long_desc);
  case "smell" :          return smell;
  default :               return sprintf("Sorry, %s is not defined", arg);
  }
}
