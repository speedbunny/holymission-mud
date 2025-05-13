#define SAY(x) tell_room(environment(),x)
#define TO this_object()
#define TP this_player()

inherit "obj/monster";

void sayt(object pl){
 object co;
  SAY("Upper guard says: Hi. If you want to save Nottingham and fight against\n"
      +"Orcs, I can give you several soldiers. Just say 'follow me' and you'll\n"
   +"see how many guards want to fight.\n");
 return;
}

void reset(int a) 
{
    ::reset(a);
    if (a) return 0;
    set_name("upper guard");
    set_alias("guard");
    set_short("Upper guard");
    set_long("Upper guard the Sherif's right hand.\n");
    set_gender(1);
    set_wc(39);
    set_ac(30);
    set_race("giant");
    set_size(3);
    set_level(48);
    add_money(22000);
    move_object(clone_object("/players/goldsun/nottingham/obj/chainmail"),
			this_object());
    command("wear chainmail");
}

init(){
 ::init();
if (TP->query_npc()==0) call_out("sayt",1,TP);
}

