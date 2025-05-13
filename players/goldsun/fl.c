/* Some hot burning flames ... */

#define	TP	this_player()
#define ROOM    "/players/goldsun/lank/room"
#define TO	this_object()
#define	TPN	TP->query_name()
#define env	environment

inherit "obj/thing";
object kill_ob;
int hp,i,r;
string KON,KOPOS;
string msg1,msg2;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("hot burning flames");
  set_alias("flames");
  set_short("Hot burning flames");
  set_long("Flames burn your hair, your hands, your feet, your whole body !!!\n");
  }

end_fire(){
 kill_ob->move_player("out#/room/church");
 destruct(this_object());
 return 1;
 }

burn(ob) {
  kill_ob=ob;
  KON=ob->query_name();
  KOPOS=ob->query_possessive();
  do_burn();
  }

do_burn() {
/* object *all; */
int is_fire;

 if  (!kill_ob || kill_ob->query_ghost()) {
    if(find_call_out("do_burn")!=-1) {
        remove_call_out("do_burn");
	kill_ob->move_player("out#/players/goldsun/workroom");
        destruct(TO);
    }  
/*
    all=all_inventory(env(this_object()));
    if(all) {
      for(i=0;i<sizeof(all);i++) {
        if(!living(all[i])) destruct(all[i]);
        }
      tell_room(ROOM+"/cottage","The items burn away in the hot flame.\n");
    }
       */

    return;
    }
 is_fire="/players/goldsun/cottage"->query_fire();
 if ((is_fire) && (!kill_ob->query_ghost())){
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
    tell_room("/players/goldsun/cottage",msg2);
   }  



/*
  hp=kill_ob->query_hp()/(1+random(2))+kill_ob->dodge_bon()+1;
*/
  hp=kill_ob->query_hp()/(1+random(2))+kill_ob->query_dex()/12 + 1;
  hp=25;
  kill_ob->hit_player(hp);
  }
 if (kill_ob->query_ghost()) write("si duch\n\n\n");
 if (!is_fire){ end_fire(); return 1;}
 call_out("do_burn",2);
 return 1;
}


