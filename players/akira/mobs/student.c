inherit "obj/monster";
reset(arg){
::reset(arg);

set_name("student");
set_long("This is one of the many students that are learning the mental\n"+
         "arts at the tower. He is wearing a simple gray robe that shows\n"+
         "his rank as a student.\n");
set_level(5+random(10));
set_number_of_arms(2);
set_ac(10);
set_wc(5);
}
