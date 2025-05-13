#define SAY(x) tell_room(environment(),x)
#define TO this_object()
#define TP this_player()

inherit "obj/monster";

void sayt(object pl){
 object co;
  SAY("Vilo says: Hi. Save guard from white tower please."+
       " He wants to die in\n free land in his valley.\n");
 return;
}

void reset(int a) 
{
    ::reset(a);
    if (a) return 0;
    set_name("vilo");
    set_short("Beggar Vilo");
    set_long("A poor beggar Vilo. He is prisoner of Rockland.\n");
    set_gender(1);
    set_wc(9);
    set_ac(10);
    set_race("giant");
    set_size(3);
    set_level(8);
}

init(){
 ::init();
call_out("sayt",1,TP);
}

run_away(){
 write("He is prison here.\nHe cannot escape.\n");
 return 1;
}
