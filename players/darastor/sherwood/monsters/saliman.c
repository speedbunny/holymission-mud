inherit "/obj/monster";
reset(int arg)
 {
object m;
 ::reset(arg);

 if (arg) return;
set_name("saliman");
set_race("troll");
set_short("A dangerous Saliman");
set_long("A dangerous Saliman.\n");
set_wc(39);
set_ac(14);
set_gender(1);
set_aggressive(-1);
set_level(44);
set_size(4);
set_spell_mess1("Saliman makes the Ha-moke-quo trick.");
set_spell_mess2("Salimans makes the Ha-moke-quo trick.");
set_spell_dam(80+random(50));
set_prevent_poison(1);
set_chance(26);
add_money(2000);
m=clone_object("/obj/money");
m->set_money(10000);
transfer(m,"/players/goldsun/sherwood/room/dcave3");
move_object(clone_object("/players/goldsun/sherwood/obj/club"),
             this_object());
command("wield club");
}

init(){
 ::init();
 add_action("do_block","get");
 add_action("do_block","take");
 }

run_away(){
 write("This is a highwayman.\nThey fear nothing.\n");
 return 1;
}

int do_block(string str){
 if (str=="gem" || str=="silver" || str=="gold" || str=="coins" || 
	str=="diamond" || str=="all"){
  write("Saliman says: Don't touch it !\n");
 return 1;
 }
 return 0;
}

