
inherit "obj/monster"; /* we take the standardobj */
#include "/players/kbl/header/T.h"
#define QCHEST "/players/kbl/objs/chest"

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("vultur gryphus");
    set_level(30);
    set_al(-100);
    set_alias("vultur");
    set_race("vultur");
    set_short("A giant vultur");
    set_long("A giant vultur with black wings, red tail feathers and a bald\n"+
             "head. Its beak is the size of a large dog. Its eyes are lime\n"+
             "green giving you a sick feeling.\n");
    set_wc(10);
    set_ac(15);
    set_aggressive(0);
    add_money(random(1000)+2000);
    set_move_at_reset(); /*at every reset it moves one field */
    set_whimpy(0);
    load_chat(8,({
     "Vultur flaps its wings creating a small dust storm\n",
      "Vultur makes swallowing sounds\n",
      "Vultur looks very hungry\n",
      "Vultur belches\n",
      "Vultur sniffs in your general direction\n"}));
    set_spell_mess1("The vultur claws you good!");
    set_spell_mess2("The vultur rips you with its beak\n");
    set_chance(10); /*the chance of the monst to cast a spell*/
    set_spell_dam(40); /*the random damage of the spell */
    transfer(clone_object("players/kbl/objs/claw"),this_object());
    init_command("wield claw");
     transfer(clone_object("/players/kbl/objs/lizard_skin"),this_object());
}
}

init()
{
  ::init();
  add_action("give","give");
}

give(str)
{
  string in1,in2;
  object ob1,ob2;
  if(sscanf(str,"%s and %s to vultur",in1,in2) == 2)
  {
    ob1 = present(in1,TP);
    ob2 = present(in2,TP);
    if(ob1 && ob2)
    {
       destruct(ob1);
       transfer(ob2,this_object());
       transfer(ob1,this_object());
       tell_object(TP,"You gave the vultur a "+in1+" and a "+in2+"...\n"+
                      "The Vultur starts to flap its winds furiously!!!\n");
       tell_room(ETO,"The vultur gives off mighty gusts of wind as it takes off.\n");
       transfer(TO,"/players/kbl/clifftop");
       tell_room(TO,"Vultur flies down towards the pyramid. It lands down\n"+
                    "by the pyramid and disappears from sight for a while\n"+
                    "and then takes off towards the west and lands at the\n"+
                    "edge of the cliff.\n");
       transfer(clone_object(QCHEST),TO);
       TP->add_exp(1500);
       tell_object(TP,"You feel a little more experienced.\n");
       return 1;
    }
  }
}
