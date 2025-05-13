#define TP  this_player()
#define ROOM "/players/whisky/garden/room"
#define TO  this_object()
#define TPN TP->query_name()
#define env environment

object e,kill_ob;

int hp,i,r;
int or;

string KON,KOPOS;
string msg1,msg2;

void reset(int arg);

string query_name()
  {return "flames";}

string short()
  {return "Hot burning flames";}

string alias()
  {return "burning flames";}

string query_pronoun()
  {return "they";}

int query_npc()
  {return 1;}

int id(string str) 
  {return str=="flames";}

void long()
  {write("Flames burn your hair, your hands, your feet, your whole body !!!\n");}

void init() 
  {enable_commands();}

void burn_player(object ob)
  {if(ob->query_wizard() && ob->query_invis())
    {destruct(this_object());
    return;}
  kill_ob=ob;
  KON=ob->query_name();
  KOPOS=ob->query_possessive();
  ob->attack_object(TO);
  set_heart_beat(1);}

void heart_beat()
  {if(!kill_ob || kill_ob->query_ghost() || env(kill_ob)!=env(TO))
    {destruct(TO);
    return;}
  r=random(5)+1;
  for(i=0;i<r;i++)
    {msg1="";
    msg2="";
    switch(random(5))
      {case 0: msg1+="Flames lick up from your shoes to your hair !";
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
        break;}
    msg1+="\n";
    msg2+="\n";
    tell_object(kill_ob,msg1);
    tell_room("room/church",msg2);}
  hp=kill_ob->query_hp()/(1+random(2));
  if (hp<100)
    hp=random(kill_ob->query_hit_point()*2);
  kill_ob->misc_hit(hp,0,0);
  if (++or==3 && !kill_ob->query_ghost())
    {tell_object(kill_ob,"\n\nFinally, by the mercy of the gods, you are released!\n\n");
    kill_ob->set_alignment("burning");
    move_object(kill_ob,"room/church");
    say(KON+" arrives, coughing and smoking, still burning a bit !\n",kill_ob);
    command("look",kill_ob);
    destruct(this_object());
    return;}}

void add_exp(int i)
  {string name;
  object *ob,th;
  ob=all_inventory(kill_ob);
  for (i=0;i<sizeof(ob);i++)
    if(!random(3)&&(name=ob[i]->query_name())&&!ob[i]->drop())
      {th=clone_object("obj/thing");
      th->set_name(name);
      th->set_short(ob[i]->short()+" (burning)");
      th->set_weight(1);
      th->set_value(40);
      th->set_can_get(1);
      move_object(th,"players/kawai/workroom");
      destruct(ob[i]);}}
