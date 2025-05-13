inherit "/obj/monster";

#include "/players/skeeve/area.h"

string *riddle_name=({"broom","skull","horseshoe","map","bellows"});

/*
string *riddle_desc=({
 "This broom has swept its fair share of floors.\n"
+"It looks like a convertible for a witch.\n",
 "It's a skull. Fortunately it doesn't belong to anyone you know.\n",
 "This horseshoe seems to have taken quite a beating.\n",
 "This fine map of the land of druid Lakmir is quite detailed,\n"
+"although incomplete.\n",
 "This wooden bellows has stoked many a floundering fire.\n"});
query_riddle_desc(i) { return riddle_desc[i]; }
*/

string *riddle_text=({
 "Long neck and no hands, made of wood from forest's nest;\n"
+"a hundred legs and I can't stand, against a wall I will rest.\n",
 "Eyeless tho' that I may be, through me once a man did see;\n"
+"my form once thoughts did hold, now I'm empty, white and cold.\n",
 "First I was burnt, then I was beaten; then I was drowned,\n"
+"then I was pierced with nails.\n",
 "It has towns, but no houses; It has forests, but no trees;\n"
+"It has rivers, but no fish.\n",
 "I at fires attend, am a kitchen friend; when my nose I blow,\n"
+"how the embers glow! When the wind compels, how my body swells.\n"
});

query_riddle_name(i) { return riddle_name[i]; }
query_riddle_text(i) { return riddle_text[i]; }

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("sphinx");
    set_short("The sphinx");
    set_long("This stone figure bears the body of a lion, the head of a man, and the\n"
            +"temperament of a wolverine..\n");
    set_race("stone figure");
    set_size(4);
    set_al(400);
    set_level(90);
    set_chr(30);
    set_int(76);
    set_hp(17000);
    set_sp(17000);
    set_wc(50);
    set_ac(30);
    set_aggressive(0);
    set_no_steal();
    set_whimpy(-1);
    set_male();
    set_chance(90);
    set_spell_dam(50);
    set_spell_mess1("The sphinx casts a bolt at you.");
    set_spell_mess2("The sphinx shocks you with his roaring.");
  }
}

/*
init() {
  ::init();
  riddle(this_player());
}
*/
/*--------------------------------------------------------------------------*/

enter_inventory(ob) {
  object ticket;
  if (!ticket=present("sphinx_ticket",this_player()))
    riddle(this_player());

  if (!ob->query_sphinx()) {
    write("The sphinx says: Ugh, thanks. But I don't need it.\n"); 
    say ("The sphinx give the "+ob->query_name()+" back to "+this_player()->query_name()+"\n");
    transfer(ob,this_player()); 
    return;
  } 
  if (creator(ob)!=WIZNAME) {
    log_file("QUESTS.CHEAT",this_player()->query_real_name()+" "+
              file_name(ob)+" "+ctime(time())+"\n"); 
    destruct(ob); 
    return; 
  }
  if (ob->query_name()!=ticket->query_riddle()) {
    transfer(ob,this_player()); 
    write("The sphinx says: Ugh, thanks. But it's the wrong answer.\n"); 
    say ("The sphinx give the "+ob->query_name()+" back to "+this_player()->query_name()+"\n");
    return;
  }    
  ticket->set_solved(1);
  write("The sphinx says: Ugh, thanks. You may enter the maze.\n"); 
  say ("The sphinx says: "+this_player()->query_name()
    + " may enter the maze.\n");
  destruct(ob); 
}

riddle (tp) {
  int i;
  object ticket;
  if (tp->query_quests("holy_druid"))
    return 1;
  if (ticket=present("sphinx_ticket",tp))
    return ticket->query_solved();
  
  i = random(sizeof(riddle_name));
  move_object(ticket=clone_object(OBJECTS+"sphinx_ticket"),tp);
  ticket->set_riddle(riddle_name[i]);
  ticket->set_text(riddle_text[i]);
  
  write("The sphinx says to you:\n"+
    riddle_text[i]+
    "Bring me the answer to my riddle and I let you pass.\n");
  say("The sphinx says to "+tp->query_name()+
    riddle_text[i]+
    "Bring me the answer to my riddle and I let you pass.\n");

  return 0;
}
