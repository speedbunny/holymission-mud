inherit "room/room";

void reset(int i)
{
object ob;


 ob=clone_object("obj/money");
 ob->set_money(7654321);
 transfer(ob,this_object());

 ::reset(i);
 if (i) return;
 set_light(0);
 short_desc="A cell";
 long_desc="You are in the cell. The vault is low and made of stone. "+
      "You can see some old barrels by the wall, but they are not "+
      "interesting.\n";
 items=({"vault","Is made of stone"});
 dest_dir=({"players/goldsun/nottingham/room/my_cott","up"});
 smell="Dump air with strong wooden smell.";
}   

void init()
{
 ::init();
 add_action("my_get","get");
}


int my_get(string str)
{
 if (str=="all")
 {
   write("You cannot do that here.\n");
   return 1;
 }
 if (str=="coins" || str=="coin") 
 {
  transfer(present("coins",this_object()),this_player());
  if (present("coins",this_object()))
  {
      write("Duck arrives.\nDuck takes some money.\nDuck leaves.\n");
      destruct(present("coins",this_object()));
  }
  return 1;
 }
}



