inherit "/obj/monster";
void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("mystical tree");
set_race("tree");
set_short("A huge magic tree");
set_long("A huge magic tree. It is strange tree which must kill\n"
       + "the aliens everytime.\n");
set_wc(34);
set_ac(4);
set_hp(3000);
set_aggressive(0);
set_level(19);
set_al(-100);
set_size(4);
move_object(clone_object("/players/goldsun/sherwood/obj/bark"),
             this_object());
command("wear bark");       
}

init(){
 ::init();
 add_action("steal","steal");
 }

steal(){
 write("Huh? Are you sure that it is possible?");
 return 1;
 }

