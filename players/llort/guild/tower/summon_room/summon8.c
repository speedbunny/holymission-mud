/*******************************************************
*   This is the south part of the mage-summonroom      *
*******************************************************/

#include "summon.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="South of the Summon room";
    long_desc="This is the southern part of the summon room.\n"+
              "You can see many engravings in the walls, in the\n"+
              "floor and on the ceiling.\n";
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
    }
}

init() {
  ::init();
  add_action("summon","yaczkl");
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
