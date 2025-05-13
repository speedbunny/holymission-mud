inherit "room/room";

#define P	"players/llort/guild/tower/summon_room/"
#define INVLIST invlist()
#define ROOM_LOC ({ "",\
    "northwest corner","northwall","northeast corner","westwall","center",\
    "eastwall", "southwest corner", "southwall", "southeast corner" })

int octagon;
string my_fname;

invlist() { 
  int i; object *dir;
  dir=all_inventory(environment(this_player()));
  for(i=0;i<sizeof(dir);i++)
    if(dir[i]->short() && dir[i]!=this_player()) 
      write(capitalize(dir[i]->short()+"\n"));
}


reset(arg) {
    if(!arg)
    {
        set_light(1);
        enable_commands();
        my_fname=file_name(this_object());
    }
}

init() {
  ::init();
  add_action("draw","draw");
  call_out("dest_octa",1,this_player());
}

dest_octa(tp) {
  if(octagon) {
    tell_object(tp,"As you enter this part of the room, you destroy the"+
          " protection\nrunes drawn on the floor.\n");
    say(tp->query_name()+" destroys the protection runes on the floor.\n",tp);
    catch_tell(tp->query_name()+" destroys the protection runes "+
          "at the northwest corner of the room.\n");
    octagon=0;
  }
} 

draw(arg) {
  object ch;
  if(arg!="octagon") return;
  if(!(ch=present("chalk",this_player()))) {
    write("You can't draw anything without chalk.\n");
    return 1;
  } else ch->reduce();
  if(octagon) {
    write("You redraw this part of the octagon.\n");
  } else {
    write("You draw part of the runes, to bind a monster, on the floor.\n");
    octagon=1;
  }
  say(this_player()->query_name()+" draws something on the floor.\n",
      this_player());
  return 1;
}

catch_tell(arg) {
  int i;
  string fname;

  for(i=1;i<10;i++)
  {
     fname=sprintf("%ssummon%d",P,i);
     if(fname != my_fname)
     {
        tell_room(fname,arg);
     }
  }
}

move(arg) {
  int i;
  if((i=member_array(query_verb(),dest_dir))==-1) return 1;
  if(this_player()->short())
    catch_tell(this_player()->query_name()+" moves "+ 
           dest_dir[i]+".\n");
  move_object(this_player(),dest_dir[i-1]);
  if(this_player()->short())
    tell_room(this_object(),this_player()->query_name()+" moves "+ 
           dest_dir[i]+".\n");
  environment(this_player())->long();
  INVLIST; 
  return 1;
}

get_inv_list(room) {
  object ob;
  string tmp;
  int i;

  tmp="";
  if(!(ob=find_object(room))) return 0;
  ob=all_inventory(ob);
  for(i=0;i<sizeof(ob);i++) if(ob[i]->short() && ob[i]!=this_player())
    tmp+=capitalize(ob[i]->short())+"\n";
  return tmp=="" ? 0 : tmp;
}

test_oct() {
  return(call_other(P+"summon1","query_oct") &&
     call_other(P+"summon2","query_oct") &&
     call_other(P+"summon3","query_oct") &&
     call_other(P+"summon4","query_oct") &&
     call_other(P+"summon6","query_oct") &&
     call_other(P+"summon7","query_oct") &&
     call_other(P+"summon8","query_oct") &&
     call_other(P+"summon9","query_oct") );
}

query_oct() { return octagon; } 

set_oct(a) { octagon=a; }

long(a) {
  string tmp;
  int fl,i;

  if(a) {
    switch(a) {
      case "engravings": 
      case "engraving": 
      case "rune":
      case "runes":
        i=member_array(a,items);
        if(i!=-1) items[i+1]= this_player()->query_guild() == 5 ?
          "Some powerful runes to help prison the summoned monsters" :
          "Some strange magical runes";
        break;
    }
    return ::long(a);
  }
  
  fl=0;
  tmp=long_desc;
  if(test_oct()) {
    long_desc+="There is a big protection octagon drawn around the center "+
               "of the room.\n";
  } else if(octagon) 
    long_desc+="You notice part of a protection octagram on the floor.\n";
  ::long(a);
  long_desc=tmp;

  for(i=1;i<10;i++)
  {
      tmp = sprintf("%ssummon%d",P,i);
      if(tmp != my_fname)
      {
          if(tmp=get_inv_list(tmp))
          {
               write("At the "+ROOM_LOC[i]+" you see: "+tmp);
               fl=1;
          } 
      }
      else
      {
          if(fl && get_inv_list(my_fname))
              write("And here is : ");
      }
  }
}  
  
