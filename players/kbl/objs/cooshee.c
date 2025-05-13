/* Elvin dog */

inherit "obj/monster";
#include "/players/kbl/header/T.h"
#define SLEAF "/players/kbl/objs/leaf"
#define STAND 10

int leafs,sleaf;
int count;
string walk;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("cooshee");
    set_level(random(3)+5);
    set_alias("cooshee");
    set_alt_name("dog");
    set_race("dog");
    set_al(10);
    set_gender(random(2)+1);
    set_short("A Cooshee dog");
    set_long("Greenish coat with brown spots. Has paws with huge claws\n"+
             "and its tail is curled and held over its back. This Cooshee\n"+
             "must weight "+(this_object()->query_level()*30)+" pounds!\n");
    set_spell_mess1("Cooshee bites your knee.");
    set_spell_mess2("Cooshee gets real overbearing!");
    set_heart_beat(1);
    set_chance(15);
    add_money(random(400)+201);
    leafs = random(5)+1;
    set_spell_dam(15);
    set_move_at_reset();
    set_aggressive(0);
    load_chat(8,({
       "Cooshee wags its curved tail.\n", "Cooshee walks around in circles.\n",
       "Elvin dog looks at you.\n", "Cooshee sniffs the air.\n",
       "Elvin dog scratchs its side.\n","Cooshee lays down in the corner.\n",
                 }));
     walk = ({"north","northeast","east","southwest","southeast","south",
              "out","t6","t5","t4","t3","t2","t1","out",
              "west","northwest",
             });
    set_wc(8);
    set_ac(5);
  }
}

init()
{
  ::init();
  add_action("pet","pet");
}

pet(str)
{
  object tp;
  object tmp;

  tp = this_player();
  if(!str)
    return;
  if(str == "cooshee" || str == "elvin dog")
  {
    if((tp->query_race() == "elf" || tp->query_name() == "half elf") &&
      (tmp != tp && leafs > 0))
    {
      tmp = tp;
      transfer(clone_object("players/kbl/objs/unfrog"),tp);
      leafs++;
    }
    switch(random(8))
    {
      case 0:
             tell_room(ETO,"Cooshee barks and sits up happily.\n");
             break;
      case 1:
             write("Cooshee give your face a licking!\n");
             break;
      case 4:
             tell_room(ETO,"Cooshee sits up.\n");
             break;
      case 6:
            if(!present("star leaf",TP))
            {
             write("Cooshee gives you a star shaped leaf from its mouth.\n");
             transfer(clone_object(SLEAF),TP);
             sleaf++;
             break;
            }
            write("Cooshee licks your hand.\n");
            break;
      default:
            tell_room(ETO,"Cooshee wags its tail happily.\n");
    }
    return 1;
  }
}

heart_beat()
{
  ::heart_beat();
  count++;
  if(count>STAND)
  {
    motivate();
    count = 0;
  }
}

motivate()
{
  int dir,cnt,mov;

  cnt = 0;
  while(!mov && cnt < 16)
  {
   cnt++;
   dir = random(16);
   mov = command(walk[dir],this_object());
  }
}
