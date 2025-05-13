/*******************************************************
*   This is the south part of the mage-summonroom      *
*******************************************************/

#define P	"players/llort/guild/tower/"

inherit "room/room";
#include "summon.h"

int octagon;

reset(arg) {
  if(!arg) {
    short_desc="South of the Summon room";
    long_desc="This is the southern part of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling.\n";
    set_light(1);
    dest_dir=({ P+"summon5","north"
    	      ,P+"summon6","northeast"
	      ,P+"summon9","east"
	      ,P+"summon7","west"
	      ,P+"summon4","northwest"
	    });
    items=({ "engraving","","engravings","",
             "rune","","runes","",
             "wall","It is covered with runes",
             "floor","It is covered with runes",
             "ceiling","It is covered with runes", });
    enable_commands();
    }
}

init() {
  ::init();
  add_action("draw","draw");
  add_action("summon","yaczkl");
  if(octagon) call_out("dest_octa",1,this_player());
}

summon(arg) {
  string mon;
  object sum,obj,help,obj2;
  int i,ok;

  if(this_player()->query_spell_points()<150) {
    write("You are too low on energy.\n");
    return 1;
  }
  this_player()->restore_spell_points(-100);
  if(sscanf(arg,"hruk dan %s",mon)!=1) {
    write("The spell fizzels as you misspell the magic words.\n");
    return 1;
  }
  if(!test_oct()) {
    write("The spell fizzels due a lack of protection.\n");
    return 1;
  }
  obj=find_object(P+"summon5");
  if(!obj) {
    write("The spell fizzels due a lack of material.\n");
    return 1;
  }
  sum=find_living(mon);
  if(sum && sizeof(explode(file_name(sum),"#"))!=2) {
    destruct(sum);
    sum=find_living(mon);
  }
  if(!sum || sizeof(explode(file_name(sum),"#"))!=2) {
    write("You couldn't find "+mon+".\n");
    return 1;
  }
  if(sum->query_no_summon()) {
    write(capitalize(mon)+" doesn't want to come.\n");
    return 1;
  }
  if(this_player()->query_spell_points()<4*sum->query_level()) {
    write("You are too low on energy.\n");
    return 1;
  }
  if(query_ip_number(sum)) {
    write("You are not allowed to summon players.\n");
    return 1;
  }
  if(random(100)>(this_player()->query_level()+this_player()->query_wis())*3 /
         (this_player()->query_guild()!=5 ? 3 : 1)-sum->query_level()) {
    write("The spell fizzels due a lack of knowledge.\n");
    return 1;
  }
  obj=all_inventory(obj);
  for(i=0;i<sizeof(obj);i++) {
    if(living(obj[i])) {
      write("The spell fizzles due a living interfering with its power.\n");
      return 1;
    }
    if(obj[i]->query_value()>sum->query_level()*10) ok=i+1;
  }
  if(!ok) {
    write("The spell fizzels due a lack of material.\n");
    return 1;
  }
  tell_room(this_object(),"You hear some cracking in the air.\n"+
       "The "+obj[ok-1]->short()+" crubles to dust. And suddenly:\n");
  catch_tell("You hear some cracking in the air.\n"+
       "The "+obj[ok-1]->short()+" crubles to dust. And suddenly:\n");
  destruct(obj[ok-1]);
  help=environment(sum); 
  sum->move_player("X#"+P+"summon5");
  obj=clone_object("/players/llort/guild/obj/summon_ctl");
  move_object(obj,sum);
  if(random(150) < 150-this_player()->query_level()-
                       this_player()->query_chr()-
                      (this_player()->query_guild()!=5 ? 0 : 
                         this_player()->query_wis())) {
         obj->init_me(this_player(),1,sum->query_aggressive(),file_name(help));
         sum->set_aggressive(1);
         sum->attacked_by(this_player());
         tell_room(this_object(),"The monster groans loud as it recovers "+
             "the shock.\n");
         catch_tell("The monster groans loud as it recovers the shock.\n");
         
  } else {
         obj->init_me(this_player(),0,sum->query_aggressive(),file_name(help));
         sum->set_aggressive(0);
         tell_room(this_object(),"The monster looks puzzled in all "+
             "directions.\n");
         catch_tell("The monster looks puzzled in all directions.\n");
         obj2=clone_object("/players/llort/guild/obj/commander");
         move_object(obj2,this_player());
         obj2->init_me(sum,obj);
  }

  this_player()->restore_spell_points(-4*sum->query_level());

  return 1;
}
  
   

dest_octa(tp) {
  if(octagon) {
    tell_object(tp,"As you enter this part of the room, you destroy the"+
          " protection\nrunes drawn on the floor.\n");
    say(tp->query_name()+" destroys the protection runes on the floor.\n",tp);
    catch_tell(tp->query_name()+" destroys the protection runes "+
          "at the south of the room.\n");
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
  tell_room(P+"summon2",arg);
  tell_room(P+"summon3",arg);
  tell_room(P+"summon4",arg);
  tell_room(P+"summon5",arg);
  tell_room(P+"summon6",arg);
  tell_room(P+"summon7",arg);
  tell_room(P+"summon1",arg);
  tell_room(P+"summon9",arg);
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

  if(tmp=get_inv_list(P+"summon1")) {
    write("At the northwest corner you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon2")) {
    write("At the northwall you see: ");
    write(tmp); fl=1;
  } 
  if(tmp=get_inv_list(P+"summon3")) {
    write("At the northeast corner you see: ");
    write(tmp);  fl=1;
  } 
  if(tmp=get_inv_list(P+"summon4")) {
    write("At the westwall you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon5")) {
    write("At the center you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon6")) {
    write("At the eastwall you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon7")) {
    write("At the southwest corner you see: ");
    write(tmp);  fl=1;
  }
  if(tmp=get_inv_list(P+"summon9")) {
    write("At the southeast corner you see: ");
    write(tmp);  fl=1;
  }
  if(fl && get_inv_list(P+"summon8")) write("And here is : ");
}  
  
