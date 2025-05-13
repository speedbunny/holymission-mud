inherit "/obj/monster";
void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("owl");
set_race("animal");
set_short("A night owl");
set_long("A night owl.\n"
         +"She seems very clever, but it is not true.\n");
set_wc(22);
set_ac(1);
set_gender(2);
set_al(100);
set_no_steal();   /* this is for shit , thief_soul doean't query this func */
set_aggressive(0);
set_level(6);
set_size(1);
move_object(clone_object("/players/goldsun/sherwood/quest/feathers"),
             this_object());
}

init(){
 ::init();
 add_action("hold","hold");
 }


hold(){
   write("Its very hard to hold this owl. \n");
  return 1;
}

int query_property(string str){
 return str=="no_steal";
}
