inherit "obj/monster";
object ob; 
 
reset(arg) 
{
  ::reset(arg);
  if (arg) return;
  set_name("max");
  set_race("human");
  set_alias("maxwell");
  set_level(10);
  set_short("Maxwell Smart");
  set_long("The (in)famous master spy.\n");
  set_aggressive(0);
  set_ac(10);
  set_wc(10);
  ob = clone_object("obj/money");
  ob->set_money(random(400) + 100);
  move_object(ob,this_object());  
  load_chat(25,
    ({
       "Maxwell talks into his shoe\n",
       "Maxwell says: Have you seen 99?\n",
       "Maxwell says: I think I have found the leader of K.A.O.S.\n",
       "Maxwell changes a pen into a pair of scissors.\n",
    }));
}
