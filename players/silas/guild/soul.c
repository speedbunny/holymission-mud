 
 
/* The following actions are valid for a druid:                */
/*                                                             */
/*    druid:                    Hilfefunktion
        quo vadis:              Teleportation zur Guild
        verify -item-           Abfragen der Weapon_class
        conjure:                Verschiedene Hit-Spells
        adopt  <player>         Adoptieren einer Person
        stop:                   Loesen der Verbindung
        kidnap <object>         Kidnappen eines Lebewesens
        bind wounds             Umlagern von Sps in Hps
        meditate                Umlagern von Hps in Sps
        mist                    Verschwinden in einer Wolke
        teleport <item> to <player>  Teleportieren von Dingen
        druid                        Druidensender
*/
 
#define TP   this_player()
#define TPN  TP->query_name()
#define TPR  TP->query_real_name()
#define TPL  TP->query_level()
#define TPW  TP->query_wis()
#define TPC  TP->query_chr()
#define TPS  TP->query_str()
#define env  environment
#define TIME_TO_ADOPT 300
#define TIME_TO_KIDNAP 60
#define GM "guild/master"
#define GUILD "druid"
#define ALIGN -300
 
string adopted;
object kidnap;
int    reduce;
int    guild;
int    quo_chance,quo_cost;
int    verify_chance,verify_cost;
int    conjure_thor_chance,conjure_thor_cost;
int    conjure_odin_chance,conjure_odin_cost;
int    conjure_frija_chance,conjure_frija_cost;
int    conjure_baldur_chance,conjure_baldur_cost;
int    adopt_chance,adopt_cost;
int    kidnap_chance,kidnap_cost;
int    bind_chance,bind_cost;
int    meditate_chance,meditate_cost;
int    mist_chance,mist_cost;
int    teleport_chance,teleport_cost;
 
id(str) { return str == "druidsoul" || str== "guildsoul";}
 
drop() { return 1; }    /* don't drop */
get()  { return 1; }
 
reset(arg) {
  if(arg) return;
  guild = GM ->query_number(GUILD);
}
 
init() {
     set_var();
     add_action("help","help");
     add_action("go_guild","quo");
     add_action("con_on","verify");
     add_action("conjure","conjure");
     add_action("adopt","adopt");
     add_action("stop_adoption","stop");
     add_action("kidnap","kidnap");
     add_action("bind","bind");
     add_action("meditate","meditate");
     add_action("mist","mist");
     add_action("teleport","teleport");
     add_action("druid","druid");
     enable_commands();
}
 
long() {
   cat("/players/silas/guild/long.tex");
   return 1;
}
 
go_guild(str) {
 
   object ob;
 
   if (str == "vadis") {
     if (!check_alignment()) return 1;
 
     if (env(TP)->query_mist())
      {
        write("This spell doesn't work inside a mist of safety.\n");
        return 1;
     }
 
     ob = first_inventory(TP);
     while (ob) {
       if (ob->query_food()) {
        write("Your drinks prevent your teleportation.\n");
        return 1;
       }
       ob =next_inventory(ob);
     }
 
     if (!check_sp(quo_cost)) return 1;
 
     if (spell_works(quo_chance)) {
       say(TPN + " fades away.\n");
       write("You are magically transferred to your guild.\n");
       move_object(TP,"/players/silas/guild/guild");
       reduce_sp(quo_cost);
     }
     return 1;
   }
}
 
help(str) {
     string help_file;
   if (!check_alignment()) return 1;
   if (str == "guild") {
      cat("/players/silas/guild/help.tex");
      return 1;
   }
   if (str == "levels") {
     list_levels();
     return 1;
   }
   if (str == "spell") {
       list_spells();
       return 1;
   }
 
help_file = "/players/silas/guild/help"+str+".tex";
if (file_size(help_file)>0)
{
   cat("/players/silas/guild/help"+str+".tex");
return 1;
}
else 
return 0;

return 1;
}
 
