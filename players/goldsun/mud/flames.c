/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */
/* Some hot burning flames ... */
/* Recoded by Uglymouth 930901: removed enable_commands() and heart_beat(),
   inherits /obj/thing.c now, bug (dead 1, ghost 0) solved now */
/* 12-05-93 Mangla: recoded do_burn call_out/destruct and hp damage */

#define	TP	this_player()
#define ROOM    "/players/whisky/garden/room"
#define TO	this_object()
#define	TPN	TP->query_name()
#define env	environment

inherit "obj/thing";
object kill_ob;
int hp,i,r;
int count;
string KON,KOPOS;
string msg1,msg2;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("hot burning flames");
  set_alias("flames");
  set_short("Hot burning flames");
  set_long("Flames burn your hair, your hands, your feet, your whole body !!!\n");
  set_can_get(0);
  count = 0;
  }

burn_player(ob) {
  if (ob->query_wizard() && ob->query_invis()) {
    destruct(this_object());
    return;
    }
  kill_ob=ob;
  KON=ob->query_name();
  KOPOS=ob->query_possessive();
  call_out("do_burn",3);
  }

do_burn() {
object *all;
  if (!kill_ob || kill_ob->query_ghost() || env(kill_ob)!=env(TO)) {
/* 12-05-93 Mangla removed.
    if(find_call_out("do_burn")!=-1) remove_call_out("do_burn");
*/
    if(find_call_out("do_burn")!=-1) {
        remove_call_out("do_burn");
        destruct(TO);
    }
    all=all_inventory(env(this_object()));
    if(all) {
      for(i=0;i<sizeof(all);i++) {
        if(!living(all[i])) destruct(all[i]);
        }
      tell_room(ROOM+"/oven","The items burn away in the hot flame.\n");
      }
/* 12-05-93 Mangla removed.
    destruct(TO);
*/
    return;
    }

  r=random(5)+1;
  for(i=0;i<r;i++) {
    msg1="";
    msg2="";
    switch(random(5)) {
      case 0: msg1+="Flames lick up from your shoes to your hair !";
     	      msg2+="Flames lick up from "+KON+"'s shoes to "+KOPOS+" hairs !";
	      break;
      case 1: msg1+="The heat of the oven takes your breath away !";
	      msg2+=KON+" desperately tries to breath, but\n"
		+ "only smoke gets in "+KOPOS+" nostrils !"; 
	      break;
      case 2: msg1+="You feel like Satan has come to visit you !";
 	      msg2+="Satan has come to visit "+KON+" !";
	      break;
      case 3: msg1+="You feel your left eyeball burst as a flame "
		+"burns your head !";
	      msg2+=KON+" screems with horror as "+KOPOS+" left eyeball "
		+"burst\nlike a toad being blown up !";
	      break;
      case 4: msg1+="Blisters grow from your back as the flames shift\n"
		+"slowly from your back to your toes !";
	      msg2+="Blisters grow from "+KON+"'s back as the flames\n"
		+"shift slowly from "+KOPOS+" back to "+KOPOS+" toes !";
	      break;
      }
    msg1+="\n";
    msg2+="\n";
    tell_object(kill_ob,msg1);
    tell_room(ROOM+"/house2",msg2);
    }
/* 12-05-93 Mangla modified.
  hp=kill_ob->query_hp()/(1+random(2))+kill_ob->dodge_bon()+1;
*/
  hp=kill_ob->query_hp()/(1+random(2))+kill_ob->query_dex()/12 + 1;
  kill_ob->hit_player(hp);
  count++;
  if (count==3 && !kill_ob->query_ghost()) {   
    tell_object(kill_ob,"\n\nYou struggle and struggle, and finally escape "
		+"from the oven !\n\n");
    kill_ob->set_alignment("burning");
    move_object(kill_ob,ROOM+"/house2");
    say(KON+" arrives, coughing and smoking, still burning a bit !\n",kill_ob);
    command("look",kill_ob);
    all=all_inventory(env(this_object()));
    if(all) {
      for(i=0;i<sizeof(all);i++) {
        if(!living(all[i]) && all[i]!=this_object()) destruct(all[i]);
        }
      tell_room(ROOM+"/oven","The items burn away in the hot flame.\n");
      }
    destruct(this_object());
    return;
    } 
  call_out("do_burn",3);
  return;
  }

/* Doesn't work anymore and shouldn't work this way anyway. I let the 
   items that are left in the oven burn away. Uglymouth 930901 */
add_exp(i) {
string name;
object *ob,th;
  
  ob=all_inventory(kill_ob);
  for (i=0;i<sizeof(ob);i++)
    if (!random(3) && (name=ob[i]->query_name()) && !ob[i]->drop()) {
	th=clone_object("obj/thing");
	th->set_name(name);
	th->set_short(ob[i]->short()+" (burning)");
	th->set_weight(1);
        th->set_value(40);
	th->set_can_get(1);
	move_object(th,ROOM+"/house2");
	destruct(ob[i]);
    }
  }
