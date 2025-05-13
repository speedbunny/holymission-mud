#define ST "players/llort/guild/tower/store_room"
#define SH "players/llort/guild/tower/magic_shop"
#define MAX_LIST 20
#define ENV environment()

inherit "/obj/monster.c";
#include "/obj/monsoul.c" 

object last;
string last_n;
string msg;

reset(arg) {
object ob;

  ::reset(arg);

  if(!arg) {
    set_name("wuntvor");
    set_alias("man");
    set_short("An old robed man");
    set_long("Wuntvor the old, Archmage of the inner circle.\n");
    set_race("human");
    set_gender(1);
    set_level(95);
/*    set_spell_mess2("Wuntvor shoots a bolt of fire using his staff");
    set_spell_mess1("Wuntvor shoots a bolt of fire using his staff");
    set_chance(100);
    set_spell_dam(80); 
*/
    set_language_skill(0,100);
    set_language_skill(2,100);
    set_speaks_in(0);

    change_spell( "meteor swarm", 95, 95, 2 );
    change_spell( "fireball", 95, 95, 2 );
    change_spell( "lightning bolt", 95, 95, 1 );
    change_spell( "magic missile", 95, 95, 0 );
    change_spell( "chainlightning", 95, 95, 2 );
    change_spell( "fear", 95, 95, 1 );

    ob=clone_object("/obj/shadows/fireshield_shad");
    ob->start_shadow(this_object(),0,2);
    ob=clone_object("/obj/shadows/true_sight_shad");
    ob->start_shadow(this_object(),0);
    "/players/llort/castle"->abc();
    ob=present("visor",find_object("/players/llort/castle"));
    if(ob)
    {
       move_object(ob,this_object());
       init_command("wear visor");
    };
    ob=clone_object("/players/llort/animals_stuff/phylactery");
    move_object(ob,this_object());
    init_command("wear phylactery");
  }
  sreset(arg);
}

init() {
  ::init();
  if(this_player()->id("wuntvor")) return;
  if(environment()==find_object(ST)) {
    add_action("south","south");
  } else if(environment()==find_object(SH)) {
    add_action("north","north");
  }
}

north() {
  if(environment()!=find_object(SH)) return;
  if(!this_player()->short()) return;
  write("Wuntvor blocks your way.\n");
  tell_room(ENV,"Wuntvor says: You are not allowed to enter the storeroom youngster.\n");
  return 1;
}

south() {
  object *dir;
  int i;
  if(!(dir=deep_inventory(this_player()))) return;
  for(i=0;i<sizeof(dir);i++) {
      if(dir[i]->id("chalk")) break;
      else if(dir[i]->id("ring of following")) break;
      else if(dir[i]->id("aladin's lamp")) break;
      else if(dir[i]->id("judger")) break;
      else if(dir[i]->id("black diamond")) break;
      else if(dir[i]->id("magic ball")) break;
      else if(dir[i]->id("catseye")) break;
  }
  if(i<sizeof(dir)) {
      write("Wuntvor blocks your way.\n");
      tell_room(ENV,"Wuntvor says: You won't escape you lousy thief.\n");
      return 1;
  }
}

catch_tell(arg) {
  string who,what,item,hlp,old;

#if 0
  tell_object(find_player("llort"),"WUNTI: >"+arg+"<\n");
#endif
  msg=""; 
  if(!arg || environment()!=find_object(SH)) return;
  if(sscanf(arg,"%s says: %s\n",who,what)!=2) return;
  who=lower_case(who);
  if(sscanf(what,"buy%s",item)==1 ||
     sscanf(what,"sell me%s",item)==1 ||
     sscanf(what,"give me%s",item)==1 ||
     sscanf(what,"bring me%s",item)==1 ||
     sscanf(what,"%s buy%s",hlp,item)==2 ||
     sscanf(what,"%s sell me%s",hlp,item)==2 ||
     sscanf(what,"%s give me%s",hlp,item)==2 ||
     sscanf(what,"%s bring me%s",hlp,item)==2 ) {
    if(item=="") {
      msg+=("Wuntvor says: What do you want to buy?\n");
      list();
      return;
    }
    if(!ST->got(item)) {
      old=item;
      if(sscanf(item,"%s ball",hlp)==1) item="ball";
      else if(sscanf(item,"%s chalk",hlp)==1) item="chalk";
      else if(sscanf(item,"%s lamp",hlp)==1) item="lamp";
      else if(sscanf(item,"%s diamond",hlp)==1) item="diamond";
      else if(sscanf(item,"%s judge",hlp)==1) item="judge";
      else if(sscanf(item,"%s eye",hlp)==1) item="eye";
      else if(sscanf(item,"%s ring",hlp)==1) item="ring";
    }
    if(!ST->got(item)) {
      msg+=("Wuntvor says: Sorry, we haven't got "+old+".\n");
      list();
      return;
    }
    if(!present(who,environment())) {
      msg+=("Wuntvor says: Who did say that?\n");
      write(who+"\n");
      call_out("delay_say",0);
      return;
    }
    call_out("buy",0,item);
  } else if(sizeof(explode(what," buy "))==2 ||
            sizeof(explode(what," sell "))==2) {
    list();
  }
}