con_on(str) {
 
  int wc;
 
  reduce = verify_cost;
 
  if (!check_alignment()) return 1;
 
  if (!check_sp(reduce)) return 1;
 
  if (TPL < 10) {
    write ("Your level is too low; gain more experience first young druid.\n");
    return 1;
  }
  if (TPW < 10) {
    write ("You are too inexperienced to use this command.\n");
    return 1;
  }
  if (!str) {
     write ("What do you want to verify?\n");
     return 1;
  }
  if (!present(str,TP)) {
    write ("You don't have this.\n");
    return 1;
  }
 
  if (spell_works(verify_chance))
  {
    reduce_sp(reduce);
 
    wc = (present(str,TP)->weapon_class());
 
    if (!wc) {
       write("This item is no weapon.\n");
       return 1;
    }
    if (wc<5)
      write("Using your hands might be a better idea.\n");
    else
    if (wc<10)
      write("It's better than fighting with your hands.\n");
    else
    if (wc<15)
      write("A good weapon for a good guy.\n");
    else
    if (wc<20)
      write("An excellent weapon.\n");
    else
      write("One of the best weapons that you can get.\n");
    return 1;
  }
  return 1;
}
 
conjure(str) {
  if (!check_alignment()) return 1;
 
  if (!str) {
    write("Who do you want to conjure?\n");
    return 1;
  }
  if (!TP->query_attack()) {
    write("You are not attacking anybody.\n");
    return 1;
  }
 
  switch(str) {
    case "thor":
      if ((TPL >= 15) && (TP->query_chr()>=12)) {
        if (!check_sp(conjure_thor_cost)) return 1;
 
        if (!spell_works(conjure_thor_chance)) return 1;
 
        write("Thor summons a big firebolt from the sky.\n");
        say("As "+ TPN + " conjures up Thor "+ TP->query_possessive()+
               " opponent is hit by a violent firebolt.\n");
 
        TP->query_attack()->hit_player(100+random(60));
        reduce_sp(conjure_thor_cost);
      }
      else
        write("Your magic isn't powerful enough yet.\n");
 
      break;
    case "odin":
      if ((TPL >=12) && (TP->query_chr()>=10)) {
        if (!check_sp(conjure_odin_cost)) return 1;
 
        if (!spell_works(conjure_odin_chance)) return 1;
 
        TP->query_attack()->hit_player(100+random(20));
 
        write("Listening to you Odin sends a violent flash towards your opponent.\n");
        say("Odin the Master of Thunder supports his servant "+ TPR + " and\n" +
               "summons a big flash from the sky.\n");
 
        reduce_sp(conjure_odin_cost);
      }
      else
        write("Odin the Master of Thunder doesn't want to listen to\n"+
                  "such an inexperienced druid.\n");
 
      break;
 
    case "frija":
        if (!check_sp(conjure_frija_cost)) return 1;
 
        if (!spell_works(conjure_frija_chance)) return 1;
 
        TP->query_attack()->hit_player(40+random(20));
 
        write("As you pray to Frija your opponent seems to be confused and hits himself.\n");
        say("Frija supports his servant "+TPR+".\n");
 
        reduce_sp(conjure_frija_cost);
      break;
 
    case "baldur":
        if (!check_sp(conjure_baldur_cost)) return 1;
 
        if (!spell_works(conjure_baldur_chance)) return 1;
 
        TP->query_attack()->hit_player(random(20));
 
 
        write("You are not alone anymore. Baldur fights with you.\n");
        say("Baldur is here.\n");
 
        reduce_sp(conjure_baldur_cost);
      break;
 
    default:
  }
  return 1;
}
druid(str) {
  string msg;
  object *u;
  int i;
  u = users();
  if(str) {
    for(i=0;i<sizeof(u);i++)
      if(u[i]->query_guild()==guild)
        tell_object(u[i],"<*"+TPN+"*> "+str+".\n");
        tell_object(TP,"Ok.\n");
        return 1;

     }
    msg = "Druids currently wandering within the Holy Mission:\n";
    for(i=0;i<sizeof(u);i++)
    if(u[i]->query_guild()==guild)
      if(!u[i]->query_invis()) {
      msg+=u[i]->query_name()+"\n";
      }
    write(msg);
    return 1;
}
 
