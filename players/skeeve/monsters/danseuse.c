
/* danseuse */
// Last Edit Whisky, moves the call_out into the heart_beat

inherit "/obj/monster";

#include "/players/skeeve/area.h"
#include "/players/skeeve/code.h"

int count, delay;

void add_money_to_self(int m);
 
void reset(int arg) 
{
  string s; 
  int i;
     
  ::reset(arg);
  if (!arg) 
  {
    set_name("danseuse");
    set_short("A danseuse");
    set_long("The danseuse is a fantastic dancer, but noone like her.\n");
    set_race("half-elf");
    set_female();
    set_level(16);
    set_dex(21);
    set_al(200);
    set_hp(500);
    set_sp(0);
    set_wc(3);
    set_ac(0);
    set_aggressive(0);
    set_no_steal();
    set_size(3);
    set_dead_ob(this_object());
    if (sscanf(file_name(this_object()),"%s#%d",s,i)==2) 
    {
        set_heart_beat(1);
        count = 0;
        delay = 15;
    }
  }
  
  WEAPON ("danseuse_dagger",this_object());
  ARMOUR ("tricot","dance_tricot",this_object());
  ARMOUR ("shoes","dance_shoes",this_object());
  ARMOUR ("tights","pink_tights",this_object());
  ARMOUR ("shawl","pink_shawl",this_object());
  ARMOUR ("ring","perl_ring",this_object());  
  if (!present("bill")) 
      move_object(clone_object(OBJECTS+"danseuse_bill"),this_object());
}

void init()  
{
  int m;
  string s;
  object p, bill, skeeve;
  
   ::init();

   if (!delay && test_if_any_here())
   {
       delay = 15;
       set_heart_beat(1);
   }
   p = this_player();
   if(p->query_player() 
   && !p->query_immortal()
   && !p->query_ghost() 
   && !present("danseuse_bill",p)
   && !present("danseuse_ticket",p)) {
     if((p->query_level() > 5)  
     && (p->query_money() > 500) ) {
       write ("The Danseuse sweeps you across the dance floor.\n"
           +  "She gives you a bill.\n");
       say ("The Danseuse sweeps " + p->query_name()
           +" across the dance floor.\n",p);
       bill=clone_object(OBJECTS+"danseuse_bill");
       m = p->query_money()/5; 
       if (m>4000) m=4000;
       bill->set_bill(m,p->query_real_name());
       transfer(bill,p);
       p->add_money(-m);
       add_money_to_self(m);
     } else if ((query_money() > 99) 
     && (p->query_level() <= 5)  
     && (p->query_money() < 1000) ) {
       m = (p->query_level() + p->query_str()) * 500 - p->query_money();
       if ( query_money()/5 < m) m = query_money()/3;
       if (m>0) {
         p->add_money(m);
         add_money(-m);
  
         write ("The Danseuse sweeps you across the dance floor.\n"
               +"She is excited about your dancing skills and gives you "
               + m + " gold coins.\n");
         say ("The Danseuse sweeps " + p->query_name()
             +" across the dance floor.\n",p);
         bill=clone_object(OBJECTS+"danseuse_ticket");
         bill->set_coins(m);
         transfer(bill,p);
       }
      }
     }
}

void add_money_to_self(int m) {
  int l;
  object mo;
  l=query_money()+m-(level+query_str())*500;
  if (l>0) {
    say ("Some gold dissapears to somewhere!\n");
    mo = clone_object("obj/money");
    mo -> set_value(l+ 6000);
    move_object(mo,COTTAGE+"guardroom");
    m = 6000-query_money();
  }
  add_money(m);
}

query_stay_garden() { return 0; }

void heart_beat()  
{
  string s;
  int i;

  count ++;
 
  if (count == 15)
  {
      random_move();
      count = 0;
      delay--;
  }
  if (!delay)
       set_heart_beat(0);
}

monster_died(o) {
  object bill;
  object env,ob,next;
  
  env=environment(this_object());
  ob = first_inventory(env);
  while(ob) {
    next = next_inventory(ob);
    if (ob->id("danseuse_bill")) destruct (ob);
    else while (bill=present("danseuse_bill",ob))
      destruct(bill);
    ob = next;
  }
  tell_room (env,"You hear a voice from the sky: I will come back!\n");
  CASTLE->monster_died("danseuse");
  return 0;
}
