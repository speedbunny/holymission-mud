inherit "room/room";

void reset(int i)
{
object ob;


 ob=clone_object("obj/money");
 ob->set_amount(7654321);
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
 add_action("upd_u","",1);
}

int upd_u()
{
write("heh");
return 1;

}