adopt(str) {
 
   object adopt_ob,ob;
 
   reduce = adopt_cost;
 
   if (!check_alignment()) return 1;
 
   if (!check_sp(reduce)) return 1;
 
   if (!str) {
     write("Who do you want to adopt?\n");
     return 1;
   }
   if (capitalize(TPR) == capitalize(str)) {
     write("You can't adopt yourself.\n");
     return 1;
   }
 
   if (adopted) {
     write("You can only adopt one person.\n");
     return 1;
   }
   if (present(str,env(TP))->query_npc()) {
      write("You can only adopt players.\n");
      return 1;
   }
 
   if (!present(str,env(TP))) {
     write(capitalize(str) + " isn't here.\n");
     return 1;
   }
   if (TPL < present(str,env(TP))->query_level())
      write("You are too inexperienced to adopt this person.\n");
   else
   {
     if (!spell_works(adopt_chance)) return 1;
 
     reduce_sp(reduce);
     adopted = present(str,env(TP));
     call_out("stop_adoption",TIME_TO_ADOPT);
     write("You adopt "+ capitalize(str) +"\n");
     tell_object(adopted,"You are adopted by "+
                         TPN +"\n");
     adopt_ob = clone_object("/players/silas/guild/adopt");
     move_object(adopt_ob,present(str,env(TP)));
     ob = present("adopt_slave",find_player(str));
     ob -> query_master(TP);
   }
   return 1;
}
 
kidnap(str) {
 
  object ob;
 
  reduce = kidnap_cost;
 
  if(!check_alignment()) return 1;
 
  if (!check_sp(reduce)) return 1;
 
  if(!str) {
    write("Who do you want to kidnap?\n");
    return 1;
  }
 
  if (!present(str,env(TP))) {
     write(capitalize(str) + " isn't here. Take a better look next time.\n");
     return 1;
  }
 
  if (!living(present(str,env(TP)))) {
    write(capitalize(str) +" isn't a living thing.\n");
    return 1;
  }
 
  if (kidnap) {
    write("You can only kidnap one living thing.\n");
    return 1;
  }
 
  if (str == TPR) {
    write("You can't kidnap yourself.\n");
    return 1;
  }
  if (find_player(str) && find_living(str)->query_level()>TPL) {
     write("You are to inexperienced to kidnap this person.\n");
     return 1;
  }
 
  if (!spell_works(kidnap_chance)) return 1;
 
  reduce_sp(reduce);
 
  kidnap = present(str,env(TP));
  ob = clone_object("/players/silas/guild/kidnap");
  move_object(ob,kidnap);
  ob -> query_master(TP);
 
  call_out("stop_kidnap",TIME_TO_KIDNAP);
  write("You kidnapped "+ capitalize(str) +"\n");
  tell_object(kidnap, "You are kidnapped by "
              +TPN+".\n");
  return 1;
}
 
bind(str) {
 
  reduce = bind_cost;
 
  if (!check_alignment()) return 1;
 
  if (!check_sp(bind_cost)) return 1;
 
  if (!str) {
    write("What do you want to bind?\n");
    return 1;
  }
  if (!spell_works(bind_chance)) return 1;
 
  reduce_sp(bind_cost*2);
  TP->reduce_hit_point(-bind_cost);
  write("You feel a lot stronger after binding your wounds.\n");
  return 1;
}
 
meditate() {
 
   if(!check_alignment()) return 1;
 
   if(TP->query_hit_point()<=meditate_cost+10) {
      write("Don't forget your hit points druid.\n");
      return 1;
   }
 
   if (!spell_works(meditate_chance)) return 1;
 
   reduce_sp(-meditate_cost);
   TP->reduce_hit_point(meditate_cost*2);
   write("You are more concentrated now.\n");
   return 1;
}
 
mist() {
 
  object ob;
  string color;
 
  reduce = mist_cost;
 
  if (!check_alignment()) return 1;
 
  if(!check_sp(reduce)) return 1;
 
  if (!spell_works(mist_chance)) return 1;
 
  reduce_sp(reduce);
  color = query_color();
 
  ob = clone_object("/players/silas/guild/mist");
  move_object(ob,env(TP));
  ob->set_color(color);
 
  tell_room(env(ob),TPN +" makes some magical gestures and leaves into a "+color+" mist.\n");
  write("Using the power of the druids you leave into a "+ color+" mist of safety.\n");
  move_object(TP,ob);
  call_out("leave_mist",30,ob);
  return 1;
}
 
leave_mist(ob) {
  tell_room(env(ob),TPN +" jumps out of the "+query_color()+" mist.\n");
  tell_room(env(ob),"WUUUUMMMM!! The "+query_color()+" mist of safety disappears.\n");
  write("The "+query_color()+ " mist of safety disappears.\n");
  move_object(TP,env(ob));
  destruct(ob);
  return 1;
}
 
 
catch_tell(str) {
  follow_adopt(str);
  follow_kidnap(str);
}
 