list() {
  msg+=("Wuntvor says: I've got the following items for sale:\n"+
      "              ring .. in fact that are rings of following,\n"+
      "              diamond .. some strange magic diamonds,\n"+
      "              lamp .. certain magic lamps,\n");
  msg+=("              chalk .. magic chalk of binding,\n"+
      "              judge .. mystic devices to get information about someone,\n");
  msg+=("              eye .. usefull magic locate devices and\n"+
      "              ball .. funny magic balls.\n"+
      "Wuntvor says: Do you want to 'buy' something from this?\n");
  call_out("delay_say",0);
}  

delay_say() { 
  string *list;
  int i;
  if(!msg || msg=="") return;
  list=explode(msg,"\n"); 
  for(i=0;i<sizeof(list);i++) tell_room(environment(),list[i]+"\n");
  msg=""; 
}

buy(what) {
  tell_room(ENV,msg);
  command("north",this_object());
  call_out("buy2",1,what);
}

buy2(what) {
  command("get "+what,this_object());
  call_out("buy3",1,what);
}

buy3(what) {
  command("south",this_object());
  if(last=present(what,this_object())) {
    if(environment()==find_object("players/llort/guild/tower/magic_shop")) 
     tell_room(ENV,"Wuntvor says: Here we are. This makes "+last->query_value()*2+
          " gold coins.\n");
    last_n=what;
  } else {
    last=last_n=0;
    tell_room(ENV,"Wuntvor says: Sorry, we're out of "+what+"s. Please try later again.\n");
  }
}

add_money(x) {
  ::add_money(x);
  if(!last) {
    tell_room(ENV,"Wuntvor says: I don't want your money for nothing.\n");
    command("give "+x+" coins to "+this_player()->query_real_name(),
            this_object());
  } else {
    if(x<last->query_value()*2) {
      tell_room(ENV,"Wuntvor says: That's not enough.\n");
      command("give "+x+" coins to "+this_player()->query_real_name(),
              this_object());
    } else if(x>last->query_value()*2) {
      tell_room(ENV,"Wuntvor says: Thanks for the tip.\n");
      tell_room(ENV,"Wuntvor smiles at "+capitalize(this_player()->query_name())+".\n");
      command("give "+last_n+" to "+this_player()->query_real_name(),
              this_object());
      last=0;
    } else {
      command("give "+last_n+" to "+this_player()->query_real_name(),
              this_object());
      last=0;
    }
  }
  ::add_money(-this_object()->query_money());
}

query_no_summon() { return 1; }

save_me() { return; }

no_clean_up() { return 1; }

int concentrate( object vic )
{
   int rnd;

   if ( vic && !query_concentrating() ) {
      rnd = random( 100 );
      if ( rnd < 5 )
         npc_process_spell( "meteor swarm", vic );
      else if ( rnd < 25 )
         npc_process_spell( "fireball", vic );
      else if ( rnd < 50 )
         npc_process_spell( "magic missile", vic );
      else if ( rnd < 75 )
         npc_process_spell( "lightning bolt", vic );
      else if ( rnd < 95 )
         npc_process_spell( "chainlightning", vic );
      else
         npc_process_spell( "fear", vic );
   }

   return( 1 );
}