follow_adopt(str) {
   object old_env;
   string who,where;
 
   if (!adopted) return;
 
   if (!living(adopted))
   {
     adopted = 0;
     remove_call_out("stop_adoption");
     return;
   }
 
   if (present("adopt_slave",adopted)) {
     if (random(100)>98) {
       write("You lose your concentration and you can't remember your slave.\n");
       tell_object(adopted,"Your master loses you as he loses his concentration.\n");
 
       destruct(present("adopt_slave",adopted));
       return;
     }
 
     if (env(TP) != env(adopted)) {
       tell_object(adopted,"You follow your leader.\n");
       old_env = env(adopted);
       move_object(adopted,env(TP));
       tell_object(adopted,"You arrive at " + env(TP)->short()+".\n");
       tell_room(old_env,capitalize(adopted->query_real_name()) + " follows "+  query_poss(adopted) + " leader " + TPN +"\n");
 
     }
   }
   else
     adopted =0;
}
 
follow_kidnap(str) {
 
  object old_env;
  object ob;
 
  if (!kidnap) return;
 
  if (!living(kidnap)) {
     kidnap =0;
     remove_call_out("stop_kidnap");
     return 1;
  }
 
  if (!present("kidnap_slave",kidnap)) {
      kidnap =0;
      remove_call_out("stop_kidnap");
      return 1;
  }
 
  if (env(TP) == env(kidnap)) return;
  tell_object(kidnap,"Your kidnapper drags you to "+env(TP)->short()+"\n");
  old_env = env(kidnap);
  move_object(kidnap,env(TP));
  tell_room(old_env,kidnap->query_name()+" follows "+query_poss(kidnap)+" kidnapper.\n");
 
  ob = first_inventory(env(TP));
  while (ob)
  {
     if (ob->query_name() != kidnap->query_name())
        tell_object(ob,kidnap->query_name() +" arrives.\n");
     ob = next_inventory(ob);
  }
}
 
stop_adoption() {
  if (!adopted) return 1;
 
  if (!present("adopt_slave",find_player(adopted))) return 1;
  write("You free your slave.\n");
  call_other(present("adopt_slave",find_player(adopted)),"stop_adoption" ,"adoption");
 
  adopted =0;
  return 1;
}
 
stop_kidnap() {
   if (!kidnap) return;
   if (!present("kidnap_slave",kidnap)) return;
   destruct(present("kidnap_slave",kidnap));
   write("Your kidnapped victim finally got free.\n");
   return kidnap=0;
}
 
erase_adopted() { adopted =0; }
 
teleport(str) {
 
   object list;
   string item, to, receiver;
 
   reduce = teleport_cost;
 
   if(!check_alignment()) return 1;
 
   if (!check_sp(reduce)) return 1;
 
   if (TPL<15 || TP->query_wis()<15 || TP->query_chr()<15) {
       write("This magic spell can only be used by advanced druids.\n");
       return 1;
   }
 
   if (!str) {
      write("Usage: teleport <item> to <player>\n");
      return 1;
   }
   sscanf(str,"%s %s %s",item,to,receiver);
 
   if (!item || !to || !receiver || (to != "to")) {
      write("Usage: teleport <item> to <player>\n");
      return 1;
   }
   if (!present(item,TP)) {
      write(capitalize(item)+" ???? You haven`t got this.\n");
      return 1;
   }
 
   if (present(item,TP)->query_food()) {
      write("The food would become bad by teleporting.\n");
      return 1;
   }
 
   if (!find_player(receiver)) {
      write("You can't localize "+capitalize(receiver)+".\n");
      return 1;
   }
 
   if (!spell_works(teleport_chance)) return 1;
 
   reduce_sp(reduce);
 
   if (TP->query_intoxination()>10) {
     write("As a result of your intoxication you can't localize "+ capitalize(receiver) +" exactly.\n");
     list = users();
     receiver = list[random(sizeof(list))]->query_real_name();
   }
   else
   {
     write("You have localized "+ capitalize(receiver) +" using all your magic power.\n");
   }
   if (receiver != TPR) {
      write("You feel that your "+ item +" starts moving.\n");
      write("Suddenly Thor's hand grabs your "+item+" and moves it to "+capitalize(receiver)+".\n");
      tell_object(find_player(receiver),"You feel a strong power concentrated on you.\n");
      tell_object(find_player(receiver),"Suddenly the hand of Thor comes down from the air and gives you a "+ item +".\n");
      transfer(present(item,TP),find_player(receiver));
   }
   else
   {
      write("You concentrate on yourself which does not make sense.\n");
      write("Nothing happened.\n");
   }
   return 1;
 
}
 
reduce_sp(amount) {
   TP->restore_spell_points(-amount);
   return 1;
}
 
check_alignment() {
   if (TP->query_alignment() <= ALIGN) {
    write("You are not allowed to used the druid commands any longer.\n");
    write("Regret your sins and do good deeds.\n");
    return 0;
  }
  return 1;
}
 
check_sp(amount) {
  if (TP->query_spell_points()<amount) {
    write("You are too low on power.\n");
    return 0;
  }
  return 1;
}
 
query_poss(ob) {
 
  switch(ob->query_gender()) {
     case 0: return "its";
             break;
     case 1: return "his";
             break;
     case 2: return "her";
             break;
  }
}
 
query_color() {
     int align;
 
     align = TP->query_alignment() ;
 
     if (align<50) return "blue";
     if (align<100) return "violet";
     if (align<200) return "red";
     if (align<300) return "pink";
     if (align<500) return "yellow";
     return "white";
}
 
list_levels() {
    return GM->list_levels(guild);
  }
 
 
list_spells() {
    set_var();
    write("Spell          \tCost\tChance\n");
    write("=============================================\n");
    write("quo vadis      \t"+quo_cost+"\t"+quo_chance+"% \n");
    write("verify         \t"+verify_cost+"\t"+verify_chance+"%\n");
    write("conjure thor   \t"+conjure_thor_cost+"\t"+conjure_thor_chance+"%\n");
    write("conjure odin   \t"+conjure_odin_cost+"\t"+conjure_odin_chance+"%\n");
    write("conjure frija  \t"+conjure_frija_cost+"\t"+conjure_frija_chance+"%\n");
    write("conjure baldur \t"+conjure_baldur_cost+"\t"+conjure_baldur_chance+"%\n");
    write("adopt          \t"+adopt_cost+"\t"+adopt_chance+"%\n");
    write("kidnap         \t"+kidnap_cost+"\t"+kidnap_chance+"%\n");
    write("bind wounds    \t"+bind_cost+"\t"+bind_chance+"%\n");
    write("meditate       \t"+meditate_cost+"\t"+meditate_chance+"%\n");
    write("mist           \t"+mist_cost+"\t"+mist_chance+"%\n");
    write("teleport       \t"+teleport_cost+"\t"+teleport_chance+"%\n");
    write("=============================================\n");
}
 
set_var()
{
/* Spell-Costs and Chances */
 
   quo_cost=10;
   quo_chance=100;
 
   verify_cost = 40 - TPW;
   verify_chance = check_percent(10 * TPL);
 
   conjure_thor_cost = 200 - TPL;
   conjure_thor_chance = check_percent(TPL * 4);
 
   conjure_odin_cost = 150 - TPL;
   conjure_odin_chance = check_percent(TPL * 6);
 
   conjure_frija_cost=  25 + TPL + TPC + TPW;
   conjure_frija_chance = check_percent(TPL * 8);
 
   conjure_baldur_cost = 15 + TPL + TPC + TPW;
   conjure_baldur_chance = check_percent(TPL * 15);
 
   adopt_cost = 40 - TPC;
   adopt_chance = check_percent((TPL+TPC)*5);
 
   kidnap_cost = 80 - TPW - TPS;
   kidnap_chance = check_percent((TPW+TPS)*3);
 
   bind_cost = TPL * 2;
   bind_chance = check_percent(100-TPL+TPC);
 
   meditate_cost = TPL * 2;
   meditate_chance = check_percent(100-TPL+TPW);
 
   mist_cost = TPL * 4;
   mist_chance = check_percent(100 - TPL);
 
   teleport_cost = 100 - TPW - TPC;
   teleport_chance = check_percent(TPL * 5);
}
 
check_percent(int chance)
{
   if (chance > 100)
      return 100;
   return chance;
}
 
spell_works(int chance)
{
   if  (random(100)<=chance)
      return 1;
   write("Suddenly you lost your concentration.\n");
   reduce_sp(10);
   return 0;
}
